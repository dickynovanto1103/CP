/*
ID: dickyno1
LANG: C++14
TASK: milk3
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
typedef pair<int,int> ii;
typedef vector<ii> vii;

map<tuple<int, int, int>, bool> vis;
bool ada[21];
int capacity[4];

ii pour(int capa1, int capa2, int a, int b) {
	int sisa = capa2 - b;
	if(a >= sisa) {
		a -= sisa;
		b = capa2;
	}else{
		b += a;
		a = 0;
		
	}
	return ii(a, b);
}

void solve(int a, int b, int c) {
	// printf("inside solve: %d %d %d\n",a, b, c);
	if(vis[make_tuple(a, b, c)]) {
		return;
	}
	vis[make_tuple(a, b, c)] = true;
	if(a == 0) {
		ada[c] = true;
	}

	ii pourRes;
	if(a != 0) {
		//try pouring a to b
		pourRes = pour(capacity[0], capacity[1], a, b);
		// printf("pourRes: %d %d\n", pourRes.first, pourRes.second);
		solve(pourRes.first, pourRes.second, c);
		// //pour a to c
		pourRes = pour(capacity[0], capacity[2], a, c);
		solve(pourRes.first, b, pourRes.second);
	}

	if(b != 0) {
		//try pouring b to a
		pourRes = pour(capacity[1], capacity[0], b, a);
		solve(pourRes.second, pourRes.first, c);
		pourRes = pour(capacity[1], capacity[2], b, c);
		solve(a, pourRes.first, pourRes.second);
	}

	if(c != 0) {
		//c ke a
		pourRes = pour(capacity[2], capacity[0], c, a);
		solve(pourRes.second, b, pourRes.first);
		//c ke b
		pourRes = pour(capacity[2], capacity[1], c, b);
		solve(a, pourRes.second, pourRes.first);
	}
}

int main(){
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	int a,b,c;
	for(int i=0;i<3;i++){
		scanf("%d",&capacity[i]);
	}

	solve(0, 0, capacity[2]);

	vi v;
	for(int i=0;i<=20;i++){
		if(ada[i]){
			v.pb(i);
		}
	}


	for(int i=0;i<v.size();i++){
		if(i){printf(" ");}
		printf("%d", v[i]);
	}
	puts("");
	// for(int i=0;i<3;i++){
	// 	printf("elemen ke %d dari tuple: %d\n", i, get<i>(tup));
	// }
	
	return 0;
};