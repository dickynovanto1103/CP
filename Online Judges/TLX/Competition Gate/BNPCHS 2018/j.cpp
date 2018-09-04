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

const int maxn = 1e5 + 5;

int stMin[4*maxn], stMaks[4*maxn];
int a[maxn];
int kiri[maxn], kanan[maxn], lastKiri[maxn], lastKanan[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void buildMin(int node, int l, int r){
	if(l == r){
		stMin[node] = lastKanan[l];
	}else{
		int mid = (l+r)/2;
		buildMin(left(node), l, mid);
		buildMin(right(node), mid+1, r);
		stMin[node] = min(stMin[left(node)], stMin[right(node)]);
	}
}

int queryMin(int node, int l, int r, int i, int j){
	if(r < i || l > j){return inf;}
	if(i <= l && r<=j){return stMin[node];}
	int mid = (l+r)/2;
	int ans1 = queryMin(left(node), l, mid, i, j);
	int ans2 = queryMin(right(node), mid+1, r, i, j);
	return min(ans1,ans2);
}

void updateMin(int node, int l, int r, int idx, int val){
	if(r<idx || l>idx){return;}
	if(l == idx && idx == r){
		stMin[node] = val;
		lastKanan[idx] = val;
	}else{
		int mid = (l+r)/2;
		updateMin(left(node), l, mid, idx, val);
		updateMin(right(node), mid+1, r, idx, val);
		stMin[node] = min(stMin[left(node)], stMin[right(node)]);
	}
}

void buildMaks(int node, int l, int r){
	if(l == r){
		stMaks[node] = lastKiri[l];
	}else{
		int mid = (l+r)/2;
		buildMaks(left(node), l, mid);
		buildMaks(right(node), mid+1, r);
		stMaks[node] = max(stMaks[left(node)], stMaks[right(node)]);
	}
}

int queryMaks(int node, int l, int r, int i, int j){
	if(r < i || l > j){return -1;}
	if(i <= l && r<=j){return stMaks[node];}
	int mid = (l+r)/2;
	int ans1 = queryMaks(left(node), l, mid, i, j);
	int ans2 = queryMaks(right(node), mid+1, r, i, j);
	return max(ans1,ans2);
}

void updateMaks(int node, int l, int r, int idx, int val){
	if(r<idx || l>idx){return;}
	if(l == idx && idx == r){
		stMaks[node] = val;
		lastKiri[idx] = val;
	}else{
		int mid = (l+r)/2;
		updateMaks(left(node), l, mid, idx, val);
		updateMaks(right(node), mid+1, r, idx, val);
		stMaks[node] = max(stMaks[left(node)], stMaks[right(node)]);
	}
}

int main(){
	int tc,tt,i,j;
	scanf("%d",&tc);
	
	for(tt=1;tt<=tc;tt++){
		printf("Kasus #%d:",tt);
		int n;
		scanf("%d",&n);
		memset(lastKiri, -1, sizeof lastKiri);
		for(i=1;i<maxn;i++){
			lastKanan[i] = inf;
		}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		buildMin(1,1,100000);
		buildMaks(1,1,100000);
		lastKiri[a[0]] = 0;
		kiri[0] = 0;
		// printf("lastKiri[%d]: %d\n",a[0],0);
		updateMaks(1,1,100000,a[0],0);
		for(i=1;i<n;i++){
			int bil = a[i];
			//cari maks 
			int ans = queryMaks(1,1,100000,bil,100000);
			// printf("i: %d bil: %d ans: %d\n",i,bil,ans);
			if(ans == -1){
				kiri[i] = 0;
			}else{
				kiri[i] = ans+1;
			}
			// printf("kiri[%d] jadi: %d\n",i,kiri[i]);			
			lastKiri[bil] = i;
			updateMaks(1,1,100000,bil,i);
		}

		lastKanan[a[n-1]] = n-1;
		kanan[n-1] = n-1;
		updateMin(1,1,100000,a[n-1],n-1);
		for(i=n-2;i>=0;i--){
			int bil = a[i];
			//cari minimal dari bil itu ke 100 rb
			int ans = queryMin(1,1,100000,bil,100000);
			// printf("i: %d bil: %d ans: %d\n",i,bil,ans);
			if(ans == inf){
				kanan[i] = n-1;
			}else{
				kanan[i] = ans-1;
			}
			// printf("kanan[%d] jadi: %d\n",i,kanan[i]);
			lastKanan[bil] = i;
			updateMin(1,1,100000,bil,i);
		}
		for(i=0;i<n;i++){
			// printf("kiri[%d]: %d kanan[%d]: %d\n",i,kiri[i],i,kanan[i]);
			int jumlahKiri = i-kiri[i];
			int jumlahKanan = kanan[i] -i;
			printf(" %d",jumlahKiri + jumlahKanan);
		}
		printf("\n");

	}
	return 0;
};