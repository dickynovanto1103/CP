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

ll modPow(ll a, ll b, ll c) {
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a, b-1, c) % c;}
		else{
			ll temp = modPow(a, b/2, c);
			return temp*temp%c;
		}
	}
}

bitset<10000010> vis;

int main(){
	int b,c;
	ll a, n;
	scanf("%lld %d %d %lld",&a,&b,&c,&n);
	if(a == 0){printf("1\n"); return 0;} //bener
	if(b == 0){printf("%d\n",(1%n)+1); return 0;} //bener
	if(c == 0){printf("%lld\n",modPow(a, 1, n) + 1); return 0;} //bener
	ll temp = a;
	vector<long long> list;
	// list.pb(1);
	// vis[1] = true;
	while(!vis[a]){
		// if(a == 1){list.insert(list.begin(), 1); break;}
		list.pb(a);
		vis[a] = true;
		a *= temp;
		a %= n;
	}
	int i,j;
	// for(i=0;i<list.size();i++){
	// 	printf("%d ",list[i]);
	// }
	// printf("\n");

	//search b^c mod list.Size()
	int ukuran = list.size();
	assert(ukuran > 0);
	ll idxPangkat = modPow(b, c, ukuran);
	idxPangkat--;
	if(idxPangkat < 0){idxPangkat += ukuran;}
	// ll jawab = modPow(temp, idxPangkat, n);
	printf("%lld\n",list[idxPangkat] + 1);
	return 0;
};