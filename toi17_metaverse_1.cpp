#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define int long long
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7;
int n,m,p,t,enx[N],eny[N],ox[N],oy[N],dp[N][27],ans=INT_MAX,tk;
int dis(int j,int i)
{
    return abs(ox[j]-enx[i])+abs(oy[j]-eny[i]);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    cin>>p>>t;
    for(int i=1;i<=p;i++)
    {
        cin>>enx[i]>>eny[i]>>ox[i]>>oy[i];
    }
    ox[0]=oy[0]=1;
    enx[p+1]=n;
    eny[p+1]=m;
    for(int i=1;i<=p+1;i++)
        for(int j=1;j<=t;j++)
            dp[i][j]=1e9;
    for(int i=1;i<=p+1;i++)
        dp[i][0]=dis(0,i);
    for(int k=1;k<=t;k++)
        for(int i=1;i<=p;i++)
            for(int j=1;j<=p+1;j++)
            {
                if(i==j) continue;
                dp[j][k]=min(dp[j][k],dp[i][k-1]+dis(i,j));
            }
    // for(int i=1;i<=p+1;i++)
    //     for(int j=0;j<=t;j++)
    //         cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";      
    for(int i=0;i<=t;i++)
    {
        if(ans>dp[p+1][i])
        {
            ans=dp[p+1][i];
            tk=i;
        }
    }
    cout<<ans<<" "<<tk;
}