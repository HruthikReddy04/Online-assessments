// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> si = { 1,2,3,4,5};
vector<int> price = { 1,100,8,9,10};
int solve(int rodSize,vector<int> &dp)
{
    //base case 
    if(rodSize == 0 )return 0;
    //out of bound 
    if(rodSize<0)return -1e5;

    if(dp[rodSize]!=-1)return dp[rodSize];

    int ans  = -1e5;
    for(int i = 0 ; i< si.size(); i++)
    {
      ans = max(ans, price[i] + solve(rodSize-si[i],dp));
    }
    return ans;
}

//Writing tabulation and base cases in recursion is difficult
int tabulation(int t)
{
   vector<int> dp(t+1,0);
   for(int i =1; i <= t ; i++)
   {
      for(int j = 0 ; j<si.size(); j++)
      {
        dp[i] = max(dp[i],dp[i-si[j]]+price[j]);
      }
   }
   return dp[t];
}
int main() {
    //We need to pump just max value not the steps we have taken
    int t= 5;
    vector<int>dp(t+1,-1);
    dp[0]=0;
   // cout << solve(5,dp);
   cout << tabulation(t);
   

    return 0;
}
