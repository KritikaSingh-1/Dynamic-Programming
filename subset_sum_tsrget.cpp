#include<bits/stdc++.h>
using namespace std;
const int n=10;


int pat(int idx,int n,int a[],int k){
    if(idx==n){
    	return false;
	}
	if(k==0){
		return true;
	}
	int l=0,r=0;
	if(pat(idx+1,n,a,k)){
		return true;
	}
	if(pat(idx+1,n,a,k-a[idx])){
		return true;
	}
	return false;
}

int path(int idx,int n,int a[],int k, vector<vector<bool> >& dp){
    if(idx==n){
    	return false;
	}
	if(k==0){
		return dp[idx][k]=1;
	}
	if(dp[idx][k]==1){
		return true;
	}
	
	 bool l=path(idx+1,n,a,k,dp);
	 bool r=false;
	 if(k>=a[idx]){
	 	r=path(idx+1,n,a,k-a[idx],dp);
	 }
	return dp[idx][k]=(l|r);
}


int main(){
	int a[n],k;
	cin>>k;
		
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	//recursion
	int x=pat(0,n,a,k);
	
	//memoization
	vector<vector<bool> > dp1(n,vector<bool>(k+1,0));
	int y=path(0,n,a,k,dp1);
	
	//tabulation
    vector<vector<bool> > dp(n,vector<bool>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(a[0]<=k){
		dp[0][a[0]]=true;
    }
	for(int idx=1;idx<n;idx++){
		for(int target=1;target<=k;target++){
			bool l=dp[idx-1][target];
           	bool r=false;
           	if(a[idx]<=target){
               	r=dp[idx-1][target-a[idx]];
	        }
	        dp[idx][target]=(l|r);
		}
	}
	
    //space optimization
    vector<bool> prev(k+1,0),curr(k+1,0);
	prev[0]=0,curr[0]=0;
	if(a[0]<=k){
		prev[a[0]]=true;
	}
	
	for(int idx=1;idx<n;idx++){
		for(int target=1;target<=k;target++){
			bool l=prev[target];
		 	bool r=false;
            if(a[idx]<=target){
	           	r=prev[target-a[idx]];
	        }
	        curr[target]=(l|r);
		}
		prev=curr;
	}
	
	//output
	cout<<x<<" "<<y<<" "<<dp[n-1][k]<<" "<< curr[k];
	return 0;
}
