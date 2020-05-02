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

ii finalKoor(ii awal, char kar) {
	if(kar == 'N'){
		awal.second++;
	}else if(kar == 'S'){
		awal.second--;
	}else if(kar == 'E'){
		awal.first++;
	}else{
		awal.first--;
	}
	return awal;
}

int main(){
	int tc, i,j, n, m;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&m);
		string s;
		cin>>s;
		// map<ii, vi> mapper;
		vii v;
		ii koor = ii(n,m);
		for(i=0;i<s.size();i++){
			koor = finalKoor(koor, s[i]);
			// mapper[koor].pb(i+1);
			v.pb(koor);
		}
		int ans = -1;
		for(i=0;i<v.size();i++){
			int time = i+1;
			ii koor = v[i];
			int req = abs(koor.first) + abs(koor.second);
			if(req <= time){
				ans = time;
				break;
			}
		}
		if(ans == -1){printf("IMPOSSIBLE\n");}
		else{printf("%d\n",ans);}
	}
	// for(i=0;i<)
	return 0;
};