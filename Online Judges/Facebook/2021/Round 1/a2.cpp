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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 800010;
const ll mod = 1e9 + 7;

int cntArr[maxn];
int cntNum[maxn];
char nextSigChar[maxn];

void resetArr(int n) {
	for(int i=0;i<=n;i++){
		cntArr[i] = -1;
		cntNum[i] = 0;
		nextSigChar[i] = 'a';
	}
}

ll add(ll a, ll b) {
	a += b;
	if(a < 0) {
		a += mod;
	}
	return a % mod;
}

void genNextSignificantChar(int n, string s) {
	char sigChar = 'a';
	for(int i = n-1; i>=0;i--) {
		if(sigChar != s[i] && (s[i] == 'X' || s[i] == 'O')) {
			sigChar = s[i]; 
		}
		nextSigChar[i] = sigChar;

	}
	// for(int i=0;i<n;i++){
	// 	printf("nextSigChar[%d]: %c\n",i, nextSigChar[i]);
	// }
}

bool isSignificantChar(char c) {
	return c == 'X' || c == 'O';
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		scanf("%d",&n);

		resetArr(n);
		string s;
		cin>>s;

		genNextSignificantChar(n, s);

		char last = 'a';
		int cnt = 0;
		for(i=0;i<n;i++){
			if(s[i] == 'X' || s[i] == 'O') {
				if(last != s[i]) {
					cnt++;
					last = s[i];
				}
			}
			int realCnt = max(cnt-1, 0);
			cntArr[i] = realCnt;
			cntNum[realCnt]++;
			// printf("cntArr[%d]: %d\n", i, cntArr[i]);
		}

		ll sum = 0;
		int cntNot0 = 0;
		for(i=0;i<n;i++){
			sum = add(sum, cntArr[i]);
			if(cntArr[i] > 0){cntNot0++;}
		}
		ll totalSum = sum;


		int idx = 1;
		for(i=1;i<n;i++){
			if(isSignificantChar(s[i-1]) && isSignificantChar(nextSigChar[i]) && nextSigChar[i] != s[i-1]) {
				totalSum = add(totalSum, -cntNot0);

				
				assert(totalSum >= 0);
				//reduce cntNot0
				cntNot0 -= cntNum[idx++];
				assert(cntNot0 >= 0);
				// if(totalSum < 100) {
				// 	printf("totalSum: %lld cntNot0: %d\n", totalSum, cntNot0);	
				// }
			}

			sum = add(sum, totalSum);
			// printf("i: %d totalSum: %lld sum jadi: %lld\n", i, totalSum, sum);
		}

		printf("%lld\n", sum);
		assert(0 <= sum && sum < mod);
	}
	
	return 0;
};