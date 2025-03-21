#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5
#define INF INT_MAX

int mindist(int* dist,int* visited)
{
    int min=INF,index=-1,v;
    for(v=0;v<N;v++)
    {
        if(visited[v]==0&&dist[v]<=min)
        {
            min=dist[v];
            index=v;
        }
    }
    return index;
}

void dijkstra(int graph[N][N],int start)
{
    int i,u,v,count;
    int dist[N];
    int visited[N]={0};
    for(i=0;i<N;i++)
    {
        dist[i]=INF;
    }
    dist[start]=0;
    for(count=0;count<N-1;count++)
    {
        u=mindist(dist,visited);
        visited[u]=1;
        for(v=0;v<N;v++)
        {
            if(visited[v]==0&&graph[u][v]!=INF&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("From %d to all other points:\n",start);
    for(i=1;i<N;i++)
    {
        printf("to %d: %d\n",i,dist[i]);
    }
}

int main(void)
{
    int graph[N][N]={0,10,3,7,5,
                     9,0,1,2,8,
                     INF,4,0,8,2,
                     INF,INF,INF,0,7,
                     INF,INF,INF,9,0};
    dijkstra(graph,0);
    return 0;
}
