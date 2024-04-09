#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int n;
bool dp[1007][1007];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>str1>>str2;
    cin>>n;
    int len1=str1.size();
    int len2=str2.size();
    str1=" "+str1;
    str2=" "+str2;
    while(n--)
    {
        string ask;
        cin>>ask;
        ask=" "+ask;
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                if(i==0&&j==0) 
                    dp[i][j]=true;
                else if(i==0) 
                    dp[i][j]=(dp[i][j-1]&&(ask[i+j]==str2[j]));
                else if(j==0)
                    dp[i][j]=(dp[i-1][j]&&(ask[i+j]==str1[i]));
                else
                    dp[i][j]=(dp[i-1][j]&&(ask[i+j]==str1[i]))||(dp[i][j-1]&&(ask[i+j]==str2[j]));
            }
        }
        if(dp[len1][len2]) 
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}