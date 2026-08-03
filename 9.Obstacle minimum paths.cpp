/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector> 
using namespace std;
//9.Unique paths 

//memoized 
int unique_paths_memozied(vector<vector<int>> &grid,int n , int m ,vector<vector<int>> &dp)
{
    if(n<0 ||m<0 || grid[n][m] == -1 )return 0;
    if(n == 0 && m == 0) return 1;
    if(dp[n][m]!=-1)return dp[n][m];
    
    int left = unique_paths_memozied(grid ,n-1,m,dp);
    int up = unique_paths_memozied(grid ,n,m-1,dp);
    dp[n][m] = left +up ;
    return dp[n][m] ;
}
//T.c - O(n*m)
//S.c - O(n*m)

//space optimized tabulation
int  unique_paths_tabulation(vector<vector<int>> &grid,int n , int m)
{
    vector<int> dp(m+1,0);
    for(int i = 0 ; i<= n ;i++)
    {
        vector<int> temp(m+1 , 0);
        for(int j = 0 ; j<= m ;j++)
        {
            if(i == 0 && j == 0)
            {
                temp[j]= 1;
            }else if (grid[i][j] == -1)
            {
                temp[j] = 0;
            }else
            {
                int left = 0 ,up = 0 ;
                if(i>0)up = dp[j];
                if(j>0)left = temp[j-1];
                temp[j] = up + left ;
            }
        }
        dp = temp;
    }
    return dp[m];
}

int main()
{  
  vector<vector<int>> grid = {{0,0,0},{0,-1,0},{0,0,0}};
  int n = 3, m = 3;
//   vector<vector<int>> dp(n,vector<int> (m,-1));
//   cout << unique_paths(grid ,n-1,m-1,dp);
  cout<< unique_paths_tabulation(grid, n-1, m-1);
  
    return 0;
}
