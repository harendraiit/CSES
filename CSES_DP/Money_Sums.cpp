#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main()
{
    int n;cin>>n;
    set<ll> s;
    while(n--)
    {
        int x;
        cin>>x;
        if(s.size()==0)
        {
            s.insert(x);
            continue;
        }
        vector<ll>temp;
        for(auto it=s.begin();it!=s.end();it++)
        {
            temp.push_back(*it+x);
        }
        s.insert(x);
        for(int i =0;i<temp.size();i++)
        {
            s.insert(temp[i]);
        }
    }
     cout<<s.size()<<endl;
        for(auto it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }
    
}