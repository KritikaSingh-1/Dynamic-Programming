#include<bits/stdc++.h>
using namespace std;
const int n=10;


int pat(int idx,int n,int a[],int k,int &s){

    if(idx==n){
    	return s;
	}
	if(k==0){
		s++;
	       return s;
		
	}

	int x=pat(idx+1,n,a,k,s);

	int y=pat(idx+1,n,a,k-a[idx],s);
	return x+y;
}

int path(int idx,int n,int a[],int k, vector<vector<int> >& dp,int &s){
    if(idx==n){
    	return 0;
	}
	if(dp[idx][k]!=0){
		 return dp[idx][k];
	}
	if(k==0){
		
		 return 1;
	}

	int l=0,r=0;
	if(a[idx]<=k){
		 r=path(idx+1,n,a,k-a[idx],dp,s);
	}
	
	 
	 l=path(idx+1,n,a,k,dp,s);
	 
	 
	 
	return dp[idx][k]=l+r;
}


int main(){
	int a[n],k;
	cin>>k;
		
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	//recursion
	int s=0;
	pat(0,n,a,k,s);
	int x=s;
	//memoization
	vector<vector<int> > dp1(n,vector<int>(k+1,0));
	s=0;
	int y=path(0,n,a,k,dp1,s);
	
	//tabulation

    vector<vector<int> > dp(n,vector<int>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	if(a[0]<=k){
		dp[0][a[0]]=1;
    }
	for(int idx=1;idx<n;idx++){
		for(int target=0;target<=k;target++){
			int l=dp[idx-1][target];
           	int r=0;
           	if(a[idx]<=target){
               	r=dp[idx-1][target-a[idx]];
	        }
	        dp[idx][target]=l+r;
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
