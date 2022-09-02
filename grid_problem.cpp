#include<bits/stdc++.h>
using namespace std;
const int n=3;

int path(int i,int j,int a[n][n]){
	if(j<0 || j>=n){
		return INT_MIN;
	}
	if(i==n-1){
		return a[i][j];
	}
	int x=a[i][j]+path(i+1,j,a);
	int y=a[i][j]+path(i+1,j+1,a);
	int z=a[i][j]+path(i+1,j-1,a);
	return max(x,max(y,z));
}
int path(int i,int j,int a[n][n],int dp[n][n]){
	if(j<0 || j>=n){
		return INT_MIN;
	}
	if(i==n-1){
		return a[i][j];
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	int x=a[i][j]+path(i+1,j,a);
	int y=a[i][j]+path(i+1,j+1,a);
	int z=a[i][j]+path(i+1,j-1,a);
	return dp[i][j]= max(x,max(y,z));
}
int main(){
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
	    int y =	path(0,i,a);
	    ans=max(ans,y);
	}
	
	int an=INT_MIN;
	int dp[n][n]={0};
	for(int i=0;i<n;i++){
	    int y =	path(0,i,a,dp);
	    an=max(an,y);
	}
	cout<<ans<<" "<<an;
	return 0;
}
