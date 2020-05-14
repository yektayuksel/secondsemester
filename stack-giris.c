#include <stdio.h>
#include <stdlib.h>
int dizi[2];
int boyut=2;
int tepe=0;
void push(int a)
{
    if(tepe>=boyut)
    {

        int *tmp=(int*)malloc(sizeof(int)*boyut*2);

        for(int i=0; i<tepe; i++)
        {
            tmp[i] = dizi[i];
        }
        free(dizi);
        dizi[0]=tmp[0];
        boyut*=2;

    }

    dizi[tepe++]=a;
}
int pop()
{
    if(tepe<=boyut/4)
    {

        int *tmp=(int*)malloc(sizeof(int)*boyut/2);


         for(int i=0; i<tepe; i++)
        {
            tmp[i] = dizi[i];
        }

        free(dizi);
        dizi[0]=tmp[0];
        boyut/=2;

    }
    return dizi[--tepe];
}
void bastir()
{
    for(int i=0; i<tepe; i++)
    {
        printf("%d ", dizi[i]);
    }
}
void peek()
{
    printf("%d", dizi[tepe-1]);
}
int main()
{


    for(int i=1; i<=32; i++)
    {

        push(i);
        printf("\n%d.Boyut: %d\n\n",i, boyut);
    }

     bastir();

    return 0;
}
