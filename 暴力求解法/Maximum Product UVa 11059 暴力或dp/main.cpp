#include <iostream>

using namespace std;

int data[20];

int main()
{
    // dp 的做法：维护序列中的最大值和最小值
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
                // 如果上一个位置序列的最大值为0
                if(cur_max == 0)
                    cur_max = data[i];
            }
            else if(data[i] < 0)
            {
                int temp = cur_max * data[i];
                cur_max = cur_min * data[i];
                cur_min = temp;
                // 如果上一个位置序列的最小值为0
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
