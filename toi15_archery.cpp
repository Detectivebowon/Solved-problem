#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll h[500007],minh=LLONG_MAX,cnt1,ans,anshole,dp[500007],dph[500007];
int n;
pair<ll,ll> hole[500007];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        minh=min(minh,h[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>hole[i].first;
        hole[i].second=i;
    }
    sort(hole+1,hole+1+n);
    for(int i=2;i<=n;i++)
    {
        cnt1+=hole[i].first-hole[1].first;
    }
    for(int i=1;i<=n;i++)
    {
        dph[i]=dph[i-1]+h[hole[i].second];
    }
    ans=cnt1;
    anshole=hole[1].first;
    for(int i=2;i<=n;i++)
    {
        if(hole[i].first>minh) break;
        ll newcnt=cnt1-(n-i+1)*(hole[i].first-hole[1].first)+(i-1)*(hole[1].first)+dph[i-1]-(i-1)*(hole[i].first);
        if(ans>newcnt)
        {
            ans=newcnt;
            anshole=hole[i].first;
        }
        else if(newcnt==ans)
        {
            anshole=min(hole[i].first,anshole);
        }
    }
    cout<<anshole<<" "<<ans;
}