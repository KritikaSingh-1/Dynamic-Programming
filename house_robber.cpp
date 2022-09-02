#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> dp(n,-1);
    //int	s=maxsum(0,a,n,dp);
	//cout<<s<<endl;
	
	//tabulation
	int dpp[n]={-1};
	int take=INT_MIN,nontake=INT_MIN;
	dp[0]=a[0];
	for(int i=1;i<n;i++){
		take=a[i];
		if(i>1){
			take+=dp[i-2];
		}
		nontake=dp[i-1]+0;
		dp[i]=max(take,nontake);
	}
	cout<<dp[n-1]<<endl;
	
	//space optimization
	int prev2=0,prev=a[1];
	take=0,nontake=0;
	int curr;
	for(int i=2;i<n;i++){
		take =a[i];if(i>1){
			prev2;
		}
		nontake=a[i]+prev2;
		curr=max(take,nontake);
		prev2=prev;
		prev=curr;
	}

    int prev3=0,prev1=a[0];
	take=0,nontake=0;
	int curr1;
	for(int i=1;i<n-1;i++){
		take =a[i];if(i>1){
			prev3;
		}
		nontake=a[i]+prev3;
		curr1=max(take,nontake);
		prev3=prev1;
		prev1=curr1;
	}
	cout<<max(curr,curr1);
	
	return 0;
	
}
