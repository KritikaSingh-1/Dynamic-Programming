#include<bits/stdc++.h>
using namespace std;
const int n=3,k=3;

//memoization
int ninj(int a[n][k],int idx,int last,vector<vector<int> >& ans){
	if(idx==0){
		int maxi=0;
		for(int i=0;i<k;i++){
			if(i!=last){
				maxi=max(maxi,a[idx][i]);
			}
		}
		return maxi;
	}
	if(ans[idx][last]!=0){
		return ans[idx][last];
	}
	int maxim=0;
	for(int i=0;i<k;i++){
		if(i!=last){
		
		    int preg=a[idx][i] + ninj(a,idx-1,i,ans);
		    	maxim=max(maxim,preg);
		}
	}
	
	return ans[idx][last]=maxim;
	
}

//recursion	
int ninja(int a[n][k],int idx,int last){
	if(idx==0){
		int maxi=0;
		for(int i=0;i<k;i++){
			if(i!=last){
				maxi=max(maxi,a[idx][i]);
			}
		}
		return maxi;
	}
	
	int maxim=0;
	for(int i=0;i<k;i++){
		if(i!=last){
		
		    int preg=a[idx][i]+	ninja(a,idx-1,i);
		    	maxim=max(maxim,preg);
		}
	}
	return maxim;
	
}


int main(){

	int a[n][k]={ {1,10,2},{9,6,4},{3,20,1}};
	int d=-1;
	vector<vector<int> > ans(n,vector<int>(k));
	cout<<ninja(a,n-1,3)<<endl;
	cout<<ninj(a,n-1,3,ans)<<endl;
	
	/*tabulation
	vector<vector<int> > an(n,vector<int>(k));
	
	for(int i=1;i<n;i++){
		
	for(int j=0;j<4;j++){
		if(an[i][j]!=0){
	    	continue;
     	}
		if(i!=j){
		
		    int preg=a[i][j] + an[i-1][j];
		    	maxim=max(maxim,preg);
		    	
		}
		an[i][j]=maxim;
	}
	    
	}
	cout<<an[n-1][k-1];
	*/
	
	return 0;
}
