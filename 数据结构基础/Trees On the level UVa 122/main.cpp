#include<cstdio>
#include<cstring>

const int maxn=20;
bool s[1<<maxn]; //����
int main()
{
    int D,I;
   /* while(scanf("%d%d",&D,&I)==2)
    {
        memset(s,false,sizeof(s));
        int k,n=(1<<D)-1;
        for(int i=0;i<I;i++) //������I��С������
        {
            k=1;
            for(;;)
            {
                int temp=k;
                if(s[k]) //���ݿ���ת̨ѡ�����䷽��
                    k=2*k+1;
                else
                    k=2*k;
                if(k>n) //�Ѿ��䡰���硱�ˣ�����ѭ��
                    break;
                s[temp]=!s[temp];
            }
        }
        printf("%d\n",k/2); //��������硱ǰ��Ҷ�ӱ��
    }*/

    //�Ż���
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
