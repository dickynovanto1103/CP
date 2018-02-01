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
	int n,m,i,j;
	unordered_map<int,int> mapper;
	int start = 1, end;
	vi a;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		int banyakMain, durasi;
		scanf("%d %d",&banyakMain,&durasi);
		int selisih = (banyakMain*durasi);
		end = start+selisih-1;
		a.pb(start); a.pb(end);
		mapper[start] = i; mapper[end] = i;
		start = end+1;
	}
	for(i=1;i<=m;i++){
		int time;
		scanf("%d",&time);
		int idx = lower_bound(a.begin(),a.end(),time) - a.begin();
		int waktu = a[idx];
		printf("%d\n",mapper[waktu]);
	}

	return 0;
};