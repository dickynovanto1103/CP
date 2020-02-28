#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[200001];
	int satu = 0, dua = n;
	int idx = 1;
	bool valid = true;
	for(i=1;i<=2*n;i+=2) {
		if(valid){
			a[satu++] = idx++;
			a[dua++] = idx++;	
			valid = false;
		}else{
			a[dua++] = idx++;	
			a[satu++] = idx++;
			valid = true;
		}
	}
	int sum = 0;
	int kiri = 0, kanan = n-1;
	int minim, maks;
	for(i=0;i<n;i++){
		sum += a[i];
	}
	minim = sum, maks = sum;

	do{
		sum -= a[kiri];
		kiri++;
		kiri %= 2*n;
		kanan++;
		kanan %= 2*n;
		sum += a[kanan];
		minim = min(minim, sum);
		maks = max(maks, sum);
		// printf("kiri: %d kanan: %d sum: %d minim: %d maks: %d\n",kiri, kanan, sum, minim, maks);
		if((maks - minim) > 1){
			printf("NO\n");
			return 0;
		}
	}while(kiri != 0 && kanan != n-1);
	printf("YES\n");
	for(i=0;i<2*n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");

	return 0;
};