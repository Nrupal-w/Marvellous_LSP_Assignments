#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char name[256];
    int fd;
    int n;
    int iret;

    printf("Enter Your File Name: ");
    scanf("%255s", name);
    printf("Enter the number of chars u wnat to read from the file");
    scanf("%d",&n);
    char buffer[n+1];


    fd = open(name, O_RDONLY);
    memset(buffer,'\0',n);

    if (fd == -1)
    {
        perror("Error is");
        return -1;
    }
    else
    {
        printf("File opened successfully\n");
    }
    iret=read(fd,buffer,n);
    printf("%d bytes get sucessfully read\n",iret);
    printf("Data from file :%s\n",buffer);



    close(fd);
    return 0;
}
