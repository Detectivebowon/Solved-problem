#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int H = 1e6;
int dc[H], r[H];
int k, m, n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> k >> m;
    for (int i = 1; i <= k; i++)
    {
        string str;
        int num = 0;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            num= (str[j] - '0') + (num << 1);
        }
        int idx = num%H;
        while (dc[idx] != 0)
        {
            idx=(idx+1)%H;
        }
        r[i] = num;
        dc[idx] = i;
    }

    cin >> n;
    while (n--)
    {
        int d, num = 0;
        string cc;
        bool ok = true;
        cin >> d >> cc;
        for (int i = 0; i < m-1; i++)
        {
            num= (cc[i] - '0') + (num << 1);
        }
        bool check[k+1];
        memset(check, false, sizeof(check));
        for (int i = m-1; i < d; i++)
        {
            num= (cc[i] - '0') + (num << 1);
            int idx = num%H;
            while (dc[idx]!=0)
            {
                if (num == r[dc[idx]])
                {
                    check[dc[idx]] = true;
                    ok = false;
                    break;
                }
                idx=(idx+1)%H;
            }
            num-=(num & (1 << (m-1)));
        }
        if (ok)
        {
            cout << "OK\n";
        }
        else
        {
            for (int i = 1; i <= k; i++)
            {
                if (check[i])
                {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
