#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void print_permissions(mode_t mode)
{
    char perm[11];

    perm[0] = S_ISDIR(mode) ? 'd' :
              S_ISLNK(mode) ? 'l' : '-';
    perm[1] = (mode & S_IRUSR) ? 'r' : '-';
    perm[2] = (mode & S_IWUSR) ? 'w' : '-';
    perm[3] = (mode & S_IXUSR) ? 'x' : '-';
    perm[4] = (mode & S_IRGRP) ? 'r' : '-';
    perm[5] = (mode & S_IWGRP) ? 'w' : '-';
    perm[6] = (mode & S_IXGRP) ? 'x' : '-';
    perm[7] = (mode & S_IROTH) ? 'r' : '-';
    perm[8] = (mode & S_IWOTH) ? 'w' : '-';
    perm[9] = (mode & S_IXOTH) ? 'x' : '-';
    perm[10] = '\0';
    printf("%s ", perm);
}

const char *file_type(mode_t mode)
{
    if (S_ISREG(mode)) return "FILE";
    if (S_ISDIR(mode)) return "DIR";
    if (S_ISLNK(mode)) return "LINK";
    return "OTHER";
}

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat sb;
    char fullpath[1024];
    char timebuf[64];

    if (argc != 2)
    {
        printf("ERROR: Invalid arguments\nSYNTAX: %s <directory_path>\n", argv[0]);
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    printf("NAME\tTYPE\tSIZE\tPERMISSIONS\tLAST MODIFIED\n");
    printf("-------------------------------------------------------------\n");

    while ((entry = readdir(dp)) != NULL)
    {
        /* Skip . and .. */
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            snprintf(fullpath, sizeof(fullpath),"%s/%s", argv[1], entry->d_name);

        if (lstat(fullpath, &sb) == -1)
        {
            perror("lstat");
            continue;
        }
        printf("%s\t%s\t%ld\t",entry->d_name,file_type(sb.st_mode),sb.st_size);
        print_permissions(sb.st_mode);
        printf("\t%s", ctime(&sb.st_mtime));
        }
       
        
    }

    closedir(dp);
    return 0;
}
