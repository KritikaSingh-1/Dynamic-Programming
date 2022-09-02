#include<bits/stdc++.h>
using namespace  std;

int path(int n,int i,int j,int m,vector<vector<int> > &v){
	if(i==n-1 && j==m-1)
	    return 1;
	
	if(i==n || j==m){
		return 0;
	}
    if(v[i][j]!=-1){
    	return v[i][j];
	}

	v[i][j]=path(n,i+1,j,m,v)+path(n,i,j+1,m,v);
		
			
   
   return v[i][j];
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > v(n,vector<int>(m,-1));
	int x=path(n,0,0,m,v);
	cout<<x;
	return 0;
}
