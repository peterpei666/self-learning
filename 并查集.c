#include <stdio.h>

#define MAX 1000

int parent[MAX];
int rank[MAX];

void initialize(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=1;
    }
}

int find(int x)
{
    if(x!=parent[x])
    {
        parent[x]=find(parent[x]);
        return parent[x];
    }
    else
    {
        return x;
    }
}

void union_sets(int a,int b)
{
    int rootA=find(a);
    int rootB=find(b);
    if(rootA!=rootB)
    {
        if(rank[rootA]>rank[rootB])
        {
            parent[rootB]=rootA;
        }
        else if(rank[rootA]<rank[rootB])
        {
            parent[rootA]=rootB;
        }
        else
        {
            parent[rootB]=rootA;
            rank[rootA]++;
        }
    }
}

int main(void)
{
    int n = 10;
    initialize(n);
    union_sets(1, 2);
    union_sets(2, 3);
    union_sets(4, 5);
    printf("1 和 3 是否在同一集合: %d\n", find(1) == find(3));  // 1
    printf("1 和 4 是否在同一集合: %d\n", find(1) == find(4));  // 0
    return 0;
}
