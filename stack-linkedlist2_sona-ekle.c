#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node* push(node* head, int x)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=x;
    if(head==NULL)
    {
        tmp->next=head;
        head=tmp;
        tmp->next=NULL;

    }
    else
    {
        node *iter=head;
        for(;iter->next!=NULL;iter=iter->next);
        iter->next=tmp;
        tmp->next=NULL;

    }
    return head;
}
int pop(node *head)
{
    if(head==NULL)
    {
        printf("Bos stack");
        return -1;
    }
    else
    {
        if(head->next==NULL)
        {
           int rvalue=head->data;
           head=NULL;
           return rvalue;
        }
        node *iter=head;
        for(;iter->next->next!=NULL;iter=iter->next);
        int rvalue= iter->next->data;
        free(iter->next);
        iter->next=NULL;
        return rvalue;
    }
}
void bastir(node *head)
{
    node *iter=head;
    for(;iter!=NULL; iter=iter->next)
        printf("%d -> ",iter->data);
        puts("NULL");
}


int main()
{
    node *s=NULL;
    s=push(s,10);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    pop(s);




    return 0;

}
