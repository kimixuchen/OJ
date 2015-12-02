/**
 * POJ-1700-Crossing River
 *xuchen
 *2015-12-02 09:37:12
**/
/**
 *DP
 *Solution 2.
**/
#include "stdio.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int N = 1005;
int dp[N];
int main()
{
     int T,n,i,time[1002],dp[1002];  
     cin >>T;  
     while(T--)  
     {  
         cin >> n;  
         for(i=0;i<n;i++)  
            cin >>time[i];  
         sort(time,time + n);  
         dp[0]=time[0] , dp[1]=time[1];  
         dp[2] = time[0]+time[1]+time[2];
         for(i=3;i<n;i++)  
             dp[i] = min(time[1]*2+time[0]+time[i] , time[i]+time[i-1]+time[0]*2)+dp[i-2];  
         cout <<dp[n-1] << endl;          
     }  
	return 0;
}
