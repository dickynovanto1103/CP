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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 3e4 + 4;

struct pasangan{
	int koor;
	bool isEnd;
	pasangan(int _koor, bool _isEnd) {
		koor = _koor; isEnd = _isEnd;
	}
};

bool cmp(pasangan a, pasangan b){
	if(a.koor == b.koor) {
		return a.isEnd < b.isEnd;
	}
	return a.koor < b.koor;
}

bool isValid(int a, int b, int c) {
	return a >= b && a <= c;
}

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	bool isTaken[maxn];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&q);
		memset(isTaken, false, sizeof isTaken);
		vii listPas;
		
		for(i=0;i<q;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			listPas.pb(ii(x,y));
		}
		for(i=0;i<q;i++){
			if(isTaken[i]){continue;}
			vii listValid;
			vector<pasangan> p;
			for(j=0;j<q;j++){
				if(i == j || isTaken[j]){continue;}
				listValid.pb(ii(x,y));
				p.pb(pasangan(x, false));
				p.pb(pasangan(y, true));
			}
			sort(p.begin(), p.end(), cmp);
			int cnt = 0;
			if(p.size() == 0){continue;}
			int cur = p[0].first;
			int ans = 0;
			for(j=0;j<p.size();j++){
				int koor = p[i].first;
				if(!isValid(koor, p[i].first, p[i].second)) {
					break;
				}
				if(!cnt){

				}
				cur = p[i].first;
			}
		}
	}
	return 0;
};