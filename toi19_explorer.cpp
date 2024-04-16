#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9 +7;
int n,fac[500007],child[500007],ans=1;
signed main()
{
    fac[1]=1,fac[0]=1;
    for(int i=2;i<=5e5;i++)
        fac[i]=(i*fac[i-1])%mod;
    cin>>n;
    memset(child,-1,sizeof(child));
    for(int i=1;i<=(2*n-1);i++)
    {
        int tmp;
        cin>>tmp;
        child[tmp]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(child[i]==-1) continue;
        ans=(ans*fac[child[i]])%mod;
    }
    cout<<ans;
}