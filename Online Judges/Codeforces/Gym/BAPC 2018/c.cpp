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
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
	int n,i,j,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int l[maxn], r[maxn], t[maxn];
	for(i=0;i<n;i++){
		scanf("%d %d %d",&l[i],&r[i],&t[i]);
	}
	int dist1[maxn], dist2[maxn];
	fill(dist1, dist1+maxn, inf);
	fill(dist2, dist2+maxn, inf);
	queue<int> q1,q2;
	q1.push(a); q2.push(b);
	while
	return 0;
};