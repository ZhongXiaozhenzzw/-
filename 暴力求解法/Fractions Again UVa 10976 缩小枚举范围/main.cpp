#include <iostream>

using namespace std;
#define maxn 1000
int main()
{
    int k;
    int a[maxn], b[maxn];
    while(cin >> k)
    {
        int x, y;
        int t = 0;
        for(y = k + 1; y <= 2 * k; y++)
        {
            if( (k * y) % (y - k) == 0)
            {
                a[t] = (k * y) / (y - k);
                b[t] = y;
                t++;
            }
        }
        cout<< t << endl;
        for(int i = 0;i<t;i++)
            cout<< "1/" << k << " = " << "1/" << a[i] << " + " << "1/" << b[i] <<endl;
    }
    return 0;
}
