#include <stdio.h>
#include <stdlib.h>

/*****CYCLIC LINKED LIST*****/
///Sondaki elemanin rootu gostedigi linked list cesididir.
typedef struct node
{
    int x;
    struct node *next;
} node;
void bastir(node *r)
{
    node* iter = r;
    printf("%d ", iter->x);
    iter=iter->next;
    while(iter != r)
    {
        printf("%d ", iter->x);
        iter=iter->next;
    }

}
void eleman_Ekle(node *r, int x)
{
    node *iter=r;
    while(iter->next != r)
    {
        iter=iter->next;
    }
    iter->next = (node*)malloc(sizeof(node)); ///Yeni kutuyu olustur.(Ýter hala linked liste bagli. Dolayisiyla kopma yok)
    iter->next->x=x; ///Yeni kutuya gerekli elemani koy.
    iter->next->next=r; ///Yeni kutuyu roota bagla.

}
node* sirali_Eleman_Ekle(node *r, int x)
{
    ///Circular Linked Listin bos olma durumu:
    if(r==NULL)
    {
        r=(node*)malloc(sizeof(node));
        r->x=x;
        r->next=r;
        return r;
    }
    ///Eklenen elemanin ilk elemandan kucuk olma durumu:
    if(r->x > x)
    {
        ///Root degisiyor.
        node *temp=(node*)malloc(sizeof(node));
        temp->x=x;
        temp->next=r; ///yeni eklenen eleman yeni root oluyor.
        node *iter=r;
        while(iter->next!=r)
        {
            iter=iter->next; ///iter orjinal linked listin son elemanina geliyor.
        }
        iter->next=temp; ///Son eleman yeni eklenen elemana (yeni roota) baglaniyor.
        return temp; ///yeni root donduruluyor.

    }
    node *iter = r;
    while(iter->next != r && iter->next->x < x)
        iter=iter->next;

    node *temp=(node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next=temp;
    temp -> x = x;
    return r;
}
int main()
{

    node *root=(node*)malloc(sizeof(node));
    root=NULL;
    node *iter=root;


    root=sirali_Eleman_Ekle(root, 400);
    root=sirali_Eleman_Ekle(root, 40);
    root=sirali_Eleman_Ekle(root, 4);
    root=sirali_Eleman_Ekle(root, 450);
    root=sirali_Eleman_Ekle(root, 50);
    bastir(root);
    return 0;
}
