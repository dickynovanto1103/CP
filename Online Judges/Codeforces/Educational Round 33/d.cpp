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

const int maxn = 100010;

int main(){
	int n,d,i,j;
	int a[maxn];
	scanf("%d %d",&n,&d);
	ll jumlahUang = 0;
	int ans = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){ //cek apakah jumlah uang sekarang negatif..klo iya..tambahin
			if(jumlahUang<0){jumlahUang = 0; ans++;}
		}else{
			jumlahUang+=(ll)a[i];
			
		}
		if(jumlahUang>d){printf("-1\n"); return 0;}
	}
	printf("%d\n",ans);
	return 0;
};