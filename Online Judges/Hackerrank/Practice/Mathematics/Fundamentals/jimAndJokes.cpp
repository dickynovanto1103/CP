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

bool isValid(int base, int bil){
	while(bil>0){
		int angka = bil%10;
		if(angka>=base){return false;}
		bil/=10;
	}
	return true;
}

int convert(int base, int bil){
	vi listAngka;
	int i;
	while(bil>0){
		int angka = bil%10;
		listAngka.pb(angka);
		bil/=10;
	}
	int ukuran = listAngka.size();
	int ans = 0;
	for(i=ukuran-1;i>=0;i--){
		ans += listAngka[i]*pow(base,i);
	}
	return ans;
}

int main(){
	int n,i,j;
	int counter[100000];
	memset(counter,0,sizeof counter);
	set<int> s;
	set<int>::iterator it;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int m,d;
		scanf("%d %d",&m,&d);
		if(isValid(m,d)){
			//convert ke angka desimal
			int bilangan = convert(m,d);
			//printf("bil: %d\n",bilangan);
			s.insert(bilangan);
			counter[bilangan]++;
		}
	}
	ll ans = 0;
	for(it=s.begin();it!=s.end();it++){
		int bil = *it;
		ll banyak = (ll)counter[bil];
		ans += (banyak*(banyak-1))/2LL;
	}
	printf("%lld\n",ans);
	return 0;
};