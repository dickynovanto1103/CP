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

const int maxn = 1e5 + 5;

ii ar[maxn];
int n;

int check(int a, int bil) {
	int cari = a - bil;
	int idx = lower_bound(ar, ar+n, ii(cari, -1))-ar;
	if(idx == n){
		idx--;
	}
	if(ar[idx].first != cari) {
		return -1;
	}else{
		return idx;
	}
}

int main(){
	int a,b,i,j;
	scanf("%d %d %d",&n,&a,&b);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		ar[i].first = bil, ar[i].second = i;
	}
	sort(ar, ar+n);
	set<int> s;
	for(i=0;i<n;i++){
		int bil = ar[i].first;
		
		int status = 0;
		int pertama = check(a, bil);
		if(pertama == -1){
			status |= 1;	
		}
		int kedua = check(b, bil);
		if(kedua == -1) {
			status |= 2;
		}
		if(status == 3) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=0;i<n;i++){
		printf("0 ");
	}
	printf("\n");
	
	return 0;
};