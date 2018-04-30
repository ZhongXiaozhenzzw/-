#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int edge[26][26];
int vis[10];
int num[10];
int alpha[26];
char str[100];
int result[10];
int temp[10];
int n, minn;

void dfs(int u, int maxn)
{
    if(u == n)
    {
        if(maxn < minn)
        {
            minn = maxn;
            for(int i = 0; i < n; i++)
                result[i] = temp[i];
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                temp[u] = num[i];
                for(int j = 0; j < u;j++)
                {
                    if(edge[temp[j]][temp[u]] == 1 && maxn < u - j)
                    {
                        maxn = u -j;
                    }
                }
                if(maxn > minn)
                {
                    vis[i] = false;
                    return;
                }
                dfs(u + 1, maxn);
                vis[i] = false;
            }
        }
    }
}


int main()
{
    while(scanf("%s", str) && str[0] != '#')
    {
        n = 0;
        minn = 11;
        int head;
        int flag = 0;
        memset(vis, 0, sizeof(vis));
        memset(edge, 0, sizeof(edge));
        memset(alpha, 0, sizeof(alpha));
        for(int i = 0; str[i] != '\0'; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                if(!alpha[str[i] - 'A'])
                {
                    num[n] = str[i] - 'A';
                    n++;
                    alpha[str[i] - 'A'] = 1;
                }
                if(flag)
                {
                    edge[head][str[i] - 'A'] = 1;
                    edge[str[i] - 'A'][head] = 1;
                }
            }
            else if(str[i] == ':')
            {
                head = str[i - 1] - 'A';
                flag = 1;
            }
            else if(str[i] == ';')
            {
                flag = 0;
            }
        }
        sort(num, num + n);
        dfs(0, 0);
        for(int i = 0; i < n; i++)
            printf("%c ", result[i]+'A');
        printf("-> %d\n", minn);
    }
    return 0;
}
