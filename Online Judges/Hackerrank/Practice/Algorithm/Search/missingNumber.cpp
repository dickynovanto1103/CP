#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,m,i,j, maks=-1,minim=100000;
	//int a1[200010],a2[200010];
	int counter1[10010],counter2[10010];
	for(i=0;i<=10000;i++){counter1[i] = counter2[i] =0;}//inisialisasi
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		counter1[bil]++;
		maks = max(maks,bil); minim = min(minim,bil);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		int bil;
		scanf("%d",&bil);
		counter2[bil]++;
		maks = max(maks,bil); minim = min(minim,bil);
	}
	int cnt=0;
	for(i=minim;i<=maks;i++){
		
		if(counter1[i]!=counter2[i]){
			if(cnt>0){printf(" ");}
			printf("%d",i); cnt++;
		}
	}
	printf("\n");
	return 0;
}