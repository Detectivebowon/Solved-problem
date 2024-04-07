#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +7;
int n,t,tree[N],ans=0;
vector<tuple<int,int,int>> sweep;
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
void update(int idx,int val)
{
    while(idx<=N)
    {
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}
int findidx(int t)
{
    int l=1,r=N;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(read(mid)>t)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>t;
    while(n--)
    {
        int s,h,w,o;
        cin>>s>>h>>w>>o;
        sweep.emplace_back(s,h,o);
        sweep.emplace_back(s+w,h,-o);
    }
    sort(sweep.begin(),sweep.end());
    int now=0,pre=0,s=0;
    for(auto [now,h,o]:sweep)
    {
        int e=now;
        int idxupper=findidx(t-1);
        int idxlower=findidx(t);
        int high=idxupper-idxlower;
        int w=e-s;
        ans+=high*w;
        s=now;
        update(1,o);
        update(h+1,-o);
    }
    cout<<ans;
}