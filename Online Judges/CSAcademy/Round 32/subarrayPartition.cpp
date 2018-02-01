#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a[100010],i,j;
	int last[100010];
	int maks=-1,minim = 1000000000;
	scanf("%d",&n);
	memset(last,-1,sizeof last);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		minim = min(minim,a[i]); maks = max(maks,a[i]);
		last[a[i]] = i;
	}
	
	//list semua jarak..kemudian diurutkan

	int counter = 0, idx = 0;
	for(i = 0;i<n;i++){
		idx = max(idx,last[a[i]]);
		if(i==idx){counter++;}
	}
	printf("%d\n",counter);
	return 0;
}