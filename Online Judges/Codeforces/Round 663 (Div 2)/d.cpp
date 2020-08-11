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

string s[1000001];
int a[500001];

int convertBinaryStrToInt(string s) {
	int pengali = 1;
	int ans = 0;
	for(int i=s.size()-1;i>=0;i--){
		ans += (pengali*(s[i] - '0'));
		pengali *= 2;
	}
	return ans;
}

int dp[500001][9]; //dp[idx][mask]
string temp[500001];

void compute(int prev, int now, int i) {
	int beda = __builtin_popcount(now ^ a[i]);
	dp[i][now] = min(dp[i][now], dp[i-1][prev] + beda);
}

int main(){
	int n,m,i,j;	
	scanf("%d %d",&n,&m);
	int minim = min(n,m);
	if(minim == 1){printf("0\n"); return 0;}
	if(minim >= 4){printf("-1\n"); return 0;}
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	for(i=0;i<500000;i++){
		for(j=0;j<8;j++){
			dp[i][j] = inf;
		}
	}

	if(n == minim){
		//convert it to menurun ke bawah
		for(j=0;j<m;j++){
			string st;
			for(i=0;i<n;i++){
				st += s[i][j];
			}
			temp[j] = st;
		}
		for(j=0;j<m;j++){
			s[j] = temp[j];
		}
		swap(n,m);
	}


	for(i=0;i<n;i++){
		string st;
		for(j=0;j<m;j++){
			st += s[i][j];
		}
		a[i] = convertBinaryStrToInt(st);
	}

	for(i=0;i<(1<<m);i++){
		int sor = i ^ a[0];
		int bit = __builtin_popcount(sor);
		dp[0][i] = bit;
		// printf("dp[0][%d]: %d\n",i, dp[0][i]);
	}

	for(i=1;i<n;i++){
		for(j=0;j<(1<<m);j++){ //try now if the bil is j
			//check if it is 3 digits / 2 digits, if 2 digits, then we can just do sor and builtint
			//if it is 3 digits, then need to do 2 extra operations:
			// 1. mod by 4, then do sor and builtin popcount
			// 2. if the integer is odd, decrease by 1, then sor and count bit
			for(int k=0;k<(1<<m);k++){ //check if previous bil is k
				if(m == 2){
					int sor = k ^ j;
					int count = __builtin_popcount(sor);
					if(count % 2 == 1){
						compute(k, j, i);	
					}
					
				} else {
					assert(m == 3);
					int realPrev = k;
					int realNow = j;
					int prev = k;
					int now = j;
					//do mod by 4;
					prev %= 4; now %= 4;
					int sor = now ^ prev;
					int count1 = __builtin_popcount(sor);
					// compute(prev, now, i, realPrev, realNow);

					// do reduce by 1 if odd
					prev = k; now = j;
					if(prev % 2 == 1){prev--;}
					if(now % 2 == 1){now--;}
					sor = now ^ prev;
					int count2 = __builtin_popcount(sor);

					if(count1 % 2 == 1 && count2 % 2 == 1) {
						compute(realPrev, realNow, i);
					}
				}
			}
		}
	}

	// printf("%d %d\n",dp[1][3], dp[2][6]);

	minim = inf;
	for(j=0;j<(1<<m);j++){
		minim = min(minim, dp[n-1][j]);
	}
	printf("%d\n",minim);

	return 0;
};