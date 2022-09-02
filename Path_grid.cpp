#include<bits/stdc++.h>
using namespace std;
const int m=3,n=4 ,r=4,s=3;
int findPath(int v[n][m],int n,int m,int i,int j){
	if(i==n-1 && j==m-1){
		
		return v[i][j];
	}
	if(i>=0 && i<n && j>=0 && j<m){
	
	 int down=v[i][j]+findPath(v,n,m,i,j+1);
	 int left=v[i][j]+findPath(v,n,m,i+1,j);
     return min(down,left);
   }
    return 1e9;
}
//memoization
int findPat(int v[n][m],int n,int m,int i,int j,int dp[r][s]){
	if(i==n-1 && j==m-1){
		
		return v[i][j];
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	if(i>=0 && i<n && j>=0 && j<m){
	
	 int down=v[i][j]+findPat(v,n,m,i,j+1,dp);
	 int left=v[i][j]+findPat(v,n,m,i+1,j,dp);
     return dp[i][j]=min(down,left);
   }
    return 1e9;
}
int main(){
//	int x,m,n;
//	cin>>n>>m;
	int v[n][m];
//	vector<vector<int> > v;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		//	v[i].push_back(x);
		}
	}
	
	int ans=findPath(v,n,m,0,0);
	cout<<ans;
	int dp[n][m]={0};
	int y=findPat(v,n,m,0,0,dp);
	cout<<endl<<y;
	//tabulation;
	return 0;
}
