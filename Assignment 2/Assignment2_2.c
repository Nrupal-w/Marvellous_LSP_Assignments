#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main()
{
    char name[256];
    int fd;
    int iret =0;
    char buffer[100];
    printf("Enter Your File Name: ");
    scanf("%255s", name);
    printf("Enter Your String to be written in File: ");
    scanf("%99s", buffer);

    fd = open(name, O_APPEND|O_WRONLY,0777);

    if (fd == -1)
    {
        perror("Error is");
        return -1;
    }
    else
    {
        printf("File opened successfully\n");
    }

    iret=write(fd,buffer,strlen(buffer));

    if (iret==-1)
    {
        perror("Error of File");
    }
    else
    {
        printf("Number of bites written :%d",iret);

    }

    close(fd);
    return 0;
}