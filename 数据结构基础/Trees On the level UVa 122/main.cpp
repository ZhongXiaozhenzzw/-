#include<cstdio>
#include<cstring>

const int maxn=20;
bool s[1<<maxn]; //开关
int main()
{
    int D,I;
   /* while(scanf("%d%d",&D,&I)==2)
    {
        memset(s,false,sizeof(s));
        int k,n=(1<<D)-1;
        for(int i=0;i<I;i++) //连续让I个小球下落
        {
            k=1;
            for(;;)
            {
                int temp=k;
                if(s[k]) //根据开关转台选择下落方向
                    k=2*k+1;
                else
                    k=2*k;
                if(k>n) //已经落“出界”了，跳出循环
                    break;
                s[temp]=!s[temp];
            }
        }
        printf("%d\n",k/2); //输出“出界”前的叶子编号
    }*/

    //优化：
    while(scanf("%d%d",&D,&I)==2)
    {
        int k=1;
        for(int i=0;i<D-1;i++)
        {
            if(I%2)
            {
                k=k*2;
                I=(I+2)/2;
            }
            else
            {
                k=k*2+1;
                I=I/2;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
