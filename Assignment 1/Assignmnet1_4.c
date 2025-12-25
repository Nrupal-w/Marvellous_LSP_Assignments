#include <sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
 #include <time.h>

int main()
{
    char name[256];
    int fd;
    struct stat sobj;
    int iret;
    
    printf("Enter Your File Name: ");
    scanf("%255s", name);

    fd = open(name, O_RDONLY);

    if (fd == -1)
    {
        perror("Error is");
        return -1;
    }
    else
    {
        printf("File opened successfully\n");
    }

    iret = stat(name, &sobj);

    printf("INODE Number : %lu \n",sobj.st_ino);
    
    printf("HardLink Count : %lu \n",sobj.st_nlink);
    
    printf("Total Size  : %lu \n",sobj.st_size);

    printf("Block Size  : %lu \n",sobj.st_blksize);

    printf("File Tye is :%d \n",sobj.st_mode);

    printf("Ownership :UID=%ju GID=%ju \n",sobj.st_uid,sobj.st_gid);

    printf("Last file access:         %s", ctime(sobj.st_atime));
    printf("Last file modification:   %s", ctime(sobj.st_mtime));



    close(fd);
    return 0;
}
