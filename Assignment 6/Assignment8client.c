#include <stdio.h>
#include <dlfcn.h>

int main()
{
    char str[100];
    void *handler;
    int (*upper)(char *);
    int (*lower)(char *);
    int (*digit)(char *);

    printf("Enter string: ");
    scanf("%s", str);

    handler = dlopen("./Assignment8.so", RTLD_LAZY);
    if (!handler)
    {
        printf("Error loading library: %s\n", dlerror());
        return -1;
    }

    upper = (int (*)(char *))dlsym(handler, "CountUpper");
    lower = (int (*)(char *))dlsym(handler, "CountLower");
    digit = (int (*)(char *))dlsym(handler, "CountDigit");

    if (!upper || !lower || !digit)
    {
        printf("Error loading functions: %s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    printf("Uppercase letters: %d\n", upper(str));
    printf("Lowercase letters: %d\n", lower(str));
    printf("Digits: %d\n", digit(str));

    dlclose(handler);
    return 0;
}
