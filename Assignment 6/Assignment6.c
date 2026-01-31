#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle = dlopen("Assignment1.so", RTLD_LAZY);
    if (!handle)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    printf("Library loaded successfully\n");
    dlclose(handle);
    return 0;
}

// without LD_LIBLARY_PATH  ./client
//Error: Assignment1.so: cannot open shared object file: No such file or directory
//with LD_LIBLARY_PATH 
// no error full code runing 