#include <bits/stdc++.h>

using namespace std;
#define maxn 1000010
typedef long long ll;
bool isTriangle(int i, int j, int k){return (i+j>k) && (i+k > j) && (j+k > i);}
ll total[maxn], penambahan[maxn];
int main(){
	int n,i,j,k;
	int cnt = 0;
	ll selisih = 1;
	penambahan[3] = 1; penambahan[4] = 2;
	for(i=5;i<=1000000;i++){
		if(i%2==1){selisih++;}
		penambahan[i] = penambahan[i-1] + selisih;
	}
	for(i=4;i<=1000000;i++){
		//printf("penambahan[%d] = %d\n",i,penambahan[i]);
		total[i] = total[i-1] + penambahan[i-1];
	}
	//i=1000000;
	//printf("penambahan[%d] = %lld\n",i,penambahan[i]);
	//printf("total ke 1000000 %lld\n",total[1000000]);
	while(scanf("%d",&n), (n>=3)){
		printf("%lld\n",total[n]);
	}
	
	
	return 0;
}