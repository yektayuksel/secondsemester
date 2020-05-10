#include <stdio.h>
#include <stdlib.h>

                            /*****DOUBLY LINKED LIST*****///CIFT YONLU BAGLI LISTE
typedef struct node
{
    int x;
    struct node *prev;
    struct node *next;
}node;


node* sirali_Ekle(node *r, int x)
{
    if(r==NULL)
    {
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->prev=NULL;
        r->x=x;
        return r;
    }
    if(r->x > x)
    {
        node*tmp=(node*)malloc(sizeof(node));
        tmp -> x = x;
        tmp->next=r;
        r->prev=tmp;
       // tmp->prev=NULL;
        return tmp;
    }
    node *iter=r;

    while(iter->next!=NULL && iter->next->x < x)
    {

        iter=iter->next;
    }

    node*tmp=(node*)malloc(sizeof(node));
    tmp->next = iter->next;
    iter->next=tmp;
    tmp->prev=iter;
    if(tmp->next != NULL)
        tmp->next->prev=tmp;

    tmp->x=x;
    return r;

}
void bastir(node *r)
{
    node* iter = r;
    printf("%d ", iter->x);
    iter=iter->next;
    while(iter != NULL)
    {
        printf("%d ", iter->x);
        iter=iter->next;
    }

}
node* eleman_Sil(node *r, int x)
{
   node*iter=r;
   if(iter->x == x)
   {
       r=r->next;
       free(iter);
       return r;
   }

   while(iter->next!=NULL && iter->next->x != x)
   {
       iter=iter->next;

   }

    if(iter->next==NULL)
    {
        printf("\nSayi bulunamadi!");
        return r;
    }

   node *temp=iter->next;
   iter->next=iter->next->next;
   free(temp);
   if(iter->next != NULL)
   iter -> next -> prev = iter;
   return r;
}

int main()
{

    node *root = (node*)malloc(sizeof(node));
    root=NULL;
    root= sirali_Ekle(root, 400);
    root= sirali_Ekle(root, 40);
    root= sirali_Ekle(root, 4);
    root= sirali_Ekle(root, 450);
    root= sirali_Ekle(root, 50);
    node *iter=root;
    bastir(root);
    root =eleman_Sil(root,450);
    printf("\n");
    bastir(root);

    return 0;
}
