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

const int maxn = 2010;

int main(){
	int n,i,j,a[maxn];
	scanf("%d",&n);
	int cnt1 = 0;
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
		if(a[i]==1){cnt1++;}
	}
	if(n==1){
		if(a[0]==1){
			printf("0\n");	
		}else{
			printf("-1\n");
		}
		return 0;
	}

	if(cnt1>0){
		printf("%d\n",n-cnt1); return 0;
	}
	vi listGcd;
	bool foundGcd1 = false;
	for(i=0;i<n-1;i++){
		int hasilGcd = __gcd(a[i],a[i+1]);
		if(hasilGcd==1){foundGcd1 = true;}
		listGcd.pb(hasilGcd);
		//printf("yang dipush hasilGcd: %d\n",hasilGcd);
	}
	if(foundGcd1){printf("%d\n",n); return 0;}
	
	int gcd = listGcd[0];
	for(i=1;i<listGcd.size();i++){
		gcd = __gcd(gcd,listGcd[i]);
	}
	if(gcd!=1){//ga mungkin
		printf("-1\n"); 
	}else{
		//cari terdekat
		int banyak = listGcd.size();
		int minim = inf;
		for(i=0;i<banyak;i++){
			for(j=i+1;j<banyak;j++){
				if(__gcd(listGcd[i],listGcd[j])==1){minim = min(minim,(j-i));}
			}
		}
		//printf("minim: %d\n",minim);
		printf("%d\n",minim+n);
	}
	return 0;
};