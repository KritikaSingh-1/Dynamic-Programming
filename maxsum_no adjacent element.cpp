#include<bits/stdc++.h>
using namespace std;
//recursion /memoization
int maxsum(int idx,int a[],int n,vector<int> & dp){
	if(idx==n){
		return 0; 
	}
	if(idx==n-1){
		return a[n-1];
	}
	if(dp[idx]!=-1){
		return dp[idx];
	}
     int left=maxsum(idx+2,a,n,dp)+a[idx];
	
	int right=maxsum(idx+1,a,n,dp)+0;
   
	
	return dp[idx]=max(left,right);	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> dp(n,-1);
    int	s=maxsum(0,a,n,dp);
	cout<<s<<endl;
	
	//tabulation
	int dpp[n]={-1};
	int take=INT_MIN,nontake=INT_MIN;
	dp[0]=a[0];
	for(int i=1;i<n;i++){
		take=a[i];
		if(i>1){
			take+=dp[i-2];
		}
		nontake=dp[i-1]+0;
		dp[i]=max(take,nontake);
	}
	cout<<dp[n-1]<<endl;
	
	//space optimization
	int prev2=0,prev=a[0];
	take=0,nontake=0;
	int curr;
	for(int i=1;i<n;i++){
		take =a[i];if(i>1){
			prev2;
		}
		nontake=a[i]+prev2;
		curr=max(take,nontake);
		prev2=prev;
		prev=curr;
	}
	cout<<curr;
	return 0;
}
