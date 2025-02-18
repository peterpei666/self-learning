#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int capacity=2;
    int *odd = (int *)malloc(capacity * sizeof(int));
    int n,i,sum=0,count=0;
    float ave;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    ave=(float)sum/n;
    for(i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            odd[count]=arr[i];
            count++;
            if (count >= capacity)
            {
                capacity *= 2;
                odd = (int *)realloc(odd, capacity * sizeof(int));
            }
        }
    }
    printf("总和 %d \n",sum);
    printf("平均 %f \n",ave);
    printf("奇数有 %d 个\n",count);
    for(i=0;i<count;i++)
    {
        printf("%d ",odd[i]);
    }
    qsort(odd,count,sizeof(int),compare);
    printf("排序后\n");
    for(i=0;i<count;i++)
    {
        printf("%d ",odd[i]);
    }
    free(odd);
    return 0;
}
