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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int bef(int idx, int n) {
	idx--;
	if(idx < 0) idx += n;
	return idx;
}

int af(int idx, int n) {
	idx++;
	idx %= n;
	return idx;
}

vi try1(int a[], int n) {
	vi res(n);
	int idx = 0;
	for(int i=n/2;i<n;i++){
		res[idx] = a[i];
		idx+=2;
	}

	idx = 1;
	for(int i=0;i<(n/2);i++){
		res[idx] = a[i];
		idx+=2;
	}

	return res;
}

vi try2(int a[], int n) {
	vi res(n);
	int idx = 0;
	for(int i=0;i<n/2;i++){
		res[idx] = a[i];
		idx+=2;
	}

	idx = 1;
	for(int i=n/2;i<n;i++){
		res[idx] = a[i];
		idx+=2;
	}

	return res;
}

bool validate(vi res) {
	int n = res.size();

	for(int i=0;i<n;i++){
		if((res[i] > res[bef(i, n)] && res[i] > res[af(i, n)]) || (res[i] < res[bef(i, n)] && res[i] < res[af(i, n)])) continue;
		
		return false;
	}

	return true;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[100010];
	while(tc--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a, a+n);
		// printf("n: %d\n", n);

		// bool valid = false;
		// do {
		// 	vi res(n);
		// 	for(int i=0;i<n;i++) res[i] = a[i];
		// 	if(validate(res)) {
		// 		valid = true;
		// 		printf("YES\n");
		// 		for(int v : res) {
		// 			printf("%d ", v);
		// 		}
		// 		puts("");
		// 		break;
		// 	}
		// }while(next_permutation(a, a+n));
		
		// if(!valid){
		// 	printf("NO\n");
		// }

		if(n % 2 == 1){
			puts("NO");
			continue;
		}

		vi res = try1(a, n);

		if(validate(res)) {
			puts("YES");
			for(int i=0;i<n;i++){
				printf("%d ", res[i]);
			}
			puts("");
			continue;
		}

		res = try2(a, n);
		if(validate(res)) {
			puts("YES");
			for(int i=0;i<n;i++){
				printf("%d ", res[i]);
			}
			puts("");
			continue;
		}

		puts("NO");

		// if(n % 2 == 0) {
		// 	puts("NO");
		// 	continue;
		// }
		// res = try2(a, n);
		// // for(int a: res) {
		// // 	printf("%d ", a);
		// // }
		// // puts("");

		// if(validate(res)) {
		// 	puts("YES");
		// 	for(int i=0;i<n;i++){
		// 		printf("%d ", res[i]);
		// 	}
		// 	puts("");
		// }else{
		// 	puts("NO");
		// }
	}
	
	return 0;
};