/**
 * POJ-2346-Lucky tickets
 * 29/12/15 21:38:05
 * xuchen
**/
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

const int N = 10;
int dp[50][6];

int main()
{
    int n;

    for(int i=0; i<=5; i++)
        dp[0][i] = 1;
    for(int k=1; k<=5; k++)
    {
        n = k*9;
        for(int sum=1; sum<=n; sum++)
        {
            for(int d=0; d<10 && d<=sum; d++)
            {
                dp[sum][k] += dp[sum-d][k-1];
            }
        }
    }
    int ans[6];
    ans[0] = 0;
    for(int i=1; i<=5; i++)
    {
        int sum=0;
        for(int j=0; j<=9*i; j++)
        {
            sum += dp[j][i]*dp[j][i];
        }
        ans[i] = sum;
    }
    
    int m;
    while(scanf("%d", &m) != EOF)
    {
        printf("%d\n", ans[m/2]);
    }
    
    return 0;
}

