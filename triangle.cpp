#include<bits/stdc++.h>
using namespace std;

//memoization
int findPat(vector<vector<int> > v,int i,int j,int n){
	int m=v[i].size();
	if(i==n-1){
		
		return v[i][j];
	}

	if(i>=0 && i<n-1 && j>=0 && j<m){
	
	 int down=v[i][j]+findPat(v,i+1,j+1,n);
	 int left=v[i][j]+findPat(v,i+1,j,n);
     return min(down,left);
   }
    return 1e9;
}
int main(){
	int x,m,n;
	cin>>n;

	vector<vector<int> > v(n);
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>x;
			v[i].push_back(x);
		}
	}
	x=findPat(v,0,0,n);
	cout<<x<<endl;
	return 0;
}
