#include<bits/stdc++.h>
using namespace std;
const int n=3;

int path(int i,int j1,int j2,int a[n][n]){
	
	if(j1<0 || j1>=n || j2<0 || j2>=n){
		return -1e8;
	}
	if(i==n-1){
		if(j1==j2){
			return a[i][j1];
		}else{
			return a[i][j1]+a[i][j2];
		}
		
	}

	int answ=-1e8;
	
	for(int dj1=-1;dj1<=+1;dj1++){
		for(int dj2=-1;dj2<=+1;dj2++){
			int x=0;
			if(j1==j2){
				x=a[i][j1];
		   }
		   else{
		   	    x=a[i][j1]+a[i][j2];
		   }
         	x+=path(i+1,j1+dj1,j2+dj2,a);
         	//cout<<x;
	        answ=max(answ,x);
	        
		}

	}
     return answ;
}

int pat(int i,int j1,int j2,int a[n][n],int dp[n][n][n]){
	
	if(j1<0 || j1>=n || j2<0 || j2>=n){
		return -1e8;
	}
	if(i==n-1){
		if(j1==j2){
			return a[i][j1];
		}else{
			return a[i][j1]+a[i][j2];
		}
		
	}
  
	int answ=-1e8;
	  if(dp[i][j1][j2]!=-1){
    	return dp[i][j1][j2];
	}
	for(int dj1=-1;dj1<=+1;dj1++){
		for(int dj2=-1;dj2<=+1;dj2++){
			int x=0;
			if(j1==j2){
				x=a[i][j1];
		   }
		   else{
		   	    x=a[i][j1]+a[i][j2];
		   }
         	x+=pat(i+1,j1+dj1,j2+dj2,a,dp);
         	//cout<<x;
	        answ=max(answ,x);
	        
		}

	}
     return dp[i][j1][j2]=answ;
}

int main(){
	int a[n][n];
		int dp[n][n][n]={-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			for(int k=0;k<n;k++){
				dp[i][j][k]=-1;
			}
		}
	}

	int an=path(0,0,n-1,a);
	int x=pat(0,0,n-1,a,dp);
	cout<<" "<<x;
	return 0;
}
