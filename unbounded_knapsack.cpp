#include<bits/stdc++.h>
using namespace std;

int knapsack( vector<int> weight,vector<int> value,int n,int wt){
	if(n==0){
		if(weight[n]<=wt){
			return (wt/weight[0])*value[0];
		}
		else{
			return 0;
		}
		
	}
	int nt=0+knapsack(weight,value,n-1,wt);
	int t=INT_MIN;
	if(weight[n]<=wt){
		t=value[n]+knapsack(weight,value,n,wt-weight[n]);
	}
	return max(t,nt);
}

int knapsac( vector<int> weight,vector<int> value,int n,int wt,vector<vector<int> > &dp){
	if(n==0){
		if(weight[n]<=wt){
			return (wt/weight[0])*value[0];
		}
		else{
			return 0;
		}
		
	}
	if(dp[n][wt]!=-1){
		return dp[n][wt];
	}
	int nt=0+knapsac(weight,value,n-1,wt,dp);
	int t=INT_MIN;
	if(weight[n]<=wt){
		t=value[n]+knapsac(weight,value,n,wt-weight[n],dp);
	}
	return dp[n][wt]= max(t,nt);
}

int main(){
	int n,wt;
	cin>>n>>wt;
    vector<int > weight(n),value(n);
    int x,y;
    for(int i=0;i<n;i++){
    	cin>>x>>y;
    	weight[i]=x;
    	value[i]=y;
	}
	
    x=knapsack(weight,value,n-1,wt);
       //memoization 	
    vector<vector<int> > dp(n, vector<int> (wt+1, -1));
    y=knapsac(weight,value,n-1,wt,dp);

	cout<<x<<" "<<y<<" ";
	
	//tabulation
	vector<vector<int> > dp1(n,vector<int> (wt+1,0));
	for(int w=0;w<=wt;w++){
		dp1[0][w]=((int)(w/weight[0]))*value[0];
	}
	
	for(int i=1;i<n;i++){
		for(int w=0;w<=wt;w++){
			int nt=0+dp1[i-1][w];
         	int t=0;
        	if(weight[i]<=w){
         		t=value[i]+dp1[i][w-weight[i]];
        	}
            dp1[i][w]= max(t,nt);
		}
	}
	
	cout<<dp1[n-1][wt]<<" ";
	
	//space optimization
	//tabulation
	vector<int > prev(wt+1,0), curr(wt+1,0);
	for(int w=0;w<=wt;w++){
		prev[w]=((int)(w/weight[0]))*value[0];
	}
	
	for(int i=1;i<n;i++){
		for(int w=0;w<=wt;w++){
			int nt=0+prev[w];
         	int t=0;
        	if(weight[i]<=w){
         		t=value[i]+curr[w-weight[i]];
        	}
            curr[w]= max(t,nt);
		}
		prev=curr;
	}
	
	cout<<curr[wt];
	
	return 0;
}
