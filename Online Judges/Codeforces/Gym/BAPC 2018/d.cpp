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

void minim(int &a, int b){
	a = min(a,b);
}

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
	dist1[a] = 0; dist2[b] = 0;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int front = q.front(); q.pop();
		int kiri = l[front], kanan = r[front];
		if(dist1[kiri] == inf){
			dist1[kiri] = dist1[front] + 1;
			q.push(kiri);
		}
		if(dist1[kanan] == inf){
			dist1[kanan] = dist1[front] + 1;
			q.push(kanan);
		}
	}
	q.push(b);
	while(!q.empty()){
		int front = q.front(); q.pop();
		int kiri = l[front], kanan = r[front];
		if(dist2[kiri] == inf){
			dist2[kiri] = dist2[front] + 1;
			q.push(kiri);
		}
		if(dist2[kanan] == inf){
			dist2[kanan] = dist2[front] + 1;
			q.push(kanan);
		}
	}
	int jarakMin = inf;
	for(i=0;i<n;i++){
		if(t[i]){
			minim(jarakMin, dist1[i]);
			minim(jarakMin, dist2[i]);
		}
	}
	for(i=0;i<n;i++){
		if(t[i]){
			if(dist1[i] == jarakMin && dist2[i] == jarakMin){
				continue;
			}else if(dist1[i] != jarakMin && dist2[i] == jarakMin){
				printf("%d\n",jarakMin);
				return 0;
			}else if(dist1[i] == jarakMin && dist2[i] != jarakMin){
				printf("%d\n",jarakMin);
				return 0;
			}

		}
	}
	printf("indistinguishable\n");
	return 0;
};