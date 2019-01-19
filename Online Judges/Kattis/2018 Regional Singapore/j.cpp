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

const int maxn = 105;

int main(){
	int n,i,j;
	ii a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		for(j=a[i].)
	}
	sort(a,a+n);

	int last = a[0].second;
	int tot = 0;
	int first = a[0].first;
	for(i=1;i<n;i++){
		if(last<=a[i].first){
			last = a[i].second;
		}else{
			tot += (last - first + 1);
			first = a[i].first;

		}
		last = a[i].second;
	}
	tot += (last - first + 1);
	printf("%d\n",tot);
	return 0;
};