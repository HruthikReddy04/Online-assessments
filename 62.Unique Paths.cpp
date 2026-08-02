/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
using namespace std;

int unique_paths(int n , int m )
{
    if(n == 0 && m == 0)return 1;
    if(n<0 || m<0)return 0; 
    
    //recursive case 
    int up = unique_paths(n-1,m);
    int right = unique_paths(n,m-1);
    return up + right ;
}
//T.c :O(2^m+n)
//S.C :O(m+n)


int unique_paths_memoized(int n , int m , vector<vector<int>> &dp)
{
    //base case
    if(n == 0&& m == 0)
    {   dp[0][0] = 1;
        return 1;
    }
    if(n<0 || m<0)return 0 ;
    
    if(dp[n][m]!=-1)return dp[n][m] ;
    
    
    //recursive case
    int up = unique_paths_memoized(n-1,m,dp);
    int left = unique_paths_memoized(n,m-1,dp);
    
    dp[n][m] = up +left ;
    return dp[n][m];
    
}

//T.c: O(n*m)
//S.C: O(n*m)
int unique_paths_tabulation(int n,int m)
{
    vector<vector<int>> dp(n, vector<int> (m,0));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j< m ; j++)
        {
            if(i == 0 && j== 0)
            {
                dp[i][j] =1;
            }
            else
            {
                int up = 0 , left = 0;
                if(i>0)up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];
                dp[i][j] = left + up ;
    
            }
        }
    }
    
    return dp[n-1][m-1];
}
//T.C :O(n*m);
//T.C :O(n*m)


int unique_paths_opt_tabulation(int n , int m)
{
    vector<int> dp(m,0);
    for(int i = 0 ; i<n ; i++)
    {
        vector<int> temp(m,0);
        for(int j = 0 ; j< m ; j++)
        {
            if(i==0&& j == 0)
            {
                temp[j] = 1;
            }else
            {
                 temp[j] = temp[j-1]+dp[j];
            }
        }
        dp = temp;
    }
    return dp[m-1];
}
//T.C : O(n*m)
//S.C : O(m)


int unique_paths_combinations(int n , int m)
{
    //To reach (n-1,m-1) from (0,0) we have to take n-1 steps down and m-1 right .
    //Here in the problem it is mentioned that we have to take only Right and Down steps so we can fill those n+m-2 with n-1 rights 
    //So we have n+m-2 C n-1 combinations 
    //Q:Why not permuations bcz all right steps are same so no arrangement among them whose value is n-1
    //We have to calculate atmost  3 diff factorial values where there is some redundancy is three instead we calculated 
    double result = 1;
    int N = n+m-2;
    int r = n-1;
    for(int i = 1; i <= r  ; i++)
    {
        result *= (N-r+i)/i ;
    }
    return (int)result;
}
//T.C :O(n-1)
//S.C :O(1)

int main()
{
    //We are given only n,m value 
    int n = 3, m = 3;
    vector<vector<int>> dp(n ,vector<int> (m,-1));
    //cout <<unique_path_combinations(n,m);
    //cout<<unique_paths_opt_tabulation(n,m);
    //cout << unique_paths_tabulation(n,m);
   // cout << unique_paths_memoized(n-1, m-1, dp);
    cout<< unique_paths(n-1,m-1,dp);

    return 0;
}
