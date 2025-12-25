#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main()
{
    char dname[256];
    DIR *dp;
    struct dirent *entry;

    printf("Enter directory name: ");
    scanf("%255s", dname);

    dp = opendir(dname);
    if (dp == NULL)
    {
        perror("opendir failed");
        return -1;
    }

    printf("\nFiles in directory:\n");

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%s\n", entry->d_name);
    }

    closedir(dp);
    return 0;
}
