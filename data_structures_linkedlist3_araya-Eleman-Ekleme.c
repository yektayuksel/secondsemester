#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int x;
    struct node *next;
} node;
void eleman_Ekle(node *r, int z);
void print_Linked_List(node *r);

            /*****LINKED LISTTE IKI ELEMAN ARASINA YENI BIR ELEMAN EKLEMEK*****/

void arayaEkle(node*iter, int kacinciEleman, int eklenecekDeger)
{
   for(int i=0; i<kacinciEleman-1; i++)           ///4 ve 5. eleman arasina yeni bir eleman eklenmek isteniyorsa
    {                                             ///donguyle iterator 4. elemana getirilir.
       iter = iter->next;                         ///Yani roottan baþlayarak 3 kere hareket ettirilmelidir.
                                                  ///root->next(1)->next(2)-next(3) ile 4. elemana ulasabiliriz.
    }

    node *temp=(node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x=eklenecekDeger;


}

int main()
{
    node *root;
    root = (node*)malloc(sizeof(node));
    node *iter;
    iter=root;
    root->x=10;
    root->next=NULL;
    for(int i = 0; i<5; i++)
        eleman_Ekle(root, (i+2)*10);
    print_Linked_List(root);
    arayaEkle(iter, 3, 10);
    printf("\n");
    print_Linked_List(root);
     /*arayaEkle(iter, 7, 31);
    printf("\n");
    print_Linked_List(root);*/


}
void eleman_Ekle(node *r, int z)
{
    for(;r->next!=NULL;r=r->next);
    r->next=(node*)malloc(sizeof(node));
    r->next->x=z;
    r->next->next=NULL;
}
void print_Linked_List(node *r)
{
    while(r!=NULL)
    {
        printf("%4d", r->x);
        r=r->next;
    }
}

