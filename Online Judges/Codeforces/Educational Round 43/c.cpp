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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 3e5 + 5;

bool cmp(iii a, iii b) {
	if(a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	iii a[maxn];
	for(i=1;i<=n;i++){
		scanf("%d %d",&a[i].second.first,&a[i].second.second);
		a[i].first = i;
	}

	sort(a+1,a+n+1,cmp);

	// for(i=1;i<=n;i++){
	// 	printf("%d %d %d\n",a[i].first,a[i].second.first,a[i].second.second);
	// }
	for(i=1;i<n;i++){
		iii pas1 = a[i];
		iii pas2 = a[i+1];
		int l2 = pas1.second.first, r2 = pas1.second.second;
		int l1 = pas2.second.first, r1 = pas2.second.second;
		if(l1==l2) {
			if(r2<=r1){
				printf("%d %d\n",pas1.first, pas2.first);
				return 0;
			}
		}
		if(l1>=l2 && r1<=r2) {
			printf("%d %d\n",pas2.first, pas1.first);
			return 0;
		}

		
	}
	printf("-1 -1\n");

	return 0;
};