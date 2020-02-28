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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

bool cmp1(iii a, iii b){
	return a.first.second > b.first.second;
}

bool cmp2(iii a, iii b){
	return a.first.second < b.first.second;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ii pas[n+1];
	viii naik, turun;
	for(i=1;i<=n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a > b) {turun.pb(iii(ii(a,b),i));}
		else{naik.pb(iii(ii(a,b), i));}
	}
	sort(turun.begin(), turun.end(), cmp2);
	sort(naik.begin(), naik.end(), cmp1);
	if(turun.size() > naik.size()) {
		printf("%d\n", (int)turun.size());
		for(i=0;i<turun.size();i++){
			printf("%d ", turun[i].second);
		}
		printf("\n");
	}else{
		printf("%d\n", (int)naik.size());
		for(i=0;i<naik.size();i++){
			printf("%d ", naik[i].second);
		}
		printf("\n");
	}
	// printf("%d\n",max(naik.size(), turun.size()));
	return 0;
};