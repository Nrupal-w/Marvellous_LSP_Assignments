#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    char srcdir[256], destdir[256], srcpath[512], destpath[512];
    DIR *dp;
    struct dirent *entry;
    struct stat sb;
    int count = 0;

    printf("Enter source directory: ");
    scanf("%s", srcdir);
    printf("Enter destination directory: ");
    scanf("%s", destdir);

    dp = opendir(srcdir);
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

        snprintf(srcpath, sizeof(srcpath), "%s/%s", srcdir, entry->d_name);
        snprintf(destpath, sizeof(destpath), "%s/%s", destdir, entry->d_name);

        stat(srcpath, &sb);

        if (S_ISREG(sb.st_mode))
        {
            rename(srcpath, destpath);
            count++;
        }
    }

    closedir(dp);
    printf("Total files moved: %d\n", count);
    return 0;
}
