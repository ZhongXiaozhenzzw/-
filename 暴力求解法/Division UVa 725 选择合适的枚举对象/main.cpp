#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int first = 0;
    int vis[10];
    while(scanf("%d",&n) && n)
    {
        int a,b,c,d,e,f,g,h,i,j;
        int ok = 0;
        int num, y;
        if(first == 0)
            first = 1;
        else
            printf("\n");
        for(int x = 1234;x<=98765;x++)
        {
            memset(vis, 0, sizeof(vis));
            num = x * n;
            if(num > 98765)
                break;
            a = num / 10000 % 10, b = num / 1000 % 10, c = num / 100 %10, d = num / 10 % 10, e = num %10;
            f = x / 10000 % 10, g = x / 1000 % 10, h = x / 100 % 10, i = x / 10 % 10, j = x % 10;
            vis[a]++, vis[b]++, vis[c]++, vis[d]++, vis[e]++, vis[f]++, vis[g]++, vis[h]++, vis[i]++, vis[j]++;
            for(y = 0;y < 10; y++)
                if(vis[y] > 1)
                    break;
            if(y == 10)
            {
                ok = 1;
                printf("%d%d%d%d%d / %d%d%d%d%d = %d\n", a, b, c, d, e, f, g, h, i, j, n);
            }
        }
        if(ok == 0)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
