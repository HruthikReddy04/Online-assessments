/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<cmath>
#include <climits>
using namespace std;
//10 .Minimum path sum

//Just recursion
int min_path_sum(vector<vector<int>> &grid,int i ,int j)
{
    //base case
    if(i == 0 && j == 0)return grid[0][0];
    if(i<0|| j<0)return INT_MAX;
    
    //recursive case 
     return  grid[i][j]+ min(min_path_sum(grid ,i-1,j) ,min_path_sum(grid ,i,j-1));
    
}
//recurrence relation :  T(i,j)=T(i-1,j)+T(i,j-1)
//T.C: Upto n+m levels each call has 2 child so O(2^(n+m))
//S.C:O(n+m)

//Memoizing code 
int min_path_sum_memoized(vector<vector<int>> &grid, vector<vector<int>> &dp , int i , int j )
{
     //base case
    if(i == 0 && j == 0)return grid[0][0];
    if(i<0|| j<0)return INT_MAX;
    
    if(dp[i][j]!=-1)return dp[i][j];
    
    //recursive case 
     
     dp[i][j] = grid[i][j]+ min(min_path_sum(grid ,i-1,j) ,min_path_sum(grid ,i,j-1));
     return dp[i][j];
    
}
//T.C:O(n*m)
//S.C:O(n*m)

//Tabulation
int min_path_sum_tabulation(vector<vector<int>> &grid , int n , int m)
{
    vector<vector<int>> dp(n, vector<int> (m,0));
    for(int i = 0 ; i< n ;i++)
    {
        for(int j = 0 ; j< m ; j++)
        {
            if(i== 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
            }
            else
            {
                int left = INT_MAX , up = INT_MAX;
                if(j>0)left = dp[i][j-1];
                if(i>0)up = dp[i-1][j];
                dp[i][j] = grid[i][j] + min(left , up);
            }
            
        }
    }
    return dp[n-1][m-1];
    
    
}

//T.C:O(n*m)
//S.C:O(n*m)
//Here stack space is removed 


int min_path_sum_opt_tabulation()
{
    
}

int main()
{
    vector<vector<int>> grid = { {5,9,6},{11,5,2}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m,-1));
    //cout << min_path_sum(grid ,grid.size()-1,grid[0].size()-1);
    //cout<<min_path_sum_memoized(grid ,dp, n-1,m-1);
    //cout<<min_path_sum_tabulation(grid , n,m);
   

    return 0;
}
