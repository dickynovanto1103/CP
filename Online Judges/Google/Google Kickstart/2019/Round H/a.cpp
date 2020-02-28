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

int bit[100001];

int n;

int query(int idx){
	int ans = 0;
	// printf("idx: %d\n",idx);
	for(int i=idx;i>=1;i-=(i&-i)) {
		// printf("i: %d\n",i);
		ans += bit[i];
		// printf("i: %d ans jd: %d\n",i, ans);
	}
	return ans;
}

void update(int idx, int val) {
	for(int i=idx;i<=100000;i+=(i&-i)){
		bit[i] += val;
		// printf("bit[%d]: %d\n",i,bit[i]);
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		memset(bit, 0, sizeof bit);
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		vi a;
		int kiri = 1, kanan, mid, ans;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			update(bil,1);
			if(i == 0){
				a.pb(1);
			}else{
				int batas = a.back();
				int satu = query(100000);
				int dua = query(batas);
				int banyak = satu - dua;
				int minAngka = batas+1;
				// printf("satu: %d dua: %d minAngka: %d\n",satu, dua, minAngka);
				if(banyak >= minAngka){
					a.pb(batas+1);
				}else{
					a.pb(batas);
				}
			}
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");
	}


	return 0;
};