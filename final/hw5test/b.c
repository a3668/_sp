#include <stdio.h>

int mymin(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int mymax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxCap(int ht[], int htlen)
{
    int i = 0;
    int j = htlen - 1;
    // intitilze
    int res = 0;
    while (i < j)
    {
        int capa = mymin(ht[i], ht[j]) * (j - i);
        res = mymax(res, capa);
        if (ht[i] < ht[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int ans = maxCap(arr, len);
    printf("Max capacity: %d\n", ans);
    return 0;
}
