#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x;
    struct node *next;
}node;

void elemanEkle(node *r, int x)
{
    for(; r->next!=NULL; r=r->next);
    r->next=(node*)malloc(sizeof(node));
    r->next->x=x;
    r->next->next=NULL;

}
node* sirali_Ekle(node *r, int x)
{
    if(r==NULL)
    {   ///Linked List Bossa
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->x=x;
        return r;
    }
    if(r->x>x)
    {   ///Linked Link bos degil ve ilk elemandan kucuk
        ///ROOT degisiyor cunku artik ilk eleman farkli.
        node*tmp=(node*)malloc(sizeof(node));
        tmp -> x = x;
        tmp->next=r;
        return tmp;
    }
    node *iter=r;
    ///Ilk iki durum disinda global calisir
    ///Araya veya sona eleman eklenir.
    while(iter->next!=NULL && iter->next->x < x)
    {
        ///Eklenen elemandan kucuk bir eleman ariyor. Bulursa duruyor. (ikinci durum 0  oluyor)
        ///Sayet eklenen elemandan kucuk bir eleman yoksa linked listin sonuna gidiyor.(birinci durum 0 oluyor.)
        iter=iter->next;
    }

    node*tmp=(node*)malloc(sizeof(node));
    tmp->next = iter->next; ///x'in gosterdigi degeri, x'ten kucuk elemanin gosterigi degere esitler.
    iter->next=tmp;  ///x'ten kucuk eleman artik x'i gosterir.
    tmp->x=x;
    return r;

}

int main()
{
    int i;
    node *root = (node*)malloc(sizeof(node));
    root=NULL;
    root= sirali_Ekle(root, 400);
    root= sirali_Ekle(root, 40);
    root= sirali_Ekle(root, 4);
    root= sirali_Ekle(root, 450);
    root= sirali_Ekle(root, 50);

    node *iter=root;
    for(i=0; i<5; i++)
    {
        printf("%d. %d\n",i+1, iter->x);
        iter=iter->next;
    }





    return 0;
}
