#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char dirname[256], filepath[512];
    DIR *dp;
    struct dirent *entry;
    struct stat sobj;
    int count = 0;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dp = opendir(dirname);
    if (dp == NULL)
    {
        perror("opendir failed");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        printf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

        stat(filepath, &sobj);

        if (S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            unlink(filepath);
            printf("Deleted: %s\n", entry->d_name);
            count++;
        }
    }

    closedir(dp);
    printf("Total empty files deleted: %d\n", count);
    return 0;
}
