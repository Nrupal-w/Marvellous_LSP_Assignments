#include<stdio.h>
#include<dlfcn.h>

int main()
{
  void *handel=NULL;
  int (*fp)(int,int);
  int iret=0;

  handel=dlopen("./Assignment1.so",RTLD_LAZY);
  if (handel==NULL)
  {
    printf("Unable to load liblary");
    return -1;

  }
  printf("Liblary gets loaded sucessfully\n");
  fp=(int(*)(int,int))dlsym(handel,"Addition");
  if (fp==NULL)
  {
    printf("Unable to get the adress of the function");
    dlclose(handel);
    return -1;
  }
  iret=fp(11,10);
  printf("Addition of the 2 numbers are :%d\n",iret);

  fp=(int(*)(int,int))dlsym(handel,"subtraction");
  if (fp==NULL)
  {
    printf("Unable to get the adress of the function");
    dlclose(handel);
    return -1;
  }
  iret=fp(11,13);
  printf("subraction of the 2 numbers are :%d\n",iret);
  dlclose(handel);

  return 0;

}
