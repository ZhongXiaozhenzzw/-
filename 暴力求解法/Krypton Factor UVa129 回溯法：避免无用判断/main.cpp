#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int S[100];
int n, L;
int cnt;
int dfs(int cur)  //����0��ʾ�Ѿ��õ��⣬�����������
{
    if(cnt++ == n) //cnt��ʾ�ڼ������Ѵ�
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
        for(int j = 1; j * 2 <= cur + 1;j++) //���Գ���Ϊj*2�ĺ�׺
        {
            int e = 1;
            for(int k = 0; k < j; k++) //����һ���Ƿ����ǰһ��
                if(S[cur - k] != S[cur - k - j])
                {
                    e = 0;
                    break;
                }
            if(e == 1) //��һ�����ǰһ�룬�������Ϸ�
            {
                ok = 0;
                break;
            }
        }
        if(ok) //�ݹ�����������Ѿ��ҵ��⣬��ֱ���˳�
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
