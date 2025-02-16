#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char time1[20];
    char time2[20];
    char web[50];
} access;

int main(void)
{
    FILE *fp = fopen("/Users/peiteer/Desktop/code/exercise/exercise/access_log.txt", "r");
    int count = 0, i = 0, num = 0, query, n = 0;
    int capacity = 20;
    access *list = (access *)malloc(capacity * sizeof(access));
    int *ids = (int *)malloc(capacity * sizeof(int));
    int *nums = (int *)malloc(capacity * sizeof(int));

    while (fscanf(fp, "%d %s %s %s", &list[count].id, list[count].time1, list[count].time1, list[count].web) == 4)
    {
        if (count >= capacity)
        {
            capacity *= 2;
            list = (access *)realloc(list, capacity * sizeof(access));
            ids = (int *)realloc(ids, capacity * sizeof(int));
            nums = (int *)realloc(nums, capacity * sizeof(int));
        }
        int found = 0;
        for (i = 0; i < n; i++)
        {
            if (list[count].id == ids[i])
            {
                nums[i]++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            ids[n] = list[count].id;
            nums[n] = 1;
            n++;
        }
        count++;
    }
    fclose(fp);
    for (i = 0; i < n; i++)
    {
        printf("User %d has visited %d times.\n", ids[i], nums[i]);
    }
    printf("Enter user ID to query: ");
    scanf("%d", &query);
    num = 0;
    for (i = 0; i < count; i++)
    {
        if (list[i].id == query)
        {
            printf("User %d visited %s at %s %s\n", list[i].id, list[i].web, list[i].time1, list[i].time2);
            num++;
        }
    }
    if (num == 0)
    {
        printf("No records found for user %d.\n", query);
    }
    free(list);
    free(ids);
    free(nums);
    return 0;
}

