#include<bits/stdc++.h>
using namespace std;
const int N=2e5 +7;
int n,q,h[N],l[N],r[N];
void llis()
{
    vector<int> vec;
    vec.clear();
    for(int i=1;i<=n;i++)
    {
        auto it=lower_bound(vec.begin(),vec.end(),h[i]);
        if(it==vec.end())
        {
            l[i]=vec.size();
            vec.emplace_back(h[i]);
        }
        else
        {
            l[i]=it-vec.begin();
            *it=h[i];
        }
    }
}
void rlis()
{
    vector<int> vec;
    vec.clear();
    for(int i=n;i>=1;i--)
    {
        auto it=lower_bound(vec.begin(),vec.end(),h[i]);
        if(it==vec.end())
        {
            r[i]=vec.size();
            vec.emplace_back(h[i]);
        }
        else
        {
            r[i]=it-vec.begin();
            *it=h[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    llis();
    rlis();
    for(int i=1;i<=q;i++)   
    {
        int idx;
        cin>>idx;
        cout<<min(l[idx+1],r[idx+1])<<"\n";
    }
}