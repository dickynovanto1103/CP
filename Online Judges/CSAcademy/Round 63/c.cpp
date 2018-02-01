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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	int a[maxn],b[maxn];
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
	
	int maks = -inf;
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		//printf("b[%d]: %d\n",i,b[i]);
		maks = max(maks,b[i]);
	}
	
	if(maks==0){printf("1\n"); return 0;}
	int temp[maxn];
	for(i=0;i<n;i++){
		temp[i] = a[i]-b[i];
		if(temp[i]<0){printf("-1\n"); return 0;}
	}
	int gcd = 0;
	for(i=0;i<n;i++){
		gcd = __gcd(gcd,temp[i]);
	}
	if(gcd==0){printf("%d\n",maks+1); return 0;}
	//cari divisor untuk gcd
	int ans = gcd;
	for(int angka=1;angka*angka<=gcd;angka++){
		if(gcd%angka==0){
			int bil1 = angka;
			if(bil1>maks){
				for(i=0;i<n;i++){
					if(a[i]%bil1!=b[i]){
						break;
					}
				}
				if(i==n){ans = min(ans,bil1);}
			}
			int bil2 = gcd/angka;
			if(bil2>maks){
				for(i=0;i<n;i++){
					if(a[i]%bil2!=b[i]){
						break;
					}
				}
				if(i==n){ans = min(ans,bil2);}
			}
				
		}
		
	}
	
	for(i=0;i<n;i++){
		if(a[i]%ans!=b[i]){
			printf("-1\n"); return 0;
		}
	}
	printf("%d\n",ans);
	return 0;
};