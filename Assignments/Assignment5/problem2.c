#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/* Print indentation */
void print_indent(int depth)
{
    for (int i = 0; i < depth; i++)
        printf("    ");
}

/* Recursive tree function */
void tree(const char *path, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat sb;
    char fullpath[1024];

    dp = opendir(path);
    if (dp == NULL)
    {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        /* Skip . and .. */
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath),
                 "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &sb) == -1)
        {
            perror("lstat");
            continue;
        }

        print_indent(depth);

        /* Directory */
        if (S_ISDIR(sb.st_mode))
        {
            printf("[D] %s/\n", entry->d_name);
            tree(fullpath, depth + 1);   
        }
        else if (S_ISLNK(sb.st_mode))
        {
            printf("[L] %s\n", entry->d_name);
            
        }
        else if (S_ISREG(sb.st_mode))
        {
            printf("[F] %s\n", entry->d_name);
        }
        else
        {
            printf("[O] %s\n", entry->d_name);
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

    printf("[D] %s/\n", argv[1]);
    tree(argv[1], 1);

    return 0;
}
