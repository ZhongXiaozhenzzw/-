#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int maxt = 1000 + 10;
int main()
{
    int t, kase = 0;
    while(scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team;
        for(int i= 0;i<t;i++)
        {
            int n,x;
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }

        queue<int> q,q2[maxt];
        for(;;)
        {
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if(cmd[0] == 'S')
                break;
            else if(cmd[0] == 'D')
            {
                int index = q.front();
                printf("%d\n",q2[index].front());
                q2[index].pop();
                if(q2[index].empty())
                    q.pop();
            }
            else if(cmd[0] == 'E')
            {
                scanf("%d", &x);
                int index = team[x];
                if(q2[index].empty())
                    q.push(index);
                q2[index].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
