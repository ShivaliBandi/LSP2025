#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int fdSrc, fdDest;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFSIZE];
    struct stat statObj;

    if (argc != 3)
    {
        printf("ERROR: Invalid arguments\n");
        printf("SYNTAX: %s <source_file> <destination_file>\n", argv[0]);
        return -1;
    }

    /* Open source file */
    fdSrc = open(argv[1], O_RDONLY);
    if (fdSrc == -1)
    {
        perror("Source open failed");
        return -1;
    }

    /* Get source file permissions */
    if (stat(argv[1], &statObj) == -1)
    {
        perror("stat failed");
        close(fdSrc);
        return -1;
    }

    /* Open destination file */
    fdDest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, statObj.st_mode);
    if (fdDest == -1)
    {
        perror("Destination open failed");
        close(fdSrc);
        return -1;
    }

    /* Buffered copy */
    while ((bytesRead = read(fdSrc, buffer, BUFSIZE)) > 0)
    {
        bytesWritten = write(fdDest, buffer, bytesRead);
        if (bytesWritten != bytesRead)
        {
            perror("write failed");
            close(fdSrc);
            close(fdDest);
            return -1;
        }
    }

    if (bytesRead == -1)
    {
        perror("read failed");
    }

    /* Preserve permissions (bonus) */
    chmod(argv[2], statObj.st_mode);

    close(fdSrc);
    close(fdDest);

    printf("File copied successfully.\n");
    return 0;
}
