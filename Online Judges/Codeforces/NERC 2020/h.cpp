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

int b[200010];
bool isB[200010];
int pref[200010];

int main(){
	int tc,i,j,n,k,m;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d %d",&n,&k,&m);
		for(i=1;i<=n;i++){
			isB[i] = false;
			pref[i] = 0;
		}
		for(i=0;i<m;i++){
			scanf("%d",&b[i]);
			isB[b[i]] = true;
		}
		if((n - m)%(k-1) != 0){
			printf("NO\n");
			continue;
		}
		for(i=1;i<=n;i++){
			if(!isB[i]){
				pref[i]++;
			}
			pref[i] += pref[i-1];
		}

		bool found = false;
		for(i=0;i<m;i++){
			int idx = b[i];
			int banyakAKiri = pref[idx];
			int banyakAKanan = pref[n] - banyakAKiri;
			if(banyakAKiri < (k/2) || banyakAKanan < (k/2)) {
				continue;
			}
			found = true;
			break;
			// printf("i: %d k/2: %d\n", i, k/2);
			// if(banyakAKiri % (k/2) == 0 && banyakAKanan % (k/2) == 0){
			// 	found = true;
			// 	break;
			// }
		}

		if(found){printf("YES\n");}
		else{printf("NO\n");}
	}
	
	return 0;
};