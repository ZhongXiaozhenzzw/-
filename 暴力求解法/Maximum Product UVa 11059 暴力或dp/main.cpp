#include <iostream>

using namespace std;

int data[20];

int main()
{
    // dp ��������ά�������е����ֵ����Сֵ
    int n, t =1;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
            cin>> data[i];
        long long max = 0, cur_min = 0, cur_max = 0;
        for(int i = 0; i<= n; i++)
        {
            if(data[i] == 0)
            {
                cur_min = 0;
                cur_max = 0;
            }
            else if(data[i] > 0)
            {
                cur_min = cur_min * data[i];
                cur_max = cur_max * data[i];
                // �����һ��λ�����е����ֵΪ0
                if(cur_max == 0)
                    cur_max = data[i];
            }
            else if(data[i] < 0)
            {
                int temp = cur_max * data[i];
                cur_max = cur_min * data[i];
                cur_min = temp;
                // �����һ��λ�����е���СֵΪ0
                if(!cur_min)
                    cur_min = data[i];
            }
            if(max < cur_max && data[i])
                max = cur_max;
        }
        cout << "Case #" << t++ << ": The maximum product is " << max << ".\n\n";
    }
    return 0;
}
