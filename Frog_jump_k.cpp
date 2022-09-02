#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/*Recursion method
int frogJump(int idx,int a[],int k){
	if(idx==0){
		return 0;
	}
    int steps=INT_MAX;
	for(int i=1;i<=k;i++){
		if(idx-i >=0){
		
		int jump=frogJump(idx-i,a,k)+abs(a[idx]-a[idx-i]);
        steps=min(jump,steps);
    }
   }

	return steps;
}

*/


/* Memoization method*/

int frogJump(int idx,int a[],int k,vector<int> &dp){

	if(idx==0){
		return 0;
	}
	
	if(dp[idx]!=-1){
		return dp[idx];
	}
	
    int steps=INT_MAX;
	for(int i=1;i<=k;i++){
		
		if(idx-i >=0){
		
		int jump=frogJump(idx-i,a,k,dp)+abs(a[idx]-a[idx-i]);
        steps=min(steps,jump);
        }
        dp[idx]=steps;
   }
   
   return steps;
}

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//cout<<frogJump(n-1,a,k);
	vector<int> dp(n,-1);
		
	cout<<frogJump(n-1,a,k,dp);
	

/*tabulation method

    int dp[n]={0};
    dp[0]=0;
    for(int i=1;i<n;i++){
    	if(dp[i]!=0)
		{
		continue;
		}
		int left=dp[i-1]+abs(a[i]-a[i-1]);
		int right=INT_MAX;
		if(i>1){
			right=dp[i-2]+abs(a[i]-a[i-2]);
		}
		dp[i]=min(left,right);
	}
	cout<<dp[n-1];*/
	
    
	return 0;
}
