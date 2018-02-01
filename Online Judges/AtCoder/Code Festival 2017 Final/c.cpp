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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int maks = 0;
	for(i=0;i<n-1;i++){
		int minim = inf;
		int waktu1 = a[i], waktu2 = 24-a[i];
		printf("i: %d waktu1: %d waktu2: %d\n",i,waktu1,waktu2);
		for(j=i+1;j<n;j++){
			printf("a[%d]: %d\n",j,a[j]);
			int dWaktu1 = min(abs(waktu1-a[j]),(24-abs(waktu1-a[j])));
			int dWaktu2 = min(abs(waktu2-a[j]),(24-abs(waktu2-a[j])));
			printf("dWaktu1: %d dWaktu2: %d\n",dWaktu1, dWaktu2);
			minim = min(minim,min(dWaktu2,dWaktu1));
			printf("minim1: %d\n",minim);
		}
		printf("minim akhir1: %d\n",minim);
		maks = max(maks,minim);
		printf("maks jd: %d\n",maks);
	}
	printf("maks: %d\n",maks);
	//jangan lupa consider dia juga
	// int waktu1 = 0, waktu2 = 24;
	// int minim = inf;
	// printf("part2\n");
	// for(j=0;j<n;j++){
		
	// 	int dWaktu1 = min(abs(waktu1-a[j]),(24-abs(waktu1-a[j])));
	// 	int dWaktu2 = min(abs(waktu2-a[j]),(24-abs(waktu2-a[j])));
	// 	printf("dWaktu1: %d dWaktu2: %d\n",dWaktu1, dWaktu2);
	// 	minim = min(minim,min(dWaktu2,dWaktu1));
	// 	printf("minim2: %d\n",minim);
	// }
	// maks = max(maks,minim);
	// printf("maks jd: %d\n",maks);
	printf("%d\n",maks);
	return 0;
};