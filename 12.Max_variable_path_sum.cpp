/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector> 
#include<cmath>
#include<climits>
using namespace std;
//12.Variable start and ending 

//top-down approach
//LEt's try to solve this problem using convetional approach





//Memo
int f_memo(vector<vector<int>> grid , vector<vector<int>> dp, int i , int j)
{
    //base case 
    if(i == 0 )
    {   
        dp[0][j] = grid[i][j];
        return grid[i][j];
    }
    if(i<0 || j<0)return INT_MIN;
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
     //recursive case 
     int maxi = INT_MIN;
     for(int k = -1 ; k<2; k++)
     {
         maxi = max(maxi, f_memo(grid ,dp, i-1,j+k));
     }
      dp[i][j] = grid[i][j]+ maxi;
      return dp[i][j];
}

int max_sum_grid(vector<vector<int>> grid,vector<vector<int>> dp)
{
    int maxi = INT_MIN;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0 ; i < m ; i++)
    {
        maxi = max(maxi,f_memo(grid,dp,n-1,i));
    }
    return maxi;
}

//Tabulation
int max_sum_grid_tab(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    //we need a base
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0 ; i<m ; i++)
    {
        dp[0][i] = grid[0][i] ;
    }
    
    for(int i = 1; i< n ; i++)
    {
        for(int j = 0 ; i< m ;j++)
        {
            int maxi = INT_MIN;
            for(int k = -1 ; k<2; k++)
            {
                int v = (j>0 || j<m-1)?dp[i-1][j+k]:0;
                maxi = max(maxi,v);
            }
            
            dp[i][j] =grid[i][j] + maxi;
        }
    }
    int maxi = INT_MIN;
    for(int i = 0 ; i < m;i++)
    {
        maxi = max(maxi,dp[n-1][i]);
    }
    return maxi;
}


int main()
{
    
   vector<vector<int>> grid = {{1,2,3,4} , { 40,6,7,10} , {500, 3,1,2}};
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> dp(n,vector<int> (m,-1));
   cout << max_sum_grid_tab(grid);
    return 0;
}
