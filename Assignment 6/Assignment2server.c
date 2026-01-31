#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *handel=NULL;

    int(*fp)(int,int);

    int iret=0;
    handel=dlopen("./Assignmnet1.so",RTLD_LAZY);
    // dlopen() returns a handle to the loaded shared library


    if (handel==NULL)
    {
        printf("Unable to load the file");
        return -1;
    }
    // dlsym() is used to obtain the address of the Addition function
    // from the loaded shared library using the handle

    fp=(int(*)(int,int))dlsym(handel,"Addition");
    if (fp==NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handel);
        return -1;
    }
    iret=fp(12,11);
    printf("Addition of the 2 numbers are :%d",iret);
    // dlclose() is used to unload the shared library and release resources
    dlclose(handel);
    return 0;




}