#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define maxn 100000
#define inf 0x7fffffff

typedef struct ver
{
    int num, color;
    ver(int n, int c):num(n), color(c){ }
}Ver;

int n,m,a,b,c;
int d[maxn],res[maxn]; // d�����¼ÿ���㵽�յ����̾��룬res�����¼���·������ɫ
bool vis[maxn], inqueue[maxn]; // vis�����¼ÿ���ڵ��Ƿ񱻷��ʣ� inqueue��ǽڵ��Ƿ�����˶��У���ֹ�ظ�����
vector<Ver> edge[maxn]; //�ڽӱ��¼ͼ

void bfs(int start, int e)
{
    memset(inqueue, 0 ,sizeof(inqueue));
    memset(vis, 0, sizeof(vis));
    int u,v;
    queue<int> q;
    q.push(start);
    if(start == 0)
    {
        memset(res, 0, sizeof(res));
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            vis[u] = 1;
            if(u == n -1)
                return;
            int minc = inf,len = edge[u].size();
            for(int i = 0;i<len;i++)
            {
                if(!vis[v=edge[u][i].num] && d[u] - 1 == d[v])
                    minc = min(edge[u][i].color, minc);
            }
            for(int i = 0;i<len;i++)
            {
                if(!vis[v=edge[u][i].num] && d[u] - 1 == d[v] && edge[u][i].color == minc && !inqueue[v])
                {
                    q.push(v);
                    inqueue[v] = 1;
                }
            }
            int index = d[0] - d[u];
            if(res[index] == 0)
                res[index] = minc;
            else
                res[index] = min(res[index], minc);
        }
    }
    else
    {
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            vis[u] = 1;
            for(int i = 0,len = edge[u].size();i<len;i++)
            {
                if(!vis[v=edge[u][i].num] && !inqueue[v])
                {
                    d[v] = d[u] + 1;
                    if(v == 0)
                        return;
                    q.push(v);
                    inqueue[v] = 1;
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) == 2)
    {
        for(int i = 0;i<n;i++)
            edge[i].clear();
        memset(d, -1, sizeof(d));
        d[n-1] = 0;
        while(m--)
        {
            scanf("%d%d%d", &a, &b,&c);
            if(a!=b)
            {
                edge[a-1].push_back(ver(b-1,c));
                edge[b-1].push_back(ver(a-1,c));
            }
        }
        bfs(n-1,0);
        bfs(0,n-1);
        printf("%d\n%d",d[0],res[0]);
        for(int i = 1;i<d[0];i++)
            printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}
