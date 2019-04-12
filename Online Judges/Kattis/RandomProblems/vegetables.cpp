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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

int main(){
	double ratio;
	int i,j;
	int n;
	scanf("%lf %d",&ratio, &n);
	priority_queue<ii> pq;
	double minim = 1e9;
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		pq.push(ii((double)a[i], i));
		minim = min(minim, (double)a[i]);
	}
	int ans = 0;
	vi bagi(n, 1);
	while(1){
		ii front = pq.top(); pq.pop();
		double bil = front.first;
		int idx = front.second;
		if(minim/bil > ratio){break;}
		bagi[idx]++;
		ans++;
		double baru = (double)a[idx] / (double)bagi[idx];
		minim = min(minim, baru);
		pq.push(ii(baru, idx));
	}
	printf("%d\n",ans);
	return 0;
};