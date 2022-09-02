#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int x,total=0;
	for(int i=0;i<n;i++){
		cin>>x;
		v[i]=x;
		total+=x;
	}
	
	int k=total;

	
	 vector<vector<bool> > dp(n,vector<bool>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(v[0]<=k){
		dp[0][v[0]]=true;
    }
	for(int idx=1;idx<n;idx++){
		for(int target=1;target<=k;target++){
			bool l=dp[idx-1][target];
           	bool r=false;
           	if(v[idx]<=target){
               	r=dp[idx-1][target-v[idx]];
	        }
	        dp[idx][target]=(l|r);
		}
	}
	
	int ans=INT_MAX;
    for(int j=0;j<=total/2;j++){
    	if(dp[n-1][j]){
    		ans=min(ans,abs((total-j)-j));
		}
	}
	
	cout<<ans;
	return 0;
}
