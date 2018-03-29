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

int main(){
	int n,i,j;
	vi a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		a.pb(bil);
	}
	sort(a.begin(), a.end());
	ll biaya = 0;
	while(!a.empty()) {
		bool selesai = false;
		for(i=0;i<3;i++){
			if(a.empty()){
				selesai = true;
				break;
			}else{
				if(i==2){a.pop_back(); break;}
				ll angka = (ll)a.back();
				a.pop_back();
				biaya+=angka;
			}
		}
		if(selesai){break;}
	}
	printf("%lld\n",biaya);
	return 0;
};