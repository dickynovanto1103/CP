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

int main(){
	int n, x;
	while(scanf("%d %d",&n,&x) != EOF) {
		set<int> s;
		set<int>::iterator it;
		int maks = x;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(s.size() == 0){
				s.insert(a); s.insert(b);
			}else{

				vector<int> v;
				for(it = s.begin();it!=s.end();it++){
					int bil = *it;
					v.pb(bil);
				}

				s.clear();
				for(int bil: v) {
					if(bil + a <= maks){s.insert(bil + a);}
					if(bil + b <= maks){s.insert(bil + b);}
				}
			}
		}

		if(s.find(x) != s.end()) {
			puts("Yes");
		}else{
			puts("No");
		}
	}
	
	
	return 0;
};