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
	int k,i,j;
	ll s,n;
	scanf("%lld %d %lld",&n,&k,&s);
	ll tot = (n-1LL)*k;
	if(tot < s){printf("NO\n"); return 0;}
	if(s < k){printf("NO\n"); return 0;}
	printf("YES\n");
	ll banyakLangkahMin = s/(ll)k;
	ll banyakLangkahMaks = banyakLangkahMin;
	ll cntBanyak = s%(ll)k;
	if(cntBanyak != 0){
		banyakLangkahMaks++;
	}

	if(banyakLangkahMaks > (n-1)){
		printf("NO\n"); return 0;
	}


	ll cntSedikit = k - cntBanyak;
	int node = 1;

	vi ans;
	bool isAwal = true;
	int nodeAkhir = 1;
	for(i=0;i<cntBanyak;i++){
		if(isAwal){
			ans.pb(1+banyakLangkahMaks);
			nodeAkhir = 1+banyakLangkahMaks;
			isAwal = false;
		}else{
			ans.pb(1);
			nodeAkhir = 1;
			isAwal = true;
		}
	}
	for(i=0;i<cntSedikit;i++){
		if(isAwal){
			ans.pb(nodeAkhir + banyakLangkahMin);
			nodeAkhir = nodeAkhir + banyakLangkahMin;
			isAwal = false;
		}else{
			ans.pb(nodeAkhir - banyakLangkahMin);
			nodeAkhir = nodeAkhir - banyakLangkahMin;
			isAwal = true;
		}
	}

	int ukuran = ans.size();
	for(i=0;i<ukuran;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};