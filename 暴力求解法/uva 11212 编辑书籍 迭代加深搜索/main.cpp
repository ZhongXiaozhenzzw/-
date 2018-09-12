#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, books[10];

//�ж��Ƿ�˳����ȷ
bool judge()
{
    for(int i = 0; i < n; i++)
    {
        if(books[i] != i + 1)
            return false;
    }
    return true;
}

//�������˳��ĸ���
int h()
{
    int num = 0;
    for(int i = 0; i < n - 1; i++)
        if(books[i] + 1 != books[i+ 1])
            num++;
    if(books[n - 1] != n)
        num++;
    return num;
}

bool dfs(int d, int maxd)
{
    if(d == maxd)
        return judge();

    if(3 * d + h() > 3 *maxd)
        return false;

    int old_books[10], paste[10];
    //ö�ٺͼ����Ķ�
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            memcpy(old_books, books, sizeof(books));

            //��ȡ���а�
            int cnt = 0;
            for(int k = 0; k < n; k++)
            {
                if(k < i || k > j)
                {
                    paste[cnt++] = books[k];
                }
            }

            //�ڼ��а���ѡ��λ�ý����Ķβ���
            for(int k = 0; k <= cnt; k++)
            {
                int cnt2 = 0;
                for(int p = 0; p < k; p++)
                    books[cnt2++] = paste[p];

                for(int p = i; p <= j; p++)
                    books[cnt2++] = old_books[p];

                for(int p = k; p < cnt; p++)
                    books[cnt2++] = paste[p];

                if(dfs(d + 1, maxd))
                    return true;
                memcpy(books, old_books, sizeof(old_books));
            }
        }
    }
    return false;
}

int main()
{
    int kase = 0;
    while(scanf("%d", &n) && n)
    {
        memset(books, 0, sizeof(books));
        for(int i = 0; i < n; i++)
            scanf("%d", &books[i]);

        //IDA
        int step = 0;
        for(int i = 0; i < 9; i++)
            if(dfs(0, i))
            {
                step = i;
                break;
            }
        cout << "Case " << ++kase << ": " << step <<endl;
    }
    return 0;
}
