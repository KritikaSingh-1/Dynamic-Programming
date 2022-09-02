#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/* Memoization method

int frogJump(int idx,int a[],int n,vector<int> &dp){
	if(idx==0){
		return 0;
	}
	if(dp[idx]!=-1){
		return dp[idx];
	}
	
	int left=frogJump(idx-1,a,n,dp)+abs(a[idx]-a[idx-1]);
	int right=INT_MAX;
	if(idx>1){
	    right=frogJump(idx-2,a,n,dp)+abs(a[idx]-a[idx-2]);
	}

	dp[idx]=min(left,right);
	return dp[idx];
}*/

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	vector<int> dp(n+1,-1);	
//	cout<<frogJump(n-1,a,n,dp);

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
	
	
	//space optimization
	int prev2=0,prev=0,curr=0;
	for(int i=1;i<n;i++){
		int f=prev+abs(a[i]-a[i-1]);
		int s=INT_MAX;
		if(i>1){
			s=prev2+abs(a[i]-a[i-2]);
		}
		curr=min(f,s);
		prev2=prev;
		prev=curr;
	}
	
    cout<<curr;
	return 0;
}
