#include<bits/stdc++.h>
# define mod 1000000007
# define ll long long
using namespace std;
int main()
{
    ll n,x;
    cin>>n>>x;
    ll coins[n];
    vector<ll>dp(x+1,0);
    for(int i =0;i<n;i++)
    {
        cin>>coins[i];
    }
    dp[0] =1;
    for(int i =1;i<=x;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i<coins[j]) continue;
          dp[i] = (dp[i]+dp[i-coins[j]])%mod;
        }
    }
    cout<<dp[x]%mod<<endl;
    return 0;
}