/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int helper(vector<int> nums,int i, int target , int count ,vector<vector<int>> dp)
{
    if(target == 0)
    {
        dp[i][0] = count; 
        return count ;
    }
    if(i == 0)
    {
        if(target == nums[0])
        {
            dp[0][target] = count+1;
            return count+1;
        }else
        {
            dp[0][target] = 1e8;
            return 1e8;
        }
    }
    if(dp[i][target]!=-1)return dp[i][target];
    
    int not_take = helper(nums,i-1, target , count,dp);
    int take = 1e8;
    if(target>=nums[i])
    {
         take= helper(nums , i-1 , target - nums[i], count+1,dp);
    }
    
    dp[i][target] = min(take,not_take);
    return dp[i][target] ;
}

int main()
{
    // printf("Hello World");
    vector<int> nums= { 1,1,1};
    int n = nums.size();
    int t= 4;
    vector<vector<int>> dp(n, vector<int> (t , -1));
    int v = helper(nums,n-1,t,0,dp);
   if( v == 1e8)
   {
       cout << "-1";
   }else
   {
       cout << v;
   }
    //Find minimum subsequence size 

    return 0;
}
