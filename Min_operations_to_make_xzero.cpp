// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<string> 
using namespace std;
vector<int> nums = { 1,1,4,3,5};
unordered_map<string , int> map ;
int min_operations(int l ,int r,int x)
{
    if(x == 0)return 0;

    if(l>r || x<0)return 1e5;
    string s= to_string(l)+"*"+to_string(r)+"*"+to_string(x);
    if(map.find(s)!=map.end())return map[s];
  int left =  1+min_operations(l+1, r,x-nums[l]);
  int right =  1+min_operations(l,r-1, x-nums[r]);
  map[s] = min(left,right);
  return map[s];
}

//T.C : (2^n)
//time complexity reduced into O(n^2)
//When the constriant are big n<= 10^9 we can't do this 
//we need a better algorithm 
//there are 2 ways to solve this problem using prefix sum and sliding window 
//in most dp cases timecomplexity depends on different unique states we need
//we need n^2 l,r pairs and t diffrent target values combining them we get 
//O(n^2*x)


//This is a longest subarray problem in disguice 
int min_operations_sw(int t)
{
  int sum = 0;
  for(int i: nums)sum+=i;
  int k = sum-t ;
  int start= 0 ;
  int runSum = 0;
  int longest =0 ;
  for(int end = 0 ; end < nums.size() ;end++)
  {
    runSum += nums[end];
    
    while(runSum>k) runSum -= nums[start++]; 
    if(runSum == k)longest = max(longest, end-start+1);
  }
  return nums.size()-longest ;
}

//we can do this problem using prefixSum also
int min_operations_ps(int t)
{
    //general idea is to create all subarray sum and find longest one which will take O(n^3)
    //let's reduce one n
    //It takes one n to fix end ,one n to start and one n to find sum of subrray 
    //we can reduce 3rd n using prefix sum
    int n = nums.size();
    int prefix[n] ;
    preifx[0] = nums[0] ;
    map[0] =  ;
    map[nums[0]] = 0;
    for(int i = 1 ; i < nums.size() ; i++)
    {
        prefix[i] = prefix[i-1] + nums[i];
        map[prefix[i]] = i ;
    }
    int x = sum -t;
    int longest = 0;

    for(int end  = 0 ;end <n ; end++)
    {
        if(map.find(prefix[end]-x))
        {
            if(prefix[end] == x)
            {
               longest = max(longest,i-map[prefix[end]-x]+1);
            }
            else
            {
                longest = max(longest,i-map[prefix[end]-x]);
            }
        }
    }
    return longest;

    //we can generate every subarray 
    //But we are bothered about specific sum whose value is x
    //among all possible subarray we generate from start using a particular end 
    //we need only those whose diffence of prefixsum is x
    //if we somehow store it in map we can reduce second n to O(1)

}
int main() {
 // cout <<  min_operations(0,nums.size()-1,5);
  cout<< min_operations_ps(5);

    return 0;
}
