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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int a[maxn];

	while(tc--){
		int n,r;
		scanf("%d %d",&n,&r);
		vi a;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			a.pb(bil);
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		int ans = a.size();
		int last = a[0];
		for(i=1;i<a.size();i++){
			int sisa = (int)a.size() - i;
			int banyakKiri = (last+r-1)/r;

			ans = min(ans, max(banyakKiri, sisa));
			// printf("i: %d banyakKiri: %d sisa: %d ans: %d\n",i, banyakKiri, sisa, ans);
			last = a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
};