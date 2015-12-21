/**
 * UVA-11729
 * 21/12/15 15:51:33
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
const int N = 1005;

struct solder{
    int a, b;
};

bool cmp(solder i, solder j)
{
    return i.a > j.a;
}

solder s[N];

int main()
{
    int t, n, ans;
    t = 0;
    while(scanf("%d", &n) && n!=0)
    {
        t++;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &s[i].b, &s[i].a);
        }
        sort(s, s+n, cmp);
        
        ans = 0;
        int preb = 0;
        for(int i=0; i<n; i++)
        {
            ans = max(ans, preb+s[i].a+s[i].b);
            preb += s[i].b;
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}

