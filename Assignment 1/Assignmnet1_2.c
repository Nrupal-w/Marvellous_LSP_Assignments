#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main()
{
    char name[256];
    char mode[4]; 
    int fd;  
    int per;


    printf("Enter Your File Name: ");
    scanf("%255s", name);

    printf("Enter Mode (R / W / A / RW): ");
    scanf("%3s", mode);


    

    if (strcmp(mode, "R") == 0)
    {
        per = O_RDONLY;
    }
    else if (strcmp(mode, "W") == 0)
    {
        per = O_WRONLY ;
    }
    else if (strcmp(mode, "A") == 0)
    {
        per = O_APPEND;
    }
    else if (strcmp(mode, "RW") == 0)
    {
        per = O_RDWR ;
    }
    else
    {
        printf("Invalid mode\n");
        return -1;
    }

    fd=open(name,per);

    if (fd == -1)
    {
        perror("Error is");
        return -1;
    }
    else
    {
        printf("File opened successfully\n");
    }

    close(fd);
    return 0;
}



    

