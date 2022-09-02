#include<bits/stdc++.h>
using namespace std;

int minCoin(int idx,int target,vector<int> &v){
	if(idx==0){
		if(target%v[idx] ==0){
		   return 1;
     	}
	    else{
		    return 0;
    	}
	}
	
	int take=0;
	if(v[idx]<=target){
		take=minCoin(idx,target-v[idx],v);
	}
	int nontake=minCoin(idx-1,target,v);
	
	return take+nontake;
}

int minCoi(int idx,int target,vector<int> &v,vector<vector<int> > &dp){
	if(idx==0){
		if(target%v[idx] ==0){
		   return 1;
     	}
	    else{
		    return 0;
    	}
	}
	if(dp[idx][target]!=-1){
		return dp[idx][target];
	}
	int take=0;
	if(v[idx]<=target){
		take=minCoi(idx,target-v[idx],v,dp);
	}
	int nontake=minCoi(idx-1,target,v,dp);
	
	return dp[idx][target]=take+nontake;
}
	
int main(){
	int n,target,x;
	cin>>n>>target;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	
	cout<<minCoin(n-1,target,v);
	
	vector<vector<int> > dp(n,vector<int> (target+1,-1));
		cout<<endl<<minCoi(n-1,target,v,dp)<<endl;
		
		
	//tabulation
	vector<vector<int> > dp1(n,vector<int> (target+1,-1));
	
	for(int t=0;t<=target;t++){
		if(t%v[0]==0){
			dp1[0][t]=1;
		}
		else{
			dp1[0][t]=0;
		}
	}
	for(int i=1;i<n;i++){
		for(int t=0;t<=target;t++){
			int nontake=dp1[i-1][t];
			
			int take=0;
        	if(v[i]<=t){
	        	take=dp1[i][t-v[i]];
	        }
        	
	
     	    dp1[i][t]=take+nontake;
		}
	}
	cout<<dp1[n-1][target];
	
	//space optimization
	vector<int> prev(target+1,0),curr(target+1,0);
	
	for(int t=0;t<=target;t++){
		if(t%v[0]==0){
			prev[t]=1;
		}
		else{
			prev[t]=0;
		}
	}
	for(int i=1;i<n;i++){
		for(int t=0;t<=target;t++){
			int nontake=prev[t];
			
			int take=0;
        	if(v[i]<=t){
	        	take=curr[t-v[i]];
	        }
        	
	
     	    curr[t]=take+nontake;
		}
		prev=curr;
	}
	cout<<curr[target];	
	return 0;
}
