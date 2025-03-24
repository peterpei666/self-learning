#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int tree[4*MAX];
int arr[MAX];

void build(int node,int start,int end)
{
    int mid,left,right;
    if(start==end)
    {
        tree[node]=arr[start];
    }
    else
    {
        mid=(start+end)/2;
        left=node*2;
        right=node*2+1;
        build(left,start,mid);
        build(right,mid,right);
        tree[node]=tree[left]+tree[right];
    }
}

int query(int node,int start,int end,int l,int r)
{
    if(r<start||l>end)
    {
        return 0;
    }
    if(r>=end&&l<=start)
    {
        return tree[node];
    }
    int mid,left,right;
    mid=(start+end)/2;
    left=query(node*2,start,mid,l,r);
    right=query(node*2+1,mid+1,end,l,r);
    return left+right;
}

void update(int node,int start,int end,int index,int val)
{
    if(start==end)
    {
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(index<=mid)
        {
            update(node*2,start,mid,index,val);
        }
        else
        {
            update(node*2+1,mid+1,end,index,val);
        }
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
