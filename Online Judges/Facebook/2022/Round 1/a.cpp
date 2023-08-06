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

const int maxn = 500000;

vi a, b;

int pre[maxn + 10];

class KMP {
public:
	void preprocess(vi& arr) {
		int len = arr.size();
		int i=0, j = -1; pre[0] = -1;
		while(i < len) {
			while((j >= 0) && (arr[i] != arr[j])) {
				j = pre[j];
			}

			i++; j++;
			pre[i] = j;
		}
	}

	int search(vi& big, vi& small) {
		int freq = 0;
		int i = 0, j = 0;
		int n = big.size();
		int m = small.size();
		while(i < n) {
			while((j >= 0) && (big[i] != small[j])) {
				j = pre[j];
			}

			//same
			i++; j++;
			if(j == m) {
				freq++;
				j = pre[j];
			}
		}

		return freq;
	}
};

bool isSame(vi& a, vi& b) {
	int n = b.size();
	for(int i=0;i<n;i++){
		if(a[i] != b[i]) {
			return false;
		}
	}

	return true;
}

void cetakVector(vi a) {
	for(int bil: a) {
		printf("%d ", bil);
	}
	puts("");
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n,k;
		scanf("%d %d",&n,&k);

		a.clear();
		b.clear();
		for(int i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			a.pb(bil);
		}

		for(int i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			b.pb(bil);
		}

		if(k == 0) {
			if(isSame(a, b)){
				puts("YES");
			}else{
				puts("NO");
			}
			continue;
		}
		//case of k > 0

		for(int i=0;i<n;i++){
			a.pb(a[i]);
		}
		// cetakVector(a);
		// cetakVector(b);

		KMP algo;
		algo.preprocess(b);

		int foundTimes = algo.search(a, b);
		//make several cases, particularly for len 2
		if(n == 2) {
			if(foundTimes == 0) {
				printf("ga mungkin masuk sini\n");
				assert(false);
			}else if(foundTimes == 1){
				if(k % 2 == 1) {puts("YES");}
				else{puts("NO");}
			}else if(foundTimes == 2) {
				if(k % 2 == 0){puts("YES");}
				else{puts("NO");}
			}else if(foundTimes == 3) {
				puts("YES");
			}
		}else{
			if(foundTimes) {
				if(foundTimes == 2 && k == 1){
					puts("NO");
				}else{
					puts("YES");
				}
			}else{
				puts("NO");
			}
		}
	}
	
	return 0;
};