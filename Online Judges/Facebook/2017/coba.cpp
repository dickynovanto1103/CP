#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,temp;
	vector <int> a;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&temp); a.push_back(temp);}
	printf("array:");
	for(i=0;i<n;i++){printf(" %d",a[i]);}
	printf("\n");
	int jumlah=2,counter=0;
	while(jumlah){
		a.erase(a.begin()+counter);
		printf("sisa array:");
		for(i=0;i<a.size();i++){printf(" %d",a[i]);}
		printf("\n");
		jumlah--;
	}
	return 0;
}