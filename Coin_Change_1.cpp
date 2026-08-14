#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
//Coin change

//we are given a denomination and we have infinite suplly of coins try to give change for target using minimum coins 
//First type of problem
//looks like unbounded 
//if we can sort the coins we can give change using max coins and next and next ,what case fails here is globally it can't give min coins
//{1,3,4}  target = 6 using greedy denomination is 4,1,1 but it won't find 3,3 case 
//best choice we took at a moment leads to bad choice of min coins here 

vector<int> nums =  {1,3,4};
//so look out all possible cases using recursion 


//doubt : Why we are returning O at i == n 
int solve(int target,int i)
{
    //base case 
    if(target == 0  )
    {
        return 0;
    }
    if(i == nums.size())
    {
        return 1e5;
    }
    
    //recursive cases
   int not_take = solve(target,i+1);
   int take = 1e5 ;
    if(nums[i]<=target)
    {
        take  = 1+solve(target-nums[i],i);
    }
    
    return min(take,not_take);
}

//Time complexity : O(we have 2 choices for every value = 2^x)
//x = target /least value 
//Space : O(target/least value);

//MY problem is how base cases are different from subset sum problem
//in subset sum we have a traget we need to find we have soltion or not so we ask the smaller problem if t=0
//we  found solution whereever it is end or middle but if we reach end without target = 0 means no way we found means
//if(target == 0)return true;
//if(i == n)return false; 

//In subset sum we are concerned with only true or false but here we need count of counts 
//so if we found target. = 0 we need o coins but if target not equal 0 at end means no way we find => we need to return 
//impossible so 1e5(max)

//recursive case is same take or not take 
//in subset sum we have we need to return only true or false so so we need atleast 1 true so take || not_take
//here we are concerned with counting so we add 1 to every take call

int solve_memo(vector<vector<int>> &dp , int target ,int i)
{
    //base case 
    if(target == 0  )
    {
        dp[i][target] = 0 ;
        return 0;
    }
    if(i == nums.size())
    {
        return 1e5;
    }
    
    if(dp[i][target]!=-1)return dp[i][target] ;
    //recursive cases
   int not_take = solve_memo(dp,target,i+1);
   int take = 1e5 ;
    if(nums[i]<=target)
    {
        take  = 1+solve_memo(dp,target-nums[i],i);
    }
    
    dp[i][target] = min(take,not_take);
    return dp[i][target] ;
}
//T.C:O(n*target)
//S.C:O(n*target)

//tabulation
int solve_tab(int target)
{
    int n = nums.size();
    //vector<vector<int>> dp(n , vector<int> (target+1 , 0));
    int dp[n+1][target+1];
    
    
    for(int i = 0 ; i<=n; i++)
    {
        for(int j = 0 ; j<= target ; j++)
        {
            if(j == 0)
            {
                dp[i][j] = 0;
            }else if(i == 0)
            {
                dp[i][j] = 1e5;
            }else if(nums[i-1]>target)
            {
                dp[i][j] = dp[i-1][j];
            }else
            {
                dp[i][j] = min(1+dp[i][j-nums[i-1]],dp[i-1][j]);
            }
        }
    }
    
    return dp[n][target]>1e4 ? -1:dp[n][target] ;
}

int main()
{
    int n = nums.size();
    int target =4 ; 
    vector<vector<int>> dp(n , vector<int> (target+1, -1));
    //cout<<solve(10,0);
    //cout<<solve_memo(dp, target ,0);
    cout << solve_tab(4);
}
