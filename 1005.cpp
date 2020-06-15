#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1000000;
struct node
{
    int fx, fy;
};

int main()
{
    int n, m, x, y;
    while (cin >> n >> m >> x >> y)
    {
        int bfs[10][10];
        bool fu[10][10];
        int time[10][10];
        for(int i=0;i<n;i++)
            for (int j = 0; j < m; j++)
            {
                cin >> bfs[i][j];
                time[i][j] = INF;
                fu[i][j] = false;
            }
        int dir[4][2] = { 1,0,0,-1,-1,0,0,1 };
        node temp; 
        temp.fx = x; 
        temp.fy = y;
        queue<node> que;
        que.push(temp); 
        int all = 0;
        fu[temp.fx][temp.fy] = true;
        time[x][y] = bfs[x][y];
        while (!que.empty())
        {
            temp = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int zx = temp.fx + dir[i][0];
                int zy = temp.fy + dir[i][1];
                
                if (zx >= 0 && zx < n&&zy >= 0 && zy < m)
                {
                    time[zx][zy] =min(time[zx][zy], bfs[zx][zy] + time[temp.fx][temp.fy]);
                   
                    if (!fu[zx][zy])
                    {
                       
                        node t; t.fx = zx; t.fy = zy;
                        que.push(t);
                        fu[zx][zy] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                all = max(all, time[i][j]);
        cout << all << endl;
    }
    return 0;
}
