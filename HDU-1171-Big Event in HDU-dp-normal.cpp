/**
 * HDU-1171-Big Event in HDU
 * 30/12/15 19:17:38
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

const int N = 250005;

bool dp[N];
int num[55];
int val[55];

int main()
{
    int n;
    while (scanf("%d", &n) && n>0)
    {
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d", &val[i], &num[i]);
            sum += val[i]*num[i];
        }
        
        int half = sum/2;
        dp[0] = true;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<num[i]; j++)
            {
                for(int k=half; k>=val[i]; k--)
                {
                    if(dp[k-val[i]])
                        dp[k] = true;
                }
            }
        }
        
        int ans = half;
        for(; ans>=0; ans--)
        {
            if(dp[ans])
                break;
        }
        printf("%d %d\n", sum-ans, ans);


    }

    return 0;
}

