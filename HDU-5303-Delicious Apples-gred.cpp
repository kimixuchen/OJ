/**
 * HDU-5303-Delicious Apples
 * 21/12/15 19:25:20
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

const int INF = 0x3f3f3f3f;
const int N = 2000008;

int apple[N];
int leftc[N], rightc[N];
long long num1[N], num2[N];

int main()
{
    int t, l, n, k;
    int x, a;
    int nLeft, nRight;
    int cnt;
    long long ans;
    scanf("%d", &t);
    while(t--)
    {
        cnt=0;
        ans = INF;
        scanf("%d%d%d", &l, &n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &x, &a);
            for(int j=0; j<a; j++)
            {
                apple[++cnt] = x;           //treat each apple alone
            }
        }
        
        k = min(k, cnt);
        nLeft = 0;
        nRight = 0;
        for(int i=1; i<=cnt; i++)
        {
            if(apple[i]<<1 <= l)
            {
                leftc[++nLeft] = apple[i];   //left half cycle
            }
            else
            {
                rightc[++nRight] = l - apple[i]; //right half cycle
            }
        }
        sort(leftc+1, leftc+nLeft+1);
        sort(rightc+1, rightc+nRight+1);
        
        for(int i=1; i<=nLeft; i++)
        {
            if(i<=k)
                num1[i] = leftc[i];
            else
                num1[i] = num1[i-k] + leftc[i];
        }
        for(int i=1; i<=nRight; i++)
        {
            if(i<=k)
                num2[i] = rightc[i];
            else
                num2[i] = num2[i-k] + rightc[i];
        }
        ans = 2*num1[nLeft] + 2*num2[nRight];
        for(int i=0; i<=nLeft && i<=k; i++)
        {
            ans = min(ans, (l + 2*num1[nLeft-i] + 2*num2[nRight-(k-i)]));
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}

