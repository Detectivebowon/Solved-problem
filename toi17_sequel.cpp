#include<bits/stdc++.h>
using namespace std;
const int N=1e5 +7;
int n,q,va[N],qs[340][N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>va[i];
    for(int i=1;i<=sqrt(n);i++)
        for(int j=1;j<=n;j++)
            qs[i][j]=qs[i][max(j-i,0)]+va[j];
    while(q--)
    {
        int l,m,r;
        cin>>l>>m>>r;
        if(m>=sqrt(n))
        {
            int sum=0;
            for(int i=l;i<=r;i+=m)
                sum+=va[i];
            cout<<sum<<" ";
        }
        else
        {
            cout<<qs[m][l+(r-l)/m*m]-qs[m][max(l-m,0)]<<" ";
        }
    }
}
