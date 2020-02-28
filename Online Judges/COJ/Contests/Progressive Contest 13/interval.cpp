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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		multiset<int> s;
		multiset<int>::iterator it;
		s.insert(-1); s.insert(100001);
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			s.insert(bil);
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int type, bil;
			scanf("%d %d",&type, &bil);
			if(type == 1){
				//query
				int minim = *(--s.lower_bound(bil));
				int maks = *s.upper_bound(bil);
				printf("%d %d\n",minim, maks);
			}else if(type == 2){
				//insert
				s.insert(bil);
			}else{
				it = s.find(bil);
				if(it != s.end()){
					s.erase(it);
				}
			}
		}
	}
	return 0;
};