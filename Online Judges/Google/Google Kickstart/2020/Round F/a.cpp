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

bool cmp(ii a, ii b) {
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main(){
	int tc,i,j,n,x;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:",tt);
		scanf("%d %d",&n,&x);
		vii a;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			int banyakKali = (bil + x - 1) / x;
			a.pb(ii(banyakKali, i+1));
		}
		sort(a.begin(), a.end(), cmp);
		for(i=0;i<n;i++){
			printf(" %d",a[i].second);
		}
		printf("\n");
	}
	
	return 0;
};