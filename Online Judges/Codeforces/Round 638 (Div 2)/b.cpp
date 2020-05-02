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

int main(){
	int tc,i,j,k,n;
	int a[101];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		set<int> s;
		set<int>::iterator it;
		for(i=0;i<n;i++){scanf("%d",&a[i]); s.insert(a[i]);}
		if(s.size() > k){printf("-1\n"); continue;}
		vi v;
		for(it = s.begin(); it!=s.end();it++){
			v.pb(*it);
		}
		int banyak = v.size();
		int idx = 0;
		while(v.size() < k){
			v.pb(v[idx]);
			idx++;
			idx %= banyak;
		}
		banyak = 10000;
		printf("%d\n",banyak);
		idx = 0;
		for(i=0;i<banyak;i++){
			if(i){printf(" ");}
			printf("%d",v[idx]);
			idx++;
			idx %= v.size();
		}
		printf("\n");

	}
	
	return 0;
};