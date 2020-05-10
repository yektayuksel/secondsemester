#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x;
    struct node *next;
} node;
void eleman_Ekle(node *r, int z)
{
    /**while(r->next != NULL)
    {
        r=r->next;
    } Dongusu de ayni isi yapacaktir*/
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

int main()
{
    node *root;
    root = (node*)malloc(sizeof(node));
    node *iter;
    iter=root;
    root->x=10;
    root->next=NULL;
    for(int i = 0; i<10; i++)
        eleman_Ekle(root, (i+2)*10);
    print_Linked_List(root);



    return 0;
}
