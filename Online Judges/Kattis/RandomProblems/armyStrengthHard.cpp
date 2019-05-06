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
	int tc,i,j,a,b;
	scanf("%d",&tc);

	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		set<int> s1, s2;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			// printf("dipush: %d\n",bil);
			s1.insert(bil);
		}
		for(i=0;i<m;i++){
			int bil;
			scanf("%d",&bil);
			// printf("dipush 2: %d\n",bil);
			s2.insert(bil);
		}
		while(true){
			if(s1.empty()){printf("MechaGodzilla\n"); break;}
			else if(s2.empty()){printf("Godzilla\n"); break;}
			else{
				int bil1 = *s1.begin(), bil2 = *s2.begin();
				if(bil1 == bil2){
					s2.erase(s2.begin());
				}else if(bil1 < bil2){
					s1.erase(s1.begin());
				}else {
					s2.erase(s2.begin());
				}
			}	
		}
		
	}
	return 0;
};
