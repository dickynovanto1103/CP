#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,m;
	int pos[1010], v[1010] ;
	double t[1010];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&pos[i]);}
	for(i=0;i<n;i++){scanf("%d",&v[i]);}
	for(i=0;i<n;i++){

		int jarak = abs(pos[i] - m);
		int kecepatan = v[i];
		t[i] = (double)jarak / (double) kecepatan;
		//printf("t[%d] = %.2lf\n",i,t[i]);
	}
	//cari minimal
	double minim = 1000000000;
	for(i=0;i<n;i++){
		minim = min(minim,t[i]);
	}
	//cari minimal ada brp
	int idx = -1, cnt=0;
	for(i=0;i<n;i++){
		if(minim==t[i]){idx=i; cnt++;}
		if(cnt==2){idx=-1; break;}
	}
	printf("%d\n",idx);
	return 0;
}