/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
Rodcutting 
vector<int> si= {1,2,3,4};
//vector<int> nums = {1,5,8,9};
int max_price(int t)
{
    if(t == 0)
    {
        return 0;
    }
    
    
    int ans = -1e5;
    for(int i = 0; i< nums.size(); i++)
    {
        if(si[i]<=t)
        {
            int val =nums[i] + max_price(t-si[i]);
            ans = max(ans ,val);
        }
       
    }
    
    return ans;
}

//still confusion about base cases 

//Doubt there are 3 changing values .should we use 3d dp?
vector<int> nums = {1,1,4,2,3};
int min_op(int l, int r,int sum,vector<vector<int>> &dp)
{
    if(sum == 0)
    {
        return 0 ;
    }
    
    if(dp[l][r]!=-1)return dp[l][r] ;
    // if(l>=r )
    // {
    //   return (sum == nums[l]) ? 1:1e5;
    // }
    int left = 1e5;
    int right =1e5;
    if(sum>= nums[l])left = 1+ min_op(l+1,r,sum-nums[l],dp);
    if(sum>= nums[r])right = 1+min_op(l,r-1,sum-nums[r],dp);
    dp[l][r] =  min(left ,right)
    return min(left ,right) ;
}

int main()
{
    //cout<<max_price(4);
    vector<vector<int>> dp ()
  cout<<min_op(0,nums.size()-1,5,dp);
    return 0;
}
