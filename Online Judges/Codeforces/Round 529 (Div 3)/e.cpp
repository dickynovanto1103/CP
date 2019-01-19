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

const int maxn = 1e6 + 6;
int pref[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

ii st[4*maxn];

void build(int node, int l, int r){
	if(l == r){
		st[node] = ii(pref[l], pref[l]);
		return;
	}
	int mid = (l+r)/2;
	build(left(node), l, mid);
	build(right(node), mid+1, r);
	ii ans1 = st[left(node)];
	ii ans2 = st[right(node)];
	st[node] = ii(min(ans1.first, ans2.first), max(ans1.second, ans2.second));
}

ii query(int node, int l, int r, int i, int j){
	if(i > j){return ii(inf,inf);}
	if(j < l || r < i){return ii(inf,inf);}
	if(i <= l && r <= j){return st[node];}
	int mid = (l+r)/2;
	ii ans1 = query(left(node), l, mid, i, j);
	ii ans2 = query(right(node), mid+1, r, i, j);
	if(ans1 == ii(inf,inf)){return ans2;}
	if(ans2 == ii(inf,inf)){return ans1;}
	ii ans = ii(min(ans1.first, ans2.first), max(ans1.second, ans2.second));
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata;
	cin>>kata;
	if(n == 1){printf("0\n"); return 0;}
	for(i=1;i<=n;i++){
		pref[i] = (kata[i-1] == ')' ? -1 : 1);
	}
	for(i=2;i<=n;i++){
		pref[i] += pref[i-1];
	}
	// for(i=1;i<=n;i++){
	// 	printf("pref[%d]: %d\n",i,pref[i]);
	// }
	int firstNegative = -1;
	for(i=1;i<=n;i++){
		if(pref[i] < 0){firstNegative = i; break;}
	}
	if(firstNegative == -1){firstNegative = n;}
	build(1,1,n);
	int cnt = 0;

	for(i=1;i<=firstNegative;i++){
		char kar = kata[i-1];
		// printf("i: %d kar: %c\n",i,kar);
		if(kar == '('){
			//akan berkurang 2
			if(pref[i] < 2){continue;}
			if(i == n){
				if(pref[i] - 2 == 0){cnt++;}
			}else {
				ii ans = query(1,1,n,i+1,n);
				// printf("ans: %d %d\n",ans.first, ans.second);
				int minim = ans.first;
				if(minim >= 2) {
					if(pref[n] - 2 == 0){cnt++;}
				}
			}
			

		}else{
			if(pref[i] + 2 < 0){continue;}
			if(i == n){
				continue;
			}else{
				ii ans = query(1,1,n,i+1,n);
				// printf("ans: %d %d\n",ans.first, ans.second);
				int minim = ans.first;
				if(minim + 2 >= 0){
					if(pref[n] + 2 == 0){
						// printf("halo\n");
						cnt++;
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};