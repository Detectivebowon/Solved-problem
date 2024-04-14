#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
queue<pair<int, int>> q;
bitset<2007> space[10007];
void bfs(int i, int j)
{
    int cnt = 0, xmax = i, xmin = i, ymax = j, ymin = j;
    q.push({i, j});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        space[x][y] = 0;
        cnt++;
        xmin = min(x, xmin);
        ymin = min(y, ymin);
        xmax = max(x, xmax);
        ymax = max(y, ymax);
        for (int k = -1; k <= 1; k++)
        {
            for (int l = -1; l <= 1; l++)
            {
                if (k == 0 && l == 0)
                    continue; 
                int ai = x + k;
                int aj = y + l;
                if (ai >= 1 && ai <= m && aj >= 1 && aj <= n && space[ai][aj] == 1)
                {
                    q.push({ai, aj});
                    space[ai][aj] = 0;
                }
            }
        }
    }
    if ((ymax - ymin) == (xmax - xmin))
    {
        if (cnt == (xmax - xmin + 1) * (ymax - ymin + 1))
            a++;
        else
            b++;
    }
    else
    {
        c++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char tmp;
            cin >> tmp;
            space[i][j] = tmp - '0';
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (space[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    cout << a << " " << b << " " << c;
    return 0;
}