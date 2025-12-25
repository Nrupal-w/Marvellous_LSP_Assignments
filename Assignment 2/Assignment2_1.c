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

    printf("Contents of the file is \n");
    while((iret=read(fd,buffer,100))>0)
    {
        printf("%s",buffer);

    }
    if (iret==-1)
    {
        perror("Error of File");
    }

    close(fd);
    return 0;
}