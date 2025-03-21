#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5
#define INF INT_MAX

typedef struct
{
    int vertex;
    int weight;
} edge;

typedef struct
{
    edge* edges;
    int size;
    int capacity;
} heapnode;

void swap(edge* a,edge* b)
{
    edge temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(heapnode* heap,int i)
{
    int smallest=i,left=2*i+1,right=2*i+2;
    if(left<heap->size&&heap->edges[left].weight<heap->edges[smallest].weight)
    {
        smallest=left;
    }
    if(right<heap->size&&heap->edges[right].weight<heap->edges[smallest].weight)
    {
        smallest=right;
    }
    if(i!=smallest)
    {
        swap(&heap->edges[i],&heap->edges[smallest]);
        heapify(heap,smallest);
    }
}

edge extract(heapnode* heap)
{
    edge min=heap->edges[0];
    heap->size--;
    heap->edges[0]=heap->edges[heap->size];
    heapify(heap,0);
    return min;
}

void insert(heapnode* heap,edge e)
{
    int i=heap->size;
    heap->size++;
    heap->edges[i]=e;
    while(i&&heap->edges[(i-1)/2].weight>heap->edges[i].weight)
    {
        swap(&heap->edges[(i-1)/2],&heap->edges[i]);
        i=(i-1)/2;
    }
}

void dijkstra(int graph[N][N],int start)
{
    int dist[N]={0};
    int visited[N]={0};
    int i,u,v;
    edge min;
    heapnode heap;
    heap.edges=(edge*)malloc(N*N*sizeof(edge));
    heap.size=0;
    heap.capacity=N*N;
    for(i=0;i<N;i++)
    {
        dist[i]=INF;
    }
    dist[start]=0;
    insert(&heap,(edge){start,0});
    while(heap.size>0)
    {
        min=extract(&heap);
        u=min.vertex;
        if(visited[u])
        {
            continue;
        }
        visited[u]=1;
        for(v=0;v<N;v++)
        {
            if(visited[v]==0&&graph[u][v]!=INF&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
                insert(&heap,(edge){v,dist[v]});
            }
        }
    }
    printf("From %d to all other points:\n",start);
    for(i=1;i<N;i++)
    {
        printf("to %d: %d\n",i,dist[i]);
    }
    free(heap.edges);
}

int main(void)
{
    int graph[N][N]={0,10,3,INF,INF,
                     INF,0,1,2,INF,
                     INF,4,0,8,2,
                     INF,INF,INF,0,7,
                     INF,INF,INF,9,0};
    dijkstra(graph,0);
    return 0;
}
