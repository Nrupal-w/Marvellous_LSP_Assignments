#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handler = NULL;
    int (*fp[3])(int, int);   

    handler = dlopen("./Assignment9.so", RTLD_LAZY);
    if (handler == NULL)
    {
        printf("Error loading library: %s\n", dlerror());
        return -1;
    }

    fp[0] = (int (*)(int, int))dlsym(handler, "Addition");
    fp[1] = (int (*)(int, int))dlsym(handler, "Subtraction");
    fp[2] = (int (*)(int, int))dlsym(handler, "Multiplication");

    printf("Addition: %d\n", fp[0](10, 5));
    printf("Subtraction: %d\n", fp[1](10, 5));
    printf("Multiplication: %d\n", fp[2](10, 5));

    dlclose(handler);
    return 0;
}
