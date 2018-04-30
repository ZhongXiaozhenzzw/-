#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int ROW = 10000 + 10;

map<string, int> IDcache;
vector<string> Stringcache;
vector<int> text[ROW];


struct node
{
    int x,y;
    node(int x, int y):x(x),y(y){ }
    bool operator < (const node& r) const { return x<r.x || x==r.x&&y<r.y; }
};

map<node,int> data;

int ID(string s)
{
    if(IDcache.count(s))
        return IDcache[s];
    Stringcache.push_back(s);
    return IDcache[s] = Stringcache.size() -1;
}

void read(int& n)
{
    string str;
    char ch = getchar();
    for(int i = 0;i<n;i++)
    {
        for(;;)
        {
            ch = getchar();
            if(ch == '\n' ||ch == '\r')
            {
                if(!str.empty())
                    text[i].push_back(ID(str));
                str.clear();
                break;
            }
            if(ch != ',')
                str +=ch;
            else
            {
                text[i].push_back(ID(str));
                str.clear();
            }
        }
    }
}

int n,m;

void solve()
{
     for(int c1 = 0;c1<m;c1++)
        {
            for(int c2 = c1 + 1;c2<m;c2++)
            {
                data.clear();
                for(int i = 0;i<n;i++)
                {
                    int x = text[i][c1];
                    int y = text[i][c2];
                    node p(x, y);
                    if(!data.count(p))
                        data[p] = i;
                    else
                    {
                        cout<<"NO"<<endl;
                        cout<<data[p] + 1 << " " << i + 1<<endl;
                        cout<< c1 + 1 << " " << c2 + 1<<endl;
                        return;
                    }
                }
            }
        }
        cout<<"YES"<<endl;
}

int main()
{

    while(cin>>n>>m)
    {
        read(n);
        solve();
        for(int i = 0;i<n;i++)
            text[i].clear();
        IDcache.clear();
        Stringcache.clear();
    }
    return 0;
}
