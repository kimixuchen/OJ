/**
 *xuchen
 *2015-11-24 16:45:06
**/
/**
 *Flow network Demo
**/
#include "stdio.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int N = 55;
const int INF = 0x3f3f3f3f;

struct node{
    int cap;
    int _in[15];
    int out[15];
};
struct dependence{
    int a;
    int b;
    int cap;
};
node nodes[N];
int map[N<<1][N<<1];
int path[N];
int flows[N];
queue<int> q;

int BFS(int m, int s, int t)
{
    memset(path, -1, sizeof(path));
    while(!q.empty())
        q.pop();

    q.push(s);
    path[s] = 0;
    flows[s] = INF;
    bool flag = false;  //if we have found t
    int cur;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i=1; i<=m; i++)
        {
            if(path[i]==-1 && map[cur][i]>0 && !flag)
            {
                flows[i] = flows[cur]<map[cur][i] ? flows[cur]:map[cur][i];
                path[i] = cur;
                q.push(i);
                if(i==t)
                    flag = true;
            }
        }
        if(flag)
            break;
    }
    if(path[t]==-1)
        return 0;
    return flows[t];

}
int Edmons_Karp(int m, int s, int t)
{
    int max_flow = 0;
    int inc;
    while((inc=BFS(m, s, t)) != 0)
    {
        max_flow += inc;
        int m = t;
        while(m!=s)
        {
            map[path[m]][m] -= inc;
            map[m][path[m]] += inc;
            m = path[m];
        }
    }
    return max_flow;
}

bool match(const int* a, const int* b, int num)
{
    for(int i=0; i<num; i++)
    {
        if(*(a+i)==*(b+i) || *(b+i)==2)
            continue;
        else
            return false;
    }
    return true;
}

void addEdge(int s, int t, int cap)
{
    map[s][t]+=cap;
}

int main()
{
    int n, m, p;
    int from, to, cap;
    int startStr[15], endStr[15];
    int ans;

    memset(map, 0, sizeof(map));
    memset(startStr, 0, sizeof(startStr));
    for(int i=0; i<15; i++)
        endStr[i] = 1;
    scanf("%d%d", &p, &n);
    int s = 0;
    int t = (n<<1)+1;

    for(int i=1; i<=n;  i++)
    {
        scanf("%d", &nodes[i].cap);
        for(int j=0; j<p; j++)
            scanf("%d", &nodes[i]._in[j]);
        
        for(int j=0; j<p; j++)
            scanf("%d", &nodes[i].out[j]);
    }

    for(int i=1; i<=n; i++)
    {
        addEdge(i, n+i, nodes[i].cap);
        if(match(startStr, nodes[i]._in, p))
            addEdge(s, i, INF);
        if(match(endStr, nodes[i].out, p))
            addEdge(n+i, t, INF);
        for(int j=1; j<=n; j++)
        {
            if(match(nodes[i].out, nodes[j]._in, p))
            {
                addEdge(n+i, j, INF);
            }
        }
    }

    ans = Edmons_Karp((n<<1)+1, 0, (n<<1)+1);
    printf("%d ", ans);
    int depNum = 0;
    queue<dependence> output;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                continue;
            if(map[j][n+i]>0)
            {
                depNum++;
                dependence tmp;
                tmp.a = i;
                tmp.b = j;
                tmp.cap = map[j][n+i];
                output.push(tmp);
            }
        }
    }
    printf("%d\n", depNum);
    while(!output.empty())
    {
        dependence tmp = output.front();
        output.pop();
        printf("%d %d %d\n", tmp.a, tmp.b, tmp.cap);
    }
	return 0;
}

