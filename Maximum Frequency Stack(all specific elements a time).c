#include <stdio.h>
#include <stdlib.h>

#define M 100083

typedef struct
{
    int value;
    int frequency;
} tuple;

typedef struct
{
    tuple* heap;
    int size;
    int capacity;
} FreqStack;

typedef struct
{
    int value;
    int position;
    struct node* next;
} node;

node* hash_table[M];

int hash_func(int value)
{
    return value%M;
}

node* create(int value,int position)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->value=value;
    newnode->position=position;
    newnode->next=NULL;
    return newnode;
}

void insert(int value,int position)
{
    int hash=hash_func(value);
    node* temp;
    node* newnode=create(value,position);
    if(hash_table[hash]==NULL)
    {
        hash_table[hash]=newnode;
    }
    else
    {
        temp=hash_table[hash];
        while(temp->next)
        {
            temp=(node*)temp->next;
        }
        temp->next=(struct node*)newnode;
    }
}

int find(int value)
{
    int hash=hash_func(value);
    int position=-1;
    node* temp=hash_table[hash];
    while(temp)
    {
        if(temp->value==value)
        {
            position=temp->position;
            break;
        }
        temp=(node*)temp->next;
    }
    return position;
}

void interchange(int val1,int val2)
{
    int hash1=hash_func(val1);
    int hash2=hash_func(val2);
    int temp;
    node* temp1=hash_table[hash1];
    node* temp2=hash_table[hash2];
    while(temp1)
    {
        if(temp1->value==val1)
        {
            break;
        }
        temp1=(node*)temp1->next;
    }
    while(temp2)
    {
        if(temp2->value==val2)
        {
            break;
        }
        temp2=(node*)temp2->next;
    }
    temp=temp1->position;
    temp1->position=temp2->position;
    temp2->position=temp;
}

inline void swap(tuple* a,tuple* b)
{
    tuple temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(FreqStack* obj,int largest)
{
    int i=largest;
    int left=2*largest+1;
    int right=2*largest+2;
    if(left<obj->size&&obj->heap[i].frequency<obj->heap[left].frequency)
    {
        i=left;
    }
    if(right<obj->size&&obj->heap[i].frequency<obj->heap[right].frequency)
    {
        i=right;
    }
    if(largest!=i)
    {
        interchange(obj->heap[i].value,obj->heap[largest].value);
        swap(&obj->heap[i],&obj->heap[largest]);
        heapify(obj,i);
    }
}

void change_capacity(FreqStack* obj)
{
    int c=(obj->size+12)/10*10;
    if(c!=obj->capacity)
    {
        obj->capacity=c;
        obj->heap=(tuple*)realloc(obj->heap,c*sizeof(tuple));
    }
}

void clear(int value)
{
    int hash=hash_func(value);
    node* temp=hash_table[hash];
    node* prev=NULL;
    while(temp&&temp->value!=value)
    {
        prev=temp;
        temp=(node*)temp->next;
    }
    if(temp==hash_table[hash])
    {
        free(temp);
        hash_table[hash]=NULL;
    }
    else
    {
        prev->next=temp->next;
        free(temp);
    }
}

int freqStackPop(FreqStack* obj)
{
    tuple temp=obj->heap[0];
    node* tem;
    int hash;
    clear(temp.value);
    obj->size--;
    change_capacity(obj);
    obj->heap[0]=obj->heap[obj->size];
    hash=hash_func(obj->heap[obj->size].value);
    tem=hash_table[hash];
    while(tem)
    {
        if(tem->value==obj->heap[obj->size].value)
        {
            tem->position=0;
        }
        tem=(node*)tem->next;
    }
    heapify(obj,0);
    return temp.value;
}

FreqStack* freqStackCreate(void)
{
    int i;
    FreqStack* obj=(FreqStack*)malloc(sizeof(FreqStack));
    obj->heap=(tuple*)malloc(10*sizeof(tuple));
    obj->size=0;
    obj->capacity=10;
    for(i=0;i<M;i++)
    {
        hash_table[i]=NULL;
    }
    return obj;
}

void freqStackPush(FreqStack* obj, int val)
{
    int p=find(val);
    int a=obj->size;
    if(p==-1)
    {
        obj->size++;
        change_capacity(obj);
        insert(val,a);
        obj->heap[a]=(tuple){val,1};
        while(a&&obj->heap[(a-1)/2].frequency<=obj->heap[a].frequency)
        {
            swap(&obj->heap[(a-1)/2],&obj->heap[a]);
            interchange(obj->heap[(a-1)/2].value,obj->heap[a].value);
            a=(a-1)/2;
        }
    }
    else
    {
        a=p;
        obj->heap[p].frequency++;
        while(a&&obj->heap[(a-1)/2].frequency<=obj->heap[a].frequency)
        {
            swap(&obj->heap[(a-1)/2],&obj->heap[a]);
            interchange(obj->heap[(a-1)/2].value,obj->heap[a].value);
            a=(a-1)/2;
        }
    }
}

void freqStackFree(FreqStack* obj)
{
    int i;
    node* temp;
    node* prev;
    free(obj->heap);
    free(obj);
    for(i=0;i<M;i++)
    {
        if(hash_table[i])
        {
            temp=hash_table[i];
            while(temp)
            {
                prev=temp;
                temp=(node*)temp->next;
                free(prev);
            }
            hash_table[i]=NULL;
        }
    }
}
