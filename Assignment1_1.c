#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char name[256];
    int fd;

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

    close(fd);
    return 0;
}
