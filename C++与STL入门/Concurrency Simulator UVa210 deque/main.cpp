#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

struct Program{
    int number;
    queue<string> code;
    Program(int number): number(number){ }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, t1, t2, t3, t4, t5, q;
        int ch[30]; //����
        int toTime[130];  //������ת����ʱ��
        deque<Program> wait; //�ȴ�����
        queue<Program> stop; //��ֹ����
        bool isLock = false; //�Ƿ���lock ״̬
        memset(ch, 0, sizeof(ch));

        cin>>n>>t1>>t2>>t3>>t4>>t5>>q;
        getchar();
        toTime['='] = t1;
        toTime['i'] = t2;
        toTime['c'] = t3;
        toTime['l'] = t4;
        toTime['d'] = t5;

        //����
        for(int i = 1;i<=n;i++)
        {
            string s;
            Program program(i);
            while(1)
            {
                getline(cin, s);
                program.code.push(s);
                if(s == "end")
                    break;
            }
            wait.push_back(program);
        }

        //ģ������
        while(!wait.empty())
        {
            Program program = wait.front();
            wait.pop_front();
            int t = q;
            while(!program.code.empty())
            {
                string s = program.code.front();
                if(t < 0)
                {
                    wait.push_back(program);
                    break;
                }
                if(s[2] == 'c')
                {
                    if(isLock)
                    {
                        stop.push(program);
                        break;
                    }
                    else
                    {
                        isLock = true;
                    }
                }
                t -= toTime[s[2]];
                program.code.pop();
                if(s[2] == 'l')
                {
                    isLock = false;
                    if(!stop.empty())
                    {
                        wait.push_front(stop.front());
                        stop.pop();
                    }
                }
                if(s[2] == '=')
                {
                    char c;
                    string t;
                    int num;
                    stringstream ss(s);
                    ss >> c >> t >> num;
                    ch[c - 'a'] = num;
                }
                if(s[2] == 'i')
                {
                    cout<< program.number << ": " << ch[s[6] - 'a'] <<endl;
                }
                if(s[2] == 'd')
                    break;
            }
        }
        if(T)
            cout<<endl;

    }
    return 0;
}
