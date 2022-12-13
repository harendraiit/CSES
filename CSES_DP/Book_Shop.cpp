#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    int prices[n],pages[n];
    for(int i =1;i<=n;i++)
    {
          cin>>prices[i];
    }
    for(int i =1;i<=n;i++)
    {
          cin>>pages[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i = 1;i<=n;i++)
    {
       for(int j =1;j<=w;j++)
       {
           if(j<prices[i]) //continue;
          dp[i][j] = dp[i-1][j];
           else
           dp[i][j] = max(dp[i-1][j],dp[i-1][j-prices[i]]+pages[i]);
       }
    }
    cout<<dp[n][w];
    return 0;
}