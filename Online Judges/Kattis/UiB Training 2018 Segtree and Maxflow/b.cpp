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

const int maxn = 1e6 + 6;

int bit[maxn];
int arr[maxn];

void update(int idx, int val){
	for(int i=idx;i<maxn;i+=(i&-i)){
		bit[i] += val;
	}
}

int query(int idx){
	int sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		sum += bit[i];
	}
	return sum;
}

int main(){
	int n,q,i,j;
	scanf("%d %d\n",&n,&q);
	// printf("n: %d q: %d\n",n,q);
	while(q--){
		char com;
		scanf("%c ",&com);
		// printf("com: %c\n",com);
		if(com == 'F'){
			int idx;
			scanf("%d\n",&idx);
			// printf("idx: %d\n",idx);
			arr[idx] = 1-arr[idx];
			if(arr[idx]){
				update(idx, 1);
			}else{
				update(idx, -1);
			}
		}else{
			int a,b;
			scanf("%d %d\n",&a,&b);
			// printf("a: %d b: %d\n",a,b);
			int ans = query(b) - query(a-1);
			printf("%d\n",ans);
		}

		
	}
	return 0;
};