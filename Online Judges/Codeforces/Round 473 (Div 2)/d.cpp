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
bool isprime[maxn+4];
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
	int cnt = 0;
	bool isVisited[100000];
	memset(isVisited,false,sizeof isVisited);

	for(i=2;i<=maxn;i++){
		if(isprime[i]){
			prime[cnt] = 0;
			
			cnt++;
		}
	}
	int n;
	scanf("%d",&n);
	int a[100010];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bool sudahLebihBesar = false;
	vi b;
	int idxMulai;
	for(i=0;i<n;i++){
		if(!sudahLebihBesar){
			int idx = lower_bound(prime,prime+cnt,a[i]) - prime;
			int bilPrima = prime[idx];	
			b.pb(bilPrima);
			isVisited[idx] = true;
			if(bilPrima > a[i]){
				sudahLebihBesar = true;	
				//cari index terendah yang masih false
				for(j=0;j<cnt;j++){
					if(!isVisited[j]){
						idxMulai = j; break;
					}
				}
			}
			s.erase(bilPrima);
		}else{
			for(j=idxMulai;j<cnt;j++){
				if(isVisited[j]){continue;}
				b.pb(prime[j]);
				isVisited[j] = true;
				idxMulai = j+1;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	return 0;
};