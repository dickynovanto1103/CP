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

int digitPertama;

int banyakDigit(ll n){
	int cnt = 0;
	while(n>0){
		int bil = n%10;
		digitPertama = bil;
		n/=10;
		cnt++;
	}
	return cnt;
}

int jumlahDigit(ll a, ll b){
	int sum = 0;
	while(a>0){
		int bil = a%10;
		sum += bil;
		a/=10;
	}
	while(b>0){
		int bil = b%10;
		sum += bil;
		b/=10;
	}
	return sum;
}

int main(){
	ll n;
	scanf("%lld",&n);
	int cntDigit = banyakDigit(n);
	ll bilMaks = 0;
	int i,j;
	for(i=0;i<cntDigit;i++){
		bilMaks *= 10LL;
		bilMaks += 9LL;
	}

	if(n == bilMaks){
		printf("%d\n",cntDigit*9);
	}else{
		bilMaks/=10;
		ll bilBaru = digitPertama-1;
		for(i=0;i<(cntDigit-1);i++){
			bilBaru*=10LL;
		}
		bilBaru += bilMaks;
		ll sisa = n - bilBaru;
		printf("%d\n", jumlahDigit(bilBaru, sisa));
	}
	return 0;
};