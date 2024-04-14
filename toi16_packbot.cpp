#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> op,va;
double mp[4]={0,0.04,0.08,0.16};
void fvalue()
{
    int a=va.top(); va.pop();
    int b=va.top(); va.pop();
    va.emplace((a+b)+mp[op.top()]*(a+b));
    op.pop();
}
int main()
{
    cin>>s;
    s=" "+s;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='[')
        {
            op.emplace(0);
        }
        else if(s[i]==']')
        {
            while(!op.empty()&&op.top()!=0)
                fvalue();
            op.pop();
        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            va.emplace(20);
        }
        else
        {
            while(!op.empty()&&op.top()>=s[i]-'0')
                fvalue();
            op.emplace(s[i]-'0');
        }
    }
    while(!op.empty())
        fvalue();
    cout<<va.top();
}