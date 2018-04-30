#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int S[100];
int n, L;
int cnt;
int dfs(int cur)  //返回0表示已经得到解，无需继续搜索
{
    if(cnt++ == n) //cnt表示第几个困难串
    {
        for(int i = 0;i< cur;i++)
        {
            if( i % 4 == 0 && i > 0)
            {
                if(i % 64 == 0 && i > 0)
                    cout<< endl;
                else
                    cout << " ";
            }
            printf("%c", 'A' + S[i]);
        }
        cout << endl << cur << endl;
        return 0;
    }
    for(int i = 0;i< L;i++)
    {
        S[cur] = i;
        int ok = 1;
        for(int j = 1; j * 2 <= cur + 1;j++) //尝试长度为j*2的后缀
        {
            int e = 1;
            for(int k = 0; k < j; k++) //检查后一半是否等于前一半
                if(S[cur - k] != S[cur - k - j])
                {
                    e = 0;
                    break;
                }
            if(e == 1) //后一半等于前一半，方案不合法
            {
                ok = 0;
                break;
            }
        }
        if(ok) //递归搜索，如果已经找到解，则直接退出
            if(!dfs(cur + 1))
                return 0;
    }
    return 1;
}

int main()
{
    while(cin >> n >> L && n && L)
    {
        cnt = 0;
        memset(S, 0, sizeof(S));
        dfs(0);

    }
    return 0;
}
