#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

long long totalSize = 0;
long long maxFileSize = 0;
int fileCount = 0;
int dirCount = 0;
char maxFileName[1024] = {0};

void directoryReport(const char *path)
{
    DIR *dp = NULL;
    struct dirent *directoryPointer = NULL;
    struct stat statObj;
    char fullPath[1024];

    dp = opendir(path);
    if (dp == NULL)
        return;

    dirCount++;   // count directory when entered

    while ((directoryPointer = readdir(dp)) != NULL)
    {
        /* Skip . and .. using != 0 condition */
        if (strcmp(directoryPointer->d_name, ".") != 0 &&
            strcmp(directoryPointer->d_name, "..") != 0)
        {
            snprintf(fullPath, sizeof(fullPath),
                     "%s/%s", path, directoryPointer->d_name);

            if (lstat(fullPath, &statObj) == -1)
                continue;

            /* Directory */
            if (S_ISDIR(statObj.st_mode))
            {
                directoryReport(fullPath);
            }
            /* Regular file */
            else if (S_ISREG(statObj.st_mode))
            {
                fileCount++;
                totalSize += statObj.st_size;

                if (statObj.st_size > maxFileSize)
                {
                    maxFileSize = statObj.st_size;
                    strncpy(maxFileName,
                            directoryPointer->d_name,
                            sizeof(maxFileName) - 1);
                }
            }
            /* Symlink or others: ignored */
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR: Invalid arguments\n");
        printf("SYNTAX: %s <directory_path>\n", argv[0]);
        return -1;
    }

    directoryReport(argv[1]);

    printf("Files       : %d\n", fileCount);
    printf("Dirs        : %d\n", dirCount);
    printf("Total Size  : %lld bytes\n", totalSize);
    printf("Largest     : %s (%lld bytes)\n",
           maxFileName, maxFileSize);

    return 0;
}
