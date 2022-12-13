#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    for(int i =0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i==j) dp[i][j] = 0;
            else
            {
                for(int k =1;k<i;k++) // for vertical cuts
                dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                
                for(int k=1;k<j;k++)// for horizontal cuts
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}