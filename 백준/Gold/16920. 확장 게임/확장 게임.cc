#include <bits/stdc++.h>
using namespace std;

typedef struct info
{
    int y, x;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int row, col, p;
int area[10];
int len[10];
char arr[1000][1000];
queue<info> q[10];

void bfs()
{
    while (1)
    {
        for (int t = 1; t <= p; t++)
        {
            int dist = len[t];
            while (!q[t].empty() && dist--)
            {
                int qs = q[t].size();
                for (int i = 0; i < qs; i++)
                {
                    int cx = q[t].front().x;
                    int cy = q[t].front().y;
                    q[t].pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < col && ny < row && arr[ny][nx] == '.')
                        {
                            arr[ny][nx] = t + '0';
                            q[t].push({ny, nx});
                            area[t]++;
                        }
                    }
                }
            }
        }
        bool finish = true;
        for (int i = 1; i <= p; i++)
        {
            if (!q[i].empty())
            {
                finish = false;
                break;
            }
        }
        if (finish)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col >> p;
    for (int i = 1; i <= p; i++)
        cin >> len[i];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
            if ('1' <= arr[i][j] && arr[i][j] <= '9')
            {
                q[arr[i][j] - '0'].push({i, j});
                area[arr[i][j] - '0']++;
            }
        }
    bfs();
    for (int i = 1; i <= p; i++)
        cout << area[i] << " ";
    return 0;
}