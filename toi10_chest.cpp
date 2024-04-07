#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=INT_MIN,cntans=0;
tuple<int,int,int,int> prime[11]={{},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},{0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0},{1,0,1,0}};//2 3 5 7
vector<tuple<int,int,tuple<int,int,int,int>>> sweep;
int cnt[5];
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        int x,s,t;
        cin>>x>>s>>t;
        sweep.emplace_back(s,x,prime[x]);
        sweep.emplace_back(t+1,-x,prime[x]);
    }
    sort(sweep.begin(),sweep.end());
    for(auto [now,value,p]:sweep)
    {
        int s,e;
        auto [two,three,five,seven]=p;
        if(value>0)
        {
            s=now;
            cnt[1]+=two;
            cnt[2]+=three;
            cnt[3]+=five;
            cnt[4]+=seven;
        }
        else
        {
            e=now; 
            int sum=(cnt[1]+1)*(cnt[2]+1)*(cnt[3]+1)*(cnt[4]+1);
            if(sum>ans)
            {
                ans=sum;
                cntans=e-s;
            }
            else if(sum==ans)
            {
                cntans+=e-s;
            }
            cnt[1]-=two;
            cnt[2]-=three;
            cnt[3]-=five;
            cnt[4]-=seven;
        }
    }
    cout<<ans<<" "<<cntans;
}