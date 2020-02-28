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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int ans = 0;
	vi listans;
	for(i=0;i<3;i++){
		int akhir = n + i;
		int mod = akhir%4;
		listans.pb(mod);
	}
	int maks = 0;
	for(i=0;i<3;i++){
		if(listans[i] == 1) {
			printf("%d A\n",i);
			return 0;
		}
	}
	for(i=0;i<3;i++){
		if(listans[i] == 3){
			printf("%d B\n",i);
			return 0;
		}
	}
	return 0;
};