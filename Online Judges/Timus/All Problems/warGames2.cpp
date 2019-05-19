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
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int bit[maxn];

int LOGN = log2(1e5);
int n,k;

int query(int idx) {
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		ans += bit[i];
	}
	return ans;
}

void update(int idx, int val) {
	for(int i=idx;i<=n;i+=(i&-i)){
		bit[i] += val;
	}
}

int search(int val) {
	int sum = 0, pos = 0;
	for(int i=LOGN;i>=0;i--){
		int newPos = pos + (1<<i);
		if(newPos < n && sum + bit[newPos] < val) {
			pos = newPos;
			sum += bit[newPos];
		}
	}
	return pos + 1;
}

int cntAfter(int idx) {
	return query(n) - query(idx);
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		update(i, 1);
	}

	int pos = 0;

	for(i=1;i<=n;i++){
		if(i>1){printf(" ");}
		if(!cntAfter(pos)){pos = 0;}
		int banyakSebelum = query(pos);
		int sisa = n - i + 1;
		int after;
		after = banyakSebelum;
		after += k;
		after %= sisa;
		if(after == 0){
			after = sisa;
		}

		int posisi = search(after);
		// printf("i: %d after: %d posisi: %d\n",i,after, posisi);
		pos = posisi;
		printf("%d",pos);
		update(pos,-1);
	}
	printf("\n");

	return 0;
};