// THIS CODE IS FOR PRINTING AND FINDING THE LIS IN NLOGN TIME
// dp -> O(N2) -> O(NLOGN)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int insertedat[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>lislen;
    for(int i = 0;i<n;i++)
    {
        if(lislen.empty()||lislen.back()<arr[i])
        {
            lislen.push_back(arr[i]);
            insertedat[i] = lislen.size();
        }
        auto it = lower_bound(lislen.begin(),lislen.end(),arr[i]);
        *it = arr[i]; 
        insertedat[i] = it-lislen.begin()+1;
    }
    /* run this code to understand how actually the lis is working 
    cout<<i<<":";
    for(auto v:lislen)
    {
      cout<<v<<",";
    }
   cout<<endl;
   for(int i =0;i<n;i++)
   {
    cout<<insertedat[i]<<"";
   }
   cout<<endl;
   till this point
   */
  // this code is for printing LIS 
     vector<int>final_lis;
     int curlen = lislen.size();
     for(int i =n-1;i>=0;i--)
     {
        if(insertedat[i]==curlen)
        {
            final_lis.push_back(arr[i]);
            curlen--;
        }
     }
     reverse(final_lis.begin(),final_lis.end());
     for(auto v:final_lis)
     {
        cout<<v<<"";
     }
    cout<<lislen.size()<<endl;
     return 0;
}

   
