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
	int n,a,b,i,j, tc;
	scanf("%d",&tc);
	int p[101];
	p[1] = -1;
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d %d",&n,&a,&b);
		for(i=2;i<=n;i++){
			scanf("%d",&p[i]);
		}

		int cnt = 0;
		bool marked[101];
		
		
		int totWarna = 0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				memset(marked, false, sizeof marked);
				int warna = 0;
				int node = i;
				int cnt1 = 0;
				while(node != -1) {
					if(cnt1 % a == 0 && !marked[node]){
						marked[node] = true;
						warna++;
					}
					cnt1++;
					node = p[node];
				}
				node = j;
				int cnt2 = 0;
				while(node != -1) {
					if(cnt2 % b == 0 && !marked[node]){
						marked[node] = true;
						warna++;	
					}
					cnt2++;
					node = p[node];
				}
				cnt++;
				totWarna+=warna;
			}
		}
		printf("%.9lf\n",(double)totWarna/(double)cnt);
	}
	return 0;
};