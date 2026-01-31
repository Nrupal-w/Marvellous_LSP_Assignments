#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handel=NULL;

    int (*fp)(int,int);

    int iret=0;
    int choice;
    int a;
    int b;


    handel=dlopen("./Assignment3.so",RTLD_LAZY);
    
    if (handel==NULL)
    {
        printf("unable to load the liblary\n");
        return -1;

    }

    
    printf("Library gets loaded successfully\n");

    printf("Enter the number for action:\n");
    printf("1 : Addition\n");
    printf("2 : Subtraction\n");
    printf("3 : Multiplication\n");
    printf("4 : Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter 1 number: ");
    scanf("%d", &a);
    printf("Enter 2 number: ");
    scanf("%d", &b);
    switch (choice)
    {
    case 1:
        fp=(int(*)(int,int))dlsym(handel,"Addition");
        if(fp==NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handel);
        return -1;
    }
        break;
    case 2:
        fp=(int(*)(int,int))dlsym(handel,"subtraction");
        if(fp==NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handel);
        return -1;
    }
        break;
    case 3:
        fp=(int(*)(int,int))dlsym(handel,"Multiplication");
        if(fp==NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handel);
        return -1;
    }
        break;
    case 4:
        fp=(int(*)(int,int))dlsym(handel,"division");
        if(fp==NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handel);
        return -1;
    }printf("Error: %s\n", dlerror());
        break;
    default:
        printf("Invalid Choice ");
        dlclose(handel);
        return -1;
        break;
    }
    iret=fp(a,b);
    printf("Result is :%d\n",iret);
    dlclose(handel);



}