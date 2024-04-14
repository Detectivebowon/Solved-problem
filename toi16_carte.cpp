#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
int saka,K,n,od[401],dp[401][401],cnt[401][401],ans=INT_MIN;
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>saka>>K;
    while(saka--)
    {
        cin>>n;
        memset(dp,0x3f,sizeof(dp));
        memset(cnt,0x3f,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=1;
            cnt[i][i]=1;
        }
        for(int i=1;i<=n;i++)
            cin>>od[i];
        for(int len=2;len<=n;len++)
        {
            for(int l=1,r=len;r<=n;l++,r++)
            {
                int diff=0,newcnt;
                for(int k=l;k<r;k++)    
                {
                    if(od[l]==od[r]&&cnt[l][k]+cnt[k+1][r]<=K)
                    {
                        diff=-1;
                        newcnt=cnt[l][k]+cnt[k+1][r];
                    }
                    else
                    {
                        newcnt=1;
                    }
                    if(dp[l][r]>=dp[l][k]+dp[k+1][r]+diff)
                    {
                        dp[l][r]=dp[l][k]+dp[k+1][r]+diff;
                        cnt[l][r]=min(cnt[l][r],newcnt);
                    }
                }
            }
        }
        ans=max(ans,dp[1][n]);
        // cout<<dp[1][n]<<"\n";
    }
    cout<<ans;
}