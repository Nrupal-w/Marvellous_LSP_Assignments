#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handler = NULL;
    char *error = NULL;

    void (*inc)();
    void (*disp)();
    void (*reset)();

    handler = dlopen("./Assignmnet7.so", RTLD_LAZY);
    if (handler == NULL)
    {
        printf("Error loading library: %s\n", dlerror());
        return -1;
    }

    dlerror(); 
    inc = (void (*)())dlsym(handler, "Increment");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Increment: %s\n", error);
        dlclose(handler);
        return -1;
    }

    disp = (void (*)())dlsym(handler, "Display");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Display: %s\n", error);
        dlclose(handler);
        return -1;
    }

    reset = (void (*)())dlsym(handler, "Reset");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Reset: %s\n", error);
        dlclose(handler);
        return -1;
    }

    inc();
    inc();
    disp();

    reset();
    disp();

    dlclose(handler);
    return 0;
}
