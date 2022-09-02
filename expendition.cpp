#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
	cin>>n;
	
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	 
	int l,p;
	cin>>l>>p;
	
	for(int i=0;i<n;i++){
		a[i].first=l-a[i].first;
		
	}  
	
	sort(a.begin(),a.end());
	int ans=0;
	int curr=p;
	int flag=0;
	priority_queue<int,vector<int>> pq;
	for(int i=0;i<n;i++){
		if(curr>=l){
			break;
		}
		while(curr<a[i].first){
			if(pq.empty()){
				flag=1;
				break;
			}
			ans++;
			curr+=pq.top();
			pq.pop();
		}
		if(flag==1){
			break;
		}
		pq.push(a[i].second);
	}
	if(flag){
		cout<<"-1"<<endl;
	}
	while(!pq.empty() && curr<l){
		curr+=pq.top();
		pq.pop();
		ans++;
	}
	if(curr<l){
		cout<<"-1"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	
	
	return 0;
}