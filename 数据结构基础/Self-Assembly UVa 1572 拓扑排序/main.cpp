#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 52;
int c[maxn];
bool g[maxn][maxn];

//给每个标号分配id
int id(char a1, char a2)
{
    return (a1 - 'A') * 2 + (a2 == '+' ? 0:1);
}

//将输入的正方形和标号转化为有向图
void connect(char a1, char a2, char b1, char b2)
{
    if(a1 == '0' || b1 == '0')
        return
    int u = id(a1, a2) ^ 1, v = id(b1, b2);
    g[u][v] = true;
}

//拓扑排序 return false 表示不是有向环 return true 表示有向环
bool toposort(int u)
{
    c[u] = -1;
    for(int v = 0;v<maxn;v++)
    {
        if(g[u][v])
        {
            if(c[v] < 0)
                return true;
            else if(!c[v] && toposort(v))
                return true;
        }
    }
    c[u] = 1;
    return false;
}

bool cycle()
{
    memset(c, 0, sizeof(c));
    for(int i = 0;i<maxn;i++)
        if(!c[i])
            if(toposort(i))
                return true;
    return false;
}

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        memset(g, 0, sizeof(g));
        while(n--)
        {
            char s[10];
            scanf("%s", s);
            for(int i = 0;i<4;i++)
                for(int j = 0;j<4;j++)
                    if(i!=j)
                        connect(s[i*2], s[i*2 + 1], s[j*2], s[j*2+1]);
        }
        printf("%s\n", cycle() ? "unbounded" : "bounded");
    }
    return 0;
}
