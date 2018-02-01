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

int st[4*maxn]; // menyimpan frquency maksimal
int a[maxn], lastIdx[2*maxn], startIdx[2*maxn], freq[2*maxn], arrFreq[maxn];

int left(int n){return 2*n;}
int right(int n){return 2*n + 1;}

void build(int node, int l, int r){
	if(l==r){
		st[node] = arrFreq[l];
	}else{
		int mid = (l+r)/2;
		build(left(node),l,mid);
		build(right(node),mid+1,r);

		st[node] = max(st[left(node)], st[right(node)]);
	}
}

int query(int node, int l, int r, int i, int j){
	if(i>r || j<l){return -1;}
	if(i<=l && r<=j){return st[node];}

	int mid = (l+r)/2;
	int ans1 = query(left(node),l,mid,i,j);
	int ans2 = query(right(node),mid+1,r,i,j);
	return max(ans1,ans2);
}

int main(){
	int n,q,i,j;
	
	while(scanf("%d %d",&n,&q)==2){
		memset(freq,0,sizeof freq);
		memset(startIdx,-1,sizeof startIdx);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]+=100000;
			if(startIdx[a[i]]==-1){startIdx[a[i]] = i;}
			lastIdx[a[i]] = i;
			freq[a[i]]++;
		}
		for(i=1;i<=n;i++){
			arrFreq[i] = freq[a[i]];
		}
		build(1,1,n);

		while(q--){
			int l, r, ans;
			scanf("%d %d",&l,&r);
			if(a[l]==a[r]){
				// /printf("masuk sini\n");
				ans = r-l+1;
			}
			else{
				int ans1 = lastIdx[a[l]] - l + 1;
				int ans2 = r-startIdx[a[r]] + 1;
				int ans3;
				int lBaru, rBaru;
				lBaru = startIdx[a[l]] + freq[a[l]];
				rBaru = lastIdx[a[r]] - freq[a[r]];
				if(lBaru>rBaru){ans3 = 0;}
				else{ans3 = query(1,1,n,lBaru,rBaru);}
				//printf("ans1: %d ans2: %d ans3: %d lBaru: %d rBaru: %d\n",ans1,ans2,ans3,lBaru,rBaru);
				ans = max(ans1,max(ans2,ans3));
			}
			printf("%d\n",ans);
		}
	}
	

	return 0;
};