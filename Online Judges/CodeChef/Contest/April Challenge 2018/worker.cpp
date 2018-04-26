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

const int maxn = 1e3 + 3;

int main(){
	int n,t[maxn], a[maxn];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	int minim[4];
	fill(minim,minim+4,inf);
	for(i=0;i<n;i++){
		minim[t[i]] = min(minim[t[i]], a[i]);
	}
	int ans;
	if((minim[1] + minim[2]) > minim[3]){
		ans = minim[3];
	}else{
		ans = (minim[1] + minim[2]);
	}
	printf("%d\n",ans);
	return 0;
};