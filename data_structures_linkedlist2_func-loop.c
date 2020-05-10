#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
}node;
void bastir(node *r)
{
    int i = 0;
    while(r->next != NULL)
    {
        i++;
        printf("%d. eleman %d\n",i, r->x);
        r = r->next;
    }
}

int main()
{
     /*****LOOP ILE LINKED LIST KONTROLU*****/

  //Linked listlere sequantial acces yani dogrusal erisim ile erisilir.
  //Arraylere ise random access yani rastgele erisim ile istenilen noktasina erisilebilinir.

    node *root;
    root = (node*)malloc(sizeof(node));
    root->x = 10;
    root->next=(node*)malloc(sizeof(node));
    root->next->x=20;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->x=30;
    node *iter;
    iter = root;
    /**C salak bir dil oldugu icin NULL atamasi elle yapilir*///Aksi takdirde "segmentation fault" hatasi alinir veya
    root->next->next->next=NULL;                              //sonuz loopa girer.
    int i = 0;
    while(iter->next != NULL) //inter->next kullanýlmasýnýn sebebi, iter NULL degeri gosterdikten sonra
    {                         //iter kullanarak yeni eleman ekleme sansini kaybetmemizden dolayidir.
        i++;                  //Dongu bu sekilde kuruldugunda ise dongu sonunda iter son elemani gosterecektir.
        printf("%d. eleman %d\n",i, iter->x);
        iter = iter->next;

    }
    //Bu dongu, linked listteki son elemana gelene kadar liste uzerinde dolassip
    //iter'in son elemani isaret etmesini saglayacaktir.
    iter = root;
    for(i=2; i<=5; i++)
    {
        iter->next = (node*)malloc(sizeof(node));
        iter = iter->next;
        iter->x=i*10;
        iter->next=NULL; ///C aptal bir dil oldugu icin her seferinde
    }                    ///son pointerýn gosterdigi degere NULL atamasi yapiliyor.
    printf("\n\nYeni Linked List\n");
    bastir(root); //Linked Listi bastirmak icin tanimlanan fonksiyon.

    return 0;
}
