#include<bits/stdc++.h>
using namespace std;
const int n=6;
int pat(int idx,int n,int a[],int k1){
    if(idx==n){
    	return false;
	}
	if(k1==0 ){
		return true;
	}
	
	int l=pat(idx+1,n,a,k1-a[idx]);
		
	int r=pat(idx+1,n,a,k1);
	
	return l|r;
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
	int a[n];
	int total=0;	
	for(int i=0;i<n;i++){
			cin>>a[i];
			total+=a[i];	
	}
	int x=0,y=0;
	vector<vector<bool> > dp(n+1,vector<bool>(total/2,0));
    if(total%2==0){
    	x=pat(0,n,a,total/2);
        y=path(0,n,a,total/2,dp);	
	} 
	 
	
	cout<<x<<" "<<y;
	return 0;
}
