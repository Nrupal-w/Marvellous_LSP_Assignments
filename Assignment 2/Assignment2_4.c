#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include<fcntl.h>
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

    while ((entry = readdir(dp)) != NULL)
    {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%-15s ", entry->d_name);

        switch (entry->d_type)
        {
        case DT_REG:
            printf("Regular File");
            break;
        case DT_DIR:
            printf("Directory");
            break;
        case DT_LNK:
            printf("Symbolic Link");
            break;
        case DT_FIFO:
            printf("FIFO");
            break;
        case DT_SOCK:
            printf("Socket");
            break;
        case DT_CHR:
            printf("Character Device");
            break;
        case DT_BLK:
            printf("Block Device");
            break;
        default:
            printf("Unknown");
        }
        printf("\n");
    }

    closedir(dp);
    return 0;
}
