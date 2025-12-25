#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>

int main()
{
    char dirname[256], filename[256];
    DIR *dp;
    struct dirent *entry;
    char path[512];

    printf("Enter directory name: ");
    scanf("%s", dirname);
    printf("Enter file name: ");
    scanf("%s", filename);

    dp = opendir(dirname);
    if (dp == NULL)
    {
        perror("opendir failed");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name, filename) == 0)
        {
            realpath(dirname, path);
            printf("File found at: %s/%s\n", path, filename);
            closedir(dp);
            return 0;
        }
    }

    printf("File not found\n");
    closedir(dp);
    return 0;
}
