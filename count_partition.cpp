#include<bits/stdc++.h>
using namespace std;

int mod=(int)(1e9+7);
int path(int idx,vector<int> &a,int sum, vector<vector<int> > &dp){
	
    if(idx==0){
    	if(sum==0 && a[0]==0){
    		return 2;
		}
		if(sum==0 || sum==a[0]){
		    return 1;
	   }
		
		return 0;
	}
	
	if(dp[idx][sum]!=-1){
		return dp[idx][sum];
	}
	
	 int l=path(idx-1,a,sum,dp);
	 int r=0;
	 if(sum>=a[idx]){
	 	r=path(idx-1,a,sum-a[idx],dp);
	 }
	return dp[idx][sum] = (l+r)%mod;
}
int main(){
	int n;
	cin>>n;
	int d=0,total=0;
	
	vector<int> a;
	cin>>d;	
	for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a.push_back(x);
			total+=x;	
	}
	int y=0;
	

    if((total-d)%2==0  &&  total-d>=0 ){
    	int t=(total-d)/2;
    	vector<vector<int> > dp(n,vector<int>(t+1,-1));
    	y=path(n-1,a,t,dp);
	}
        	

	
	cout<<y<<" ";
	return 0;
}
