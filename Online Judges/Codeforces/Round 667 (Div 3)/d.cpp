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

int sumDigits(ll n){
	int ans = 0;
	while(n){
		int bil = n % 10LL;
		n /= 10LL;
		ans += bil;
	}
	return ans;
}

int main(){
	int tc,i,j;
	ll n;
	int s;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %d",&n,&s);
		ll tambah = 0;
		ll plus = 1;
		while(sumDigits(n) > s){
			while(n % 10 == 0){
				n /= 10LL;
				plus *= 10LL;
			}
			n++;
			tambah += plus;
		}
		printf("%lld\n",tambah);
	}
	
	return 0;
};