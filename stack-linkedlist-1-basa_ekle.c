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
    tmp->next=head;
    head=tmp;
    return head;
}
node* pop(node *head)
{
    node *iter=head;
    head=head->next;
    free(iter);
    return head;
}
void bastir(const node* head)
{
    while(head)
    {
        printf("%d->", head->data);
        head=head->next;
    }
    puts("NULL");
}
void peek(node *head)
{
    printf("%d", head->data);
}

int main()
{
    node *head=NULL;
    head=push(head,10);
    peek(head);

    return 0;
}
