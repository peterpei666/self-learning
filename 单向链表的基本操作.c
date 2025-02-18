#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* create_node(int value)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

void insert_at_head(struct node** head, int value)
{
    struct node* new_node=create_node(value);
    new_node->next=*head;
    *head=new_node;
}

void insert_at_tail(struct node** head, int value)
{
    struct node* new_node=create_node(value);
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    else
    {
        struct node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void delete_node(struct node** head, int value)
{
    struct node *temp=*head, *previous=NULL;
    if((temp!=NULL)&&(temp->data==value))
    {
        *head=temp->next;
    }
    else
    {
        while((temp->data!=value)&&(temp->next!=NULL))
        {
            previous=temp;
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            previous->next=temp->next;
        }
    }
    free(temp);
}

void print_list(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

void free_list(struct node* head)
{
    struct node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}

struct node* connect_list(struct node* head1, struct node* head2)
{
    struct node* temp=head1;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}

struct node* merge_sorted_list(struct node* head1, struct node* head2)
{
    if(!head1)
    {
        return head2;
    }
    if(!head2)
    {
        return head1;
    }
    if(head1->data < head2->data)
    {
        head1->next=merge_sorted_list(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=merge_sorted_list(head1,head2->next);
        return head2;
    }
}

int main(void)
{
    struct node *head1 = NULL,*head2 = NULL,*head = NULL;
    insert_at_tail(&head1, 1);
    insert_at_tail(&head1, 3);
    insert_at_tail(&head1, 5);
    insert_at_tail(&head1, 7);
    insert_at_tail(&head1, 9);
    insert_at_tail(&head2, 2);
    insert_at_tail(&head2, 4);
    insert_at_tail(&head2, 6);
    insert_at_tail(&head2, 8);
    insert_at_tail(&head2, 10);
    printf("链表1：");
    print_list(head1);
    printf("链表2：");
    print_list(head2);
    printf("合并后的链表：");
    print_list(merge_sorted_list(head1,head2));
    head=head1?head1:head2;
    delete_node(&head, 8);
    printf("去除8后的链表：");
    print_list(head);
    free_list(head);
    return 0;
}
