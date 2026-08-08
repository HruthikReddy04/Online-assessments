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
//Min  sum in a triangle 
//Memoized
int min_sum_memoized(vector<vector<int>> grid,vector<vector<int>> dp ,int i,int j ,int n)
{
    //base case
    if(i == n-1)return grid[i][j];
    //dp
    if(dp[i][j]!=-1)return dp[i][j];
    
    //recursive case 
    int down =grid[i][j] +  min_sum_memoized(grid,dp, i+1 ,j ,n);
    int diag = grid[i][j] + min_sum_memoized(grid , dp,i+1 , j+1, n );
    dp[i][j] = min(down ,diag);
    return dp[i][j];
}

//Tabulation
int min_sum_tabulation(vector<vector<int>> grid)
{
    int n = grid.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    
    for(int j = 0 ; j < n ; j++)
    {
        dp[n-1][j] = grid[n-1][j];
    }
    
    for(int i = n-2 ; i>=0 ; i--)
    {
        for(int j = i ; j >=0 ; j--)
        {
            int down = grid[i][j] + dp[i+1][j] ;
            int diag = grid[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down ,diag) ;   
        }
    }
    
    return dp[0][0];
}

//Space Optimized tabulation
int min_sum_opt_tabulation(vector<vector<int>> grid)
{
    int n = grid.size();
    vector<int> dp(n,0);
    vector<int> temp(n,0);
    
    for(int j = 0 ; j < n ; j++)
    {
        dp[j] = grid[n-1][j];
    }
    
    for(int i = n-2 ; i>=0 ; i--)
    {
        
        for(int j = i ; j >=0 ; j--)
        {
            int down = grid[i][j] + dp[j] ;
            int diag = grid[i][j] + dp[j+1];
            temp[j]=min(down ,diag) ;   
        }
        dp = temp ;
    }
    
    return dp[0];
}

int main()
{
    
    vector<vector<int>> grid = {{1}, {2,8} , {3,4,5} , {1,7,8,9}};
    vector<vector<int>> dp (grid.size(),vector<int> (grid.size(),-1));
//cout << min_sum_memoized(grid,dp, 0, 0 , grid.size());
    cout<< min_sum_opt_tabulation(grid);

    return 0;
}
