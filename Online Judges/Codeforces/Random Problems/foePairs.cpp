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

const int maxn = 3e5 + 5;
set<int> AdjList[maxn];

int main(){
	int n,m,i,j;
	int a[maxn], idx[maxn];
	scanf("%d %d",&n,&m);
	if(n==1){printf("1\n"); return 0;}
	
	set<int> s;
	set<int>::iterator it;
	for(i=0;i<n;i++){scanf("%d",&a[i]); idx[a[i]] = i;}
	for(i=0;i<m;i++){
		int bil1,bil2;
		scanf("%d %d",&bil1,&bil2);
		int idx1 = idx[bil1], idx2 = idx[bil2];
		int minimIdx = min(idx1,idx2), maksIdx = max(idx1,idx2);
		s.insert(minimIdx);
		AdjList[minimIdx].insert(maksIdx);
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		it = s.lower_bound(i);
		if(it==s.end()){
			ans+=(n-i);
		}else{
			int idxMinPas = *(AdjList[*it].begin());
			int idxKaji;
			if(i<(n-1)){
				it = s.lower_bound(i+1);
				if(it==s.end()){
					idxKaji = idxMinPas;
				}else{
					int idxMinPas2 = *(AdjList[*it].begin());
					idxKaji = min(idxMinPas,idxMinPas2);
				}
			}
			ans+=(idxKaji-i);
			// printf("i: %d idx: %d\n",i,*it);	
			// printf("i: %d idxMinPas: %d\n",i,idxMinPas);
		}
		
	}
	printf("%lld\n",ans);

	return 0;
};