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
vector<int> nums=  { 5, 4, 6,2,7};
//      We are given 5 values where a0 ,a1 represent dimensions of M1 => a[i-1] ,a[i] represent Mi 
//Given five values form 4 matrices . So we need to find min value of M1 * M2 * M3 * M4 
//If you observe no of operations for diffrent cases of multiplication 
//If we take 2 at a time for m1* m2 = 5*4*6= 120 for m3*m4 = 84 => 120 + 84 = 204
//it we manually do it , 120(5,6) + 60(5,2) + 70(5,7) = 250 
//There is chance for minimum but we don't know so try all possiblities 
//How to generate all possibilites ?
//on which bases there are different anwsers? in 1st case we mult m1m2 with m3m4 but in other we mult m1m2 with m3
//data is insufficient lets'try reverse mutliplication 84(6,https://www.onlinegdb.com/#tab-stdin7) + 168(4,7) + 
//I got answer based on solving the expression m1*m2*m3*m4 we get different possibiites so based on parenthesis we keep between the matrices 
//(M1) M2 M3 M4 how m2 m3 m4 is multiplied is something we don't care about .we pass that to next rec call 
//(M1 M2) M3 M4
//(M1 M2 M3) M4

//tree braches based on 1st choice of parenthsis .
//as u know when bases cases hit it stops and pumps the min value up 

//choice set = { after M1 to before M4 } => {1,2,3} . Genaralize set = { l ,l+1 .. r-1} 


//we took the choice but what's next we need to call the smaller subproblem 
//after keeping parenthsis that mean we solve expression in result in prenthsis with outside of parenthsis 
//we took a desion that we need to solve the problem in this partion way . so final result should be this multiplication 
//so we call the function with matrices  parenthisis inside and outside it 
//solve(M1) ,solve(M2M3M4) we assume it will give us min operation of entire matrix so we need to find the final cost of all assemly 
//cost. = solve(M1) + solve(M2M3M4)  + final assemly but we don't need all matrix info here we need only sizes and where the expressions starts and ends 
//cost = solve(l,i) + solve(i+1, r) + final assembly 
//final assembly = row(l,i) *col(l,i)*col(i+1,r) => we know for Mi matrix dimesions are a[i-1]*a[i] 
//Ml = a[l-1]*a[l]. and Mr = a[r-1]*a[r];
//final assembly = a[l-1]*a[i]*a[r] ;


//We exhaust all choices in choice set among the final results to get min 
//what does l ,r represent start of matrix l and end of matrx r

//Let's analyze it 
//at n-1 partions or n-1 choices or 2(n-1) 
//so 2(n-1) + 2(n-1)(2*n-2) + 2^i(n-1)(n-2)..(n-i)
//T.C - O(2^n)

//Can we do better yes
//there are overlapping subproblems 


int solve(vector<vector<int>> &dp, int l ,int r)
{
    ////base case 
    if(l == r ){
        dp[l][r] = 0;
        return 0; 
    }
    
    if(dp[l][r]!=-1)return dp[l][r];
    
    
    //recursive case 
    int ans= 1e5 ;
    for(int i = l ; i < r ; i++)
    {
        ans = min(ans , solve(dp,l,i) + solve(dp, i+1,r) + nums[l-1]*nums[i]*nums[r]);
    }
    dp[l][r]= ans;
    return ans;
    
}


//confusion about size of 2d dp
//we want end result from 1 to n
//tabulation
int mcm_tabulation()
{
    int n = nums.size()-1;
    vector<vector<int>> dp(n+1 ,vector<int> (n+1,0));
    
    
    
    //here dp represents cost of matrix multiplication
    for(int len = 2; len<=n; len++)
    {
        for(int i = 1 ; i<=n-len+1; i++)
        {
            int j = i+len-1;
            int ans = 1e5;
            
            for(int k = i ; k <j ; k++)
            {
                ans = min(ans, dp[i][k]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j]);
            }
            dp[i][j] = ans;
        }
    }
    
    return dp[1][n];
}

//learning 


int main()
{
    vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), -1));
    //cout <<solve(dp, 1,2);
    cout<<mcm_tabulation();

    return 0;
}
https://chatgpt.com/share/6a7deac0-b68c-83ea-90ca-bb98b1761b3f
