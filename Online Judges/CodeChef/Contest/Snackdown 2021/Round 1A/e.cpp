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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int findNearest(int n) {
	int nearest = 1;
	//ga peduli sama n, anggep aja n == k
	for(int i=0;i<30;i++){
		if((1<<i) <= n){
			nearest = 1<<i;
		}else{
			break;
		}
	}
	return nearest;
}

vi getIndicesOf1(int n) {
	vi ans;
	for(int i=0;i<30;i++){
		if((1<<i) & n) {
			ans.pb(i);
		}
	}
	return ans;
}

void printVector(vi v) {
	for(int x: v)
		printf("%d\n", x);
	puts("");
}

bool isAllZero(vi v) {
	for(int x: v){
		if(x != 0){return false;}
	}
	return true;
}

bool validate(int k, vi ans) {
	vi v(k+1);
	fill(v.begin(), v.end(), 1);
	v[0] = 0;
	for(int i=0;i<ans.size();i++){
		int idx = ans[i];
		for(int j=idx;j<idx+(1<<i);j++){
			v[j] = 1 - v[j];
		}
	}
	if (!isAllZero(v)) {
		puts("wrong result");
		printf("for k: %d, the wrong vector with size: %d\n", k, ans.size());
		printVector(ans);
		assert(false);
	}
	return true;
}

int main(){
	int tc,i,j;
	ll n,k;

	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld",&n,&k);
		// printf("processing tc with n: %d k: %d\n", n, k);
		if(k == 0){
			puts("YES"); puts("0"); continue;
		}
		if(k % 2 == 0){puts("NO"); continue;}

		int nearest = findNearest(k);
		int selisih = k - nearest;
		puts("YES");

		// printf("selisih: %d\n", selisih);
		vi indices1 = getIndicesOf1(k);
		// puts("indices1");
		// printVector(indices1);
		vi startIndexes(indices1.size());
		int idx = 1;
		for(i=0;i<indices1.size();i++){
			int pangkat = indices1[i];
			startIndexes[i] = idx;
			idx += (1<<pangkat);
		}
		/*
			13: 1101
			1 1111 111

			9: 1001
			19: 10011
		*/
		// puts("startIndexes");
		// printVector(startIndexes);

		vi ans;

		int step = 1;
		for(i=0;i<indices1.size()-1;i++){
			// printf("i: %d\n", i);
			int idx1 = indices1[i], idx2 = indices1[i+1];
			int selisih = idx2 - idx1;
			int wantToRemoveAmount = 1<<idx1;
			int start = startIndexes[i] + wantToRemoveAmount;
			for(j=0;j<selisih-1;j++){
				// printf("push idx: %d\n", start);
				ans.pb(start);
				start += step;
				step *= 2;	
			}
			// printf("finally push idx: %d buat hilangin %d\n", startIndexes[i], wantToRemoveAmount);
			ans.pb(startIndexes[i]);
			step *= 2;
		}
		int finalIdx = startIndexes[startIndexes.size() - 1];
		// printf("final push idx: %d\n", finalIdx);
		ans.pb(finalIdx);
		// puts("ans vector:");
		// printVector(ans);

		
		// ans.pb(idx);

		printf("%d\n", ans.size());
		for(int x: ans){
			printf("%d\n", x);
		}

		// validate(k, ans);
	}
	
	return 0;
};
// orang tambah 2, lalu flip 4 bit, ga nambah 1 atau 0
// 111110011
// 111111100
/*
temp tc:
1000000000 899899885
536870911 536870911

*/