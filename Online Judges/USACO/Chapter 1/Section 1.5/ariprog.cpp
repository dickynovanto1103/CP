/*
ID: dickyno1
LANG: C++14
TASK: ariprog
*/

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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isBisquare[150000];

int main(){
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	//1 5 9 13 17

	int n,m,i,j;
	scanf("%d %d",&n,&m);
	
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
			isBisquare[i*i + j*j] = true;
		}
	}

	vi bisquare;

	for(i=0;i<130000;i++){
		if(isBisquare[i]){
			bisquare.pb(i);
		}
	}

	int maksBisquare = bisquare[bisquare.size() - 1];

	// printf("size: %d\n",bisquare.size());

	int banyakBisquare = bisquare.size();
	set<int> setSelisih;
	int cnt = 0;
	bool done = false;
	bool found = false;
	for(i=1;i<125000;i++) {
		int selisih = i;
		for(j=0;j<banyakBisquare;j++) {
			int bil = bisquare[j];
			if(bil + (n-1) * selisih > maksBisquare) break;
			int cari = n;
			bool valid = true;
			while(cari-- && valid) {
				if(bil > maksBisquare || !isBisquare[bil]) {
					valid = false;
					break;
				}
				bil += selisih;
			}
			if(valid) {
				printf("%d %d\n", bisquare[j], selisih);
				found = true;
				cnt++;
				if(cnt >= 10000) {
					assert(false);
					done = true;
					break;	
				}
			}
			
			// setSelisih.pb(selisih);
		}
		if(done) break;
	}

	if(!found){
		puts("NONE");
	}
	

	
	return 0;
};