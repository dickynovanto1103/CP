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

const int maxn = 2e5 + 5;

bool isprime[2750141];
int prime[maxn];
int numPrime[2750141];
int divi[maxn];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

bool cmp(int a, int b){
	return a > b;
}

int main(){

	int n,i,j;
	memset(isprime, true, sizeof isprime);
	sieve(2750140);
	int cnt = 1;
	for(i=0;i<2750141;i++){
		if(isprime[i]) {
			prime[cnt] = i;
			numPrime[i] = cnt;
			cnt++;
		}
	}
	// printf("prime: %d %d\n",prime[199999], numPrime[2750131]);

	//preprocess biggest divi
	divi[2] = 1;
	for(i=3;i<maxn;i++){
		// printf("i: %d\n",i);
		bool found = false;
		for(j=1;j*j<=i;j++){
			if(i%j == 0) {
				int div1 = j;
				int div2 = i/j;
				// if(i == 6){printf("%d %d\n",div1, div2);}
				if(div2 != i){divi[i] = div2; found = true; break;}
			}
		}
	}

	multiset<int> s;
	multiset<int>::iterator it;
	// printf("cnt: %d\n",cnt);
	scanf("%d",&n);
	int b[2*maxn];
	for(i=0;i<2*n;i++){
		scanf("%d",&b[i]);
		s.insert(b[i]);
	}
	sort(b, b+2*n, cmp);
	vi ans(n);
	int idx = 0;
	for(i=0;i<2*n;i++){
		it = s.find(b[i]);
		if(it == s.end()){continue;}
		if(isprime[b[i]]){
			// printf("prime\n");
			
			it = s.find(numPrime[b[i]]);
			if(it == s.end()){

			}else{
				ans[idx++] = numPrime[b[i]];
				s.erase(it);
				it = s.find(b[i]);
				s.erase(it);
				// printf("b[%d]: %d dipush %d\n",i,b[i],numPrime[b[i]]);
			}
			
		}else{

			int greatestDiv = divi[b[i]];
			// printf("greatestDiv: %d\n",greatestDiv);
			it = s.find(greatestDiv);
			if(it == s.end()) {

			}else{
				ans[idx++] = b[i];
				s.erase(it);
				it = s.find(b[i]);
				s.erase(it);
				// printf("dipush b[%d]: %d\n", i,b[i]);
			}
		}
	}
	// printf("idx :%d\n",idx);
	assert(idx == n);
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");

	return 0;
};