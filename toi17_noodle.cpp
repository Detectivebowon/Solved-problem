#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
ll n,m,k,num[N];
ll mx=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    ll r=0;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        r+=num[i];
    }
    ll l=1;
    while(l<r)
    {
        ll mid=(l+r+1)/2,sum=0,cnt=0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=1;i<=n;i++)
        {
            sum+=num[i];
            pq.emplace(num[i]);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(sum>=mid&&pq.size()==k)
            {
                // cout<<sum<<"\n";
                cnt++;
                sum=0;
                while(!pq.empty())
                    pq.pop();
            }
        }
        // cout<<l<<" "<<r<<" "<<mid<<" "<<cnt<<"\n";
        if(cnt>=m)
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
        while(!pq.empty())
            pq.pop();
    }
    cout<<l;
}