#include<bits/stdc++.h>
using namespace std;

int minCoin(int idx,int target,vector<int> &v){
	if(idx==0){
		if(target%v[idx] ==0){
		   return target/v[idx];
     	}
	    else{
		    return INT_MAX;
    	}
	}
	
	int take=INT_MAX;
	if(v[idx]<=target){
		take=1+minCoin(idx,target-v[idx],v);
	}
	int nontake=0+minCoin(idx-1,target,v);
	
	return min(take,nontake);
}

int minCoi(int idx,int target,vector<int> &v,vector<vector<int> > &dp){
	if(idx==0){
		if(target%v[idx] ==0){
		   return target/v[idx];
     	}
	    else{
		    return INT_MAX;
    	}
	}
	if(dp[idx][target]!=-1){
		return dp[idx][target];
	}
	int take=INT_MAX;
	if(v[idx]<=target){
		take=1+minCoi(idx,target-v[idx],v,dp);
	}
	int nontake=0+minCoi(idx-1,target,v,dp);
	
	return dp[idx][target]=min(take,nontake);
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
			dp1[0][t]=t/v[0];
		}
		else{
			dp1[0][t]=INT_MAX;
		}
	}
	for(int i=1;i<n;i++){
		for(int t=0;t<=target;t++){
			int nontake=0+dp1[i-1][t];
			
			int take=INT_MAX;
        	if(v[i]<=t){
	        	take=1+dp1[i][t-v[i]];
	        }
        	
	
     	    dp1[i][t]=min(take,nontake);
		}
	}
	cout<<dp1[n-1][target]<<endl;
	
	
	//space optimization
	vector<int> prev(target+1,0),curr(target+1,0);
	
	for(int t=0;t<=target;t++){
		if(t%v[0]==0){
			prev[t]=t/v[0];
		}
		else{
			prev[t]=INT_MAX;
		}
	}
	for(int i=1;i<n;i++){
		for(int t=0;t<=target;t++){
			int nontake=0+prev[t];
			
			int take=INT_MAX;
        	if(v[i]<=t){
	        	take=1+curr[t-v[i]];
	        }
        	
	
     	    curr[t]=min(take,nontake);
		}
		prev=curr;
	}
	cout<<prev[target];
		
	return 0;
}
