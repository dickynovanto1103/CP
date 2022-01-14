/*
ID: dickyno1
LANG: C++14
TASK: barn1
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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);

	int m,s,c;
	scanf("%d %d %d",&m,&s,&c);
	int i,j;
	int a[300];
	for(i=0;i<c;i++){
		scanf("%d",&a[i]);
	}
	sort(a, a + c);
	vi listSelisih;
	for(i=0;i<c-1;i++){
		if(a[i+1] - a[i] > 1) {
			listSelisih.pb(a[i+1] - a[i] - 1);
		}
	}

	sort(listSelisih.begin(), listSelisih.end());
	int ans = a[c-1] - a[0] + 1;
	for(i=0;i<m-1;i++){
		if(listSelisih.size() == 0){break;}
		int back = listSelisih.back(); listSelisih.pop_back();
		ans -= back;
	}

	printf("%d\n", ans);
	
	return 0;
};