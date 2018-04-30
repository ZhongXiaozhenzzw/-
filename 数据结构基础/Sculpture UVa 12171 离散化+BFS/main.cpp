#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 105;
const int maxr = 1005;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct Point{
    int x,y,z;
    Point(int x, int y, int z):x(x),y(y),z(z){ }
    Point(){ }
};

Point p[maxn];
int x[maxn], y[maxn], z[maxn]; //��ɢ�����������
int a[maxn][maxn][maxn]; //��ɢ����ϵ
int vis[maxn][maxn][maxn]; //����Ƿ����
int n, nx, ny, nz; //�������Լ���ɢ����ĳ���
int v, s;

void input(); //����
void build(); //�����
void bfs(); //������ v �� s
int getArea(int tx, int ty, int tz, int dir); //����tx,ty,tz��������dir�����ϵ������������Ӵ��������


int main()
{
    int T;
    cin>> T;
    while(T--)
    {
        input();
        build();
        bfs();
        cout<< s << " "<< v <<endl;
    }
    return 0;
}

void input()
{
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    v = 0, s = 0;
    cin >> n;
    for(int i=1;i<=2 *n;i+=2)
    {
        cin>>p[i].x>>p[i].y>>p[i].z;
        cin>>p[i+1].x >> p[i+1].y >> p[i+1].z;
        p[i+1].x+=p[i].x;
        p[i+1].y+=p[i].y;
        p[i+1].z+=p[i].z;
        x[i]=p[i].x; y[i]=p[i].y; z[i]=p[i].z;
        x[i+1]=p[i+1].x; y[i+1]=p[i+1].y; z[i+1]=p[i+1].z;
    }
    x[0]=0; y[0]=0; z[0]=0;
    //��������������ȥ�أ��õ���ɢ����
    sort(x, x + 2*n + 1);
    sort(y, y + 2*n + 1);
    sort(z, z + 2*n + 1);
    nx = unique(x, x + 2*n +1) - x;
    ny = unique(y, y + 2*n +1) - y;
    nz = unique(z, z + 2*n + 1) - z;
    //����ΧΧ�Ͽ���
    x[nx++] = maxr; y[ny++] = maxr; z[nz++] = maxr;
}

void build()
{
    for(int i = 1;i<=2*n;i++)
    {
        int x1,x2,y1,y2,z1,z2;
        x1 = lower_bound(x, x+nx, p[i].x) - x;
        x2 = lower_bound(x, x + nx, p[i+1].x) - x;
        y1 = lower_bound(y, y + ny, p[i].y) - y;
        y2 = lower_bound(y, y+ny, p[i+1].y) - y;
        z1 = lower_bound(z, z+nz, p[i].z) - z;
        z2 = lower_bound(z, z+nz, p[i+1].z) - z;

        for(int i = x1;i<x2;i++)
            for(int j=y1;j<y2;j++)
                for(int k=z1;k<z2;k++)
                    a[i][j][k]=1;
    }
}

void bfs()
{
    queue<Point> q;
    q.push(Point(0, 0, 0));
    vis[0][0][0] = 1;

    while(!q.empty())
    {
        Point t = q.front();
        q.pop();
        if(a[t.x][t.y][t.z] == 0)
            v += (x[t.x+1] - x[t.x]) * (y[t.y + 1] - y[t.y]) * (z[t.z + 1] - z[t.z]);
        for(int i = 0;i<6;i++)
        {
            int tx,ty,tz;
            tx = t.x + dx[i];
            ty = t.y + dy[i];
            tz = t.z + dz[i];
            if(tx < 0 || ty < 0 || tz < 0 || tx >= nx - 1 || ty >= ny - 1 || tz >= nz -1)
                continue;
            if(a[tx][ty][tz] == 1)
            {
                s += getArea(tx, ty, tz, i);
            }
            else if(a[tx][ty][tz] == 0 && vis[tx][ty][tz] == 0)
            {
                q.push(Point(tx, ty, tz));
                vis[tx][ty][tz] = 1;
            }
        }
    }

    v = maxr * maxr * maxr - v;
}

int getArea(int tx, int ty, int tz, int dir)
{
    if(dx[dir] != 0)
    {
        return (y[ty + 1] - y[ty]) * (z[tz + 1] - z[tz]);
    }
    else if(dy[dir] != 0)
    {
        return (x[tx + 1] - x[tx]) * (z[tz + 1] - z[tz]);
    }
    else
    {
        return (x[tx + 1] - x[tx]) * (y[ty + 1] - y[ty]);
    }
}
