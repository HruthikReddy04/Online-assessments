/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

//Top down 
int f(int day , vector<vector<int>> &points , int last , vector<vector<int>> &dp)
{
    //base case
     int maxi = 0; 
    if(day == 0)
    {
       
        for(int task = 0 ; task < 3 ; task++)
        {
            if(task!= last)
            {
                maxi = max(maxi , points[0][task]);
            }
        }
        return maxi;
    }
    
    if(dp[day][last]!=-1)return dp[day][last];
    
    //recursive case 
    for(int task = 0 ; task < 3 ; task++)
    {
        if(task!=last)
        {
          maxi = max(maxi,points[day][task]+f(day-1,points, task ,dp)) ;
          
        }
    }
    dp[day][last] = maxi;
    return dp[day][last];
    
}

//Bottom up tabulation
int bt_up(vector<vector<int>> &points)
{
    vector<vector<int>> dp(points.size(), vector<int>(4,0));
    int maxi = 0 ;
    for(int last = 0 ;last<=3; last++)
    {
        for(int task = 0 ; task < 3 ; task++)
        {
            if(last!= task)
            {
                 maxi = max(maxi , points[0][task]);
            }
            
        }
        dp[0][last] = maxi ;
        maxi = 0;
    }
    
    for(int day = 1; day <points.size() ; day++)
    {
        for(int last = 0 ; last <= 3 ; last++)
        {
            for(int task = 0 ; task < 3; task++)
            {
                if(last!= task)
                {
                     dp[day][last] =  max( dp[day][last] ,points[day][task]+dp[day-1][task]);
                }
              
            }
            
        }
       
    }
    return dp[points.size()-1][3];
}
int main()
{
    int  n = 4;
    //int count = 0 ;
  //vector<vector<<int>> points(n,vector<int> (3,0));
  vector<vector<int>> dp(n,vector<int>(4,-1));
  vector<vector<int>> points = {{2,1,3}, {3,4,6} , {0,1,6} , {8,3,7}};
 // cout << f(n-1 ,points, 3, dp);
  cout<<bt_up(points);
  
    return 0;
}
