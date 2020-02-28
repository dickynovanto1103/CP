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
typedef pair<ll,ii> iii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	ll k;
	scanf("%d %d %lld",&n,&m,&k);
	if(n > m){swap(n,m);}
	ll kurang = 23;
	ll tambah = 1;
	int maxWidth = max(n,m);
	int kolBawah = m, kolAtas = m, rowBawah = n;

	for(i=1;i<maxWidth;i++){
		k -= i;
		if(k > 0){
			kolBawah--;
		}else{
			k += i;
			break;
		}
	}
	
	if(i != maxWidth) {
		for(i=rowBawah;i>=1;i--){

			kolBawah++;
		}
	}
	while(kolBawah > 1){
		k -= 
	}
	while(k > 0) {
		k -
	}
	return 0;
};