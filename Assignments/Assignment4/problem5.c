#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    off_t filesize, offset;
    char buffer[BUFSIZE];

    if (argc != 2)
    {
        printf("ERROR: Invalid arguments\n");
        printf("SYNTAX: %s <filename>\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    filesize = lseek(fd, 0, SEEK_END);
    offset = filesize;

    while (offset > 0)
    {
        ssize_t toRead = (offset >= BUFSIZE) ? BUFSIZE : offset;
        offset -= toRead;

        lseek(fd, offset, SEEK_SET);
        read(fd, buffer, toRead);

        /* Reverse buffer */
        for (int i = toRead - 1; i >= 0; i--)
        {
            write(1, &buffer[i], 1);
        }
    }

    close(fd);
    return 0;
}
