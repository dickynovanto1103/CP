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

vector<vi> AdjList;

int main(){
	AdjList.assign(2,vi());
	string kata, dum;
	ll k,q,i,j;
	cin>>dum;
	cin>>kata;
	ll pjg = kata.length();
	
	scanf("%lld %lld",&k,&q);
	string temp = kata;
	for(i=1;i<k;i++){
		kata+=temp;
	}

	ll a[101];
	for(i=1;i<=100;i++){a[i] = 1;}

	ll n = k*pjg + 1LL;
	ll x = (n-1LL)/(pjg);

	ll kiri = 1, kanan = n;
	// printf("kanan: %lld\n",kanan);
	for(i=0;i<kata.length();i++){
		char kar = kata[i];
		if(kar=='A'){
			kanan--;
		}else{
			kiri++;
		}
		for(j=kiri;j<=kanan;j++){
			a[j]++;
			// printf("a[%d] jd: %lld\n",j,a[j]);
		}
	}

	while(q--){
		ll l,r;
		scanf("%lld %lld",&l,&r);
		ll maks = 0;
		for(i=l;i<=r;i++){
			maks = max(maks, a[i]);
		}
		printf("%lld\n",maks);
	}
	return 0;
};