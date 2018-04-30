#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
    int v;
    double l, r;
}a[10];

double rs, ans;
int s;

void dfs(node *a, int len)
{
    double llx, rrx, lly, rry, l, r;
    //ֻʣ����������
    if(len == 2)
    {
        l = (a[1].v * 1.0) / (a[0].v + a[1].v);
        r = (a[0].v * 1.0) / (a[0].v + a[1].v);
        llx = max(a[0].l + l, a[1].l - r);
        rrx = max(a[1].r + r, a[0].r -l);
        //������������������λ��
        l = (a[0].v * 1.0) /(a[0].v + a[1].v);
        r = (a[1].v * 1.0) / (a[0].v + a[1].v);
        lly = max(a[1].l + l, a[0].l - r);
        rry = max(a[0].r + r, a[1].r - l);

        double ans1 = llx + rrx;
        double ans2 = lly + rry;
        if(ans < ans1 && ans1 < rs)
            ans = ans1;
        if(ans < ans2 && ans2 <rs)
            ans = ans2;
        return;
    }
    //��ȡ��ǰ�������ͽڵ�
    struct node c[10];
    for(int i = 0; i< len; i++)
        c[i] = a[i];
    //ö������׹�ϲ���һ��׹����ôÿ�ζ���ʹ��������ѡ��׹����Ŀ��һ
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(i == j)
                continue;
            l = (c[j].v * 1.0) / (c[i].v + c[j].v);
            r = (c[i].v * 1.0) / (c[i].v + c[j].v);
            llx = max(c[i].l + l, c[j].l - r);
            rrx = max(c[j].r + r, c[i].r - l);
            int tempV = c[i].v + c[j].v;
            int top = 0;
            for(int k = 0; k < len; k++)
            {
                if(k == i || k == j)
                    continue;
                a[top++] = c[k];
            }
            a[top].v = tempV;
            a[top].l = llx;
            a[top++].r = rrx;
            //�����ǰ��ɵ�������ȴ��ڷ����ȣ��ص�֮ǰ�����
            if(llx + rrx > rs)
            {
                for(int k = 0; k < len; k++)
                    a[k] = c[k];
                continue;
            }
            //���򣬽��еݹ�
            dfs(a, top);
            for(int k = 0; k < len; k++)
                a[k] = c[k];
        }
    }
}

int main()
{
    int T;
    for(scanf("%d", &T);T;T--)
    {
        scanf("%lf%d", &rs, &s); //rs ����Ŀ�ȣ�s ���ε�����
        //��ʼ���ڵ�
        for(int i = 0; i< s; i++)
        {
            scanf("%d", &a[i].v);
            a[i].l = a[i].r = 0;
        }
        //���ڵ���ֻ��һ��
        if(s == 1)
        {
            printf("%.8f\n", 0.0);
            continue;
        }
        ans = 0;
        dfs(a, s);
        ans == 0 ? puts("-1") : printf("%.16f\n", ans);
    }
    return 0;
}
