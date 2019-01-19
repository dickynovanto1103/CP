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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi listDivisor;
	for(i=1;i*i<=n;i++){
		if(n % i == 0){
			int bil1 = i;
			int bil2 = n/i;
			if(bil1 == bil2){
				listDivisor.pb(bil1);
			}else{
				listDivisor.pb(bil1); listDivisor.pb(bil2);
			}
		}
	}
	vi listAns;
	for(i=0;i<listDivisor.size();i++){
		ll bil = listDivisor[i];
		ll bilAwal = 1;
		ll bilAkhir = 1 + n - bil;
		listAns.pb(((bilAwal + bilAkhir)*(ll)(n/bil)) / 2LL);
	}
	sort(listAns.begin(), listAns.end());
	for(i=0;i<listAns.size();i++){
		printf("%lld ",listAns[i]);
	}
	printf("\n");
	return 0;
};