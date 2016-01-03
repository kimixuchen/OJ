/**
 * POJ-1664-·ÅÆ»¹û
 * 03/01/16 15:36:01
 * xuchen
**/
/**
 * dp
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

const int N = 12;
int f[N][N];

int divide(int m, int n)
{
    if(m<0)
        return 0;
    if(m==0 || n==1)
        return f[m][n] = 1;
    if(f[m][n]>0)
        return f[m][n];

    int num=0;
    f[m][n] = divide(m-n, n) + divide(m, n-1);
    return f[m][n];
}
int main()
{
    int t;
    int m, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        memset(f, 0, sizeof(f));
        printf("%d\n", divide(m, n));

    }

    return 0;
}

