#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    char dirname[256];
    char filepath[512];
    char largestFile[256] = "";

    long maxSize = 0;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dp = opendir(dirname);
    if (dp == NULL)
    {
        perror("Unable to open directory");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

        if (lstat(filepath, &sobj) == -1)
            continue;

        if (S_ISREG(sobj.st_mode))
        {
            if (sobj.st_size > maxSize)
            {
                maxSize = sobj.st_size;
                strcpy(largestFile, entry->d_name);
            }
        }
    }

    closedir(dp);

    if (maxSize > 0)
    {
        printf("\nLargest File Name : %s", largestFile);
        printf("\nLargest File Size : %ld bytes\n", maxSize);
    }
    else
    {
        printf("\nNo regular files found.\n");
    }

    return 0;
}
