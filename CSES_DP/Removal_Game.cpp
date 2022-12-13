#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    for(int len =1;len<=n;len++)
    {
        for(int i=0;i+len<=n;i++)
        {
            int j = i+len-1;
            ll x,y,z;
            x = (i+2<=j)?dp[i+2][j]:0;
            y = (i+1<=j-1)?dp[i+1][j-1]:0;
            z = (i<=j-2)?dp[i][j-2]:0;
            dp[i][j] = max(arr[i]+min(x,y),arr[j]+min(y,z));
        }
    }
    cout<<dp[0][n-1];
    return 0;
}