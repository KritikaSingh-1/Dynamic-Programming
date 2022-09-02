#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=0;
	vector<int> b(n/2),c(n/2);
	sort(a.begin(),a.end());
	for(int i=0;i<n/2;i++){
		b[i]=a[i];
		c[i]=a[n-1-i];
	}
	 for(int i=0;i<n/2;i++){
	 	max+=abs(b[i]-c[i]);
	 }
	 cout<<"maximum: "<<max<<endl;
	
	int min=0;
	vector<int> d(n/2),e(n/2);
	int j=0;
	for(int i=0;i<n/2;i++){
		d[i]=a[j];
		e[i]=a[j+1];
		j+=2;
	}
	 for(int i=0;i<n/2;i++){
	 	min+=abs(d[i]-e[i]);
	 }
	 cout<<"minimum: "<<min<<endl;
	
	
	return 0;
}