#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 20;
bool prime[maxn * 2];
int num[maxn];
int vis[maxn];
int n;
int kase = 1;
int ok;
void prime_Deal()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for(int i = 2; i <= maxn;i++)
        //if(prime[i])
            for(int j = i+1;j<=maxn * 2;j++)
                if(j % i == 0)
                    prime[j] = false;
}

void dfs(int u)
{
    if(u == n && prime[num[1]+ num[n]])
    {
        for(int i = 1;i<= n;i++)
        {
            if(i>1)
                cout<< " " << num[i];
            else
                cout<<num[i];
        }
        cout<<endl;
    }
    else
        for(int i = 2;i<=n;i++)
        {
            if(!vis[i] && prime[num[u] + i])
            {
                vis[i] = 1;
                num[u + 1] = i;
                dfs(u + 1);
                vis[i] = 0;
            }
        }
}

int main()
{
    prime_Deal();
    ok = 1;
    while(cin >> n)
    {
        memset(num, 0, sizeof(num));
        memset(vis, 0, sizeof(vis));
        if(ok == 1)
            ok = 0;
        else
            cout << endl;
        cout << "Case "<< kase++ << ":" << endl;
        vis[1] = 1;
        num[1] = 1;
        dfs(1);
    }
    return 0;
}
