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

const int maxn = 1e7;

bool isprime[maxn + 4];

void sieve(int n) {
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

int main(){
	memset(isprime, true, sizeof isprime);
	sieve(maxn);
	// FastSlowInput;

	int k;
	char s[1010];
	while(scanf("%d %s",&k,s) !=EOF) {
		int n = strlen(s);
		int bil = 0;
		bool valid = true;
		for(int i=0;i<n;i++){
			if(i%k == 0){
				if(i != 0){
					if(!isprime[bil]){valid = false; break;}
				}
				bil = 0;
				bil = s[i] - '0';
			}else{
				bil *= 10;
				bil += s[i] - '0';
			}
		}
		if(valid){printf(":)\n");}
		else{printf(":(\n");}
	}
	return 0;
};