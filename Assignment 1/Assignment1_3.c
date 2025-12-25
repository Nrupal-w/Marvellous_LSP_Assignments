#include <stdio.h>
#include <unistd.h>

int main() {
    char filename[256];

    printf("Enter file name: ");
    scanf("%255s", filename);

    if (access(filename, F_OK) == 0) {
        printf("File exists.\n");}
        
    else{
        printf("File does not exist.\n");
        return -1;
    }
    if (access(filename, R_OK) == 0)
            printf("Read permission granted.\n");
    else
            printf("Read permission denied.\n");

    if (access(filename, W_OK) == 0)
            printf("Write permission granted.\n");
    else
            printf("Write permission denied.\n");

    if (access(filename, X_OK) == 0)
            printf("Execute permission granted.\n");
    else
            printf("Execute permission denied.\n");

    

    return 0;
}
