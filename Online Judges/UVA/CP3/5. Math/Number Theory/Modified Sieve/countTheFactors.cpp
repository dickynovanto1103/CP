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

const int maxn = 1e6;
bool isprime[maxn+10];
int numPF[maxn+10];
int prime[78500];
void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main(){
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int i,j;
	int cnt = 0;
	for(i=1;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = i;
			cnt++;
		}
	}
	numPF[1] = 0;
	for(i=0;i<cnt;i++){
		int bil = prime[i];
		for(j=bil;j<=maxn;j+=bil){
			numPF[j]++;
		}
	}
	int input;
	while(scanf("%d",&input), (input!=0)){
		printf("%d : %d\n",input,numPF[input]);
	}
	return 0;
};