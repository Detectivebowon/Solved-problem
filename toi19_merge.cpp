#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int n,m,q,x[N],y[N],s[N],t[N],a,b,k;
signed main()
{
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]; s[i]+=s[i-1];
    }
    for(int i=0;i<m;i++)
    {
        cin>>y[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t[i]; t[i]+=t[i-1];
    }
    while(q--)
    {
        cin>>a>>b>>k;
        int l=-1e9,r=1e9;
        while(l<r)
        {
            int mid=(l+r)>>1;
            // cout<<l<<" "<<r<<" "<<mid<<"\n";
            int xva=s[upper_bound(x,x+n,mid)-x];
            int yva=t[upper_bound(y,y+m,(mid-b)/a)-y];
            if(xva+yva<k)
                l=mid+1;
            else
            {
                r=mid;
            }
        }
        cout<<l<<"\n";
    }
}