#include<bits/stdc++.h>
using namespace std;

int knapsack( vector<int> weight,vector<int> value,int n,int wt){
	if(n==0){
		if(weight[n]<=wt){
			return value[n];
		}
		else{
			return 0;
		}
		
	}
	int nt=0+knapsack(weight,value,n-1,wt);
	int t=INT_MIN;
	if(weight[n]<=wt){
		t=value[n]+knapsack(weight,value,n-1,wt-weight[n]);
	}
	return max(t,nt);
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
        	

	
	cout<<x<<" ";
	return 0;
}
