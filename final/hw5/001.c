//
//  main.c
//  newIsland
//
//  Created by 耀 on 2024/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct island
{
    int number;
    int opens;
    char *name;
    struct island *next;
} Island;
typedef struct _list
{
    Island *head;
} List;
void add(List *pList, int number1, int opens1, char *name1);
void print(List *pList);
int removeIsland(List *pList, char *name);
int main(int argc, const char *argv[])
{
    int number1;
    int opens1;
    char name1[20];
    List list;
    list.head = NULL;
    do
    {
        scanf("%d", &number1);
        if (number1 == -1)
        {
            break;
        }
        else
        {
            scanf("%d %s", &opens1, name1);
        }
        add(&list, number1, opens1, name1);
    } while (1);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    print(&list);
    scanf("%s", name1);

    int isFound = removeIsland(&list, name1);
    if (isFound)
        print(&list);

    return 0;
}
void add(List *pList, int number1, int opens1, char *name1)
{
    Island *p = (Island *)malloc(sizeof(Island));
    p->number = number1;
    p->opens = opens1;
    p->name = (char *)malloc(strlen(name1) + 1); // 分配記憶體給名稱
    strcpy(p->name, name1);
    p->next = NULL;
    // find the last
    Island *last = pList->head;
    if (last != NULL)
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = p;
    }
    else
    {
        pList->head = p;
    }
}
void print(List *pList)
{
    Island *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("number:%d opens:%d name:%s\n", p->number, p->opens, p->name);
    }
    printf("\n");
}
int removeIsland(List *pList, char *name1)
{
    Island *p;
    Island *q;
    int isFound = 0;
    for (q = NULL, p = pList->head; p; q = p, p = p->next)
    {
        if (strcmp(p->name, name1) == 0)
        {
            if (q != NULL)
            {
                q->next = p->next;
            }
            else
            {
                pList->head = p->next;
            }
            printf("is found\n");
            isFound = 1;
            free(p);
            break;
        }
    }
    if (isFound != 1)
    {
        printf("not found\n");
    }
    return isFound;
}
