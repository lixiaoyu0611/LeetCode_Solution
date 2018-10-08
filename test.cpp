#include<iostream>
using namespace std;
const int MAX = 501;
int road[MAX][MAX];
int rescue[MAX];
bool visit[501] = {false};
int n,m;
int starting,ending;
int len[MAX];
int main()
{
    cin >> n >> m >> starting >> ending;
    for (int i = 0; i < n; i++)
        cin >> rescue[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                road[i][j] = 0;
            else
                road[i][j] = MAX;
        }
    }
    for (int i = 0; i < n; i++)
        len[i] = MAX;
    int c1,c2;
    for (int i = 0; i < m; i++)
    {
        cin >> c1 >> c2;
        cin >> road[c1][c2];
        road[c2][c1] = road[c1][c2];
        if (c1 == starting)
            len[c2] = road[c1][c2];
        if (c2 == starting)
            len[c1] = road[c1][c2];
    }
    int MIN,index;
    int dis[MAX] = {0};
    dis[starting] = 1;
    len[starting] = 0;
    int maxrecure[MAX] = {0};
    maxrecure[starting] = rescue[starting];

    while(1)
    {
        MIN = MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i] && len[i] < MIN)
            {
                MIN = len[i];
                index = i;
            }
        }

        visit[index] = true;

        for (int i = 0; i < n; i++)
        {
            if (!visit[i] && road[index][i] != MAX && MIN + road[index][i] < len[i])
            {
                len[i] = MIN + road[index][i];
                dis[i] = dis[index];
                maxrecure[i] = maxrecure[index] + rescue[i];
            }
            else if (!visit[i] && road[index][i] != MAX &&  MIN + road[index][i] == len[i])
            {
                dis[i] += dis[index];
                maxrecure[i] = max(maxrecure[i], maxrecure[index] + rescue[i]);
            }
        }
        if (index == ending)
            break;
    }
    cout<<dis[ending]<<" "<<maxrecure[ending];
}
