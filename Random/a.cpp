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

int a[maxn];
int cnt;
void shuffle(int* a, int left, int right, int pivot) {
	int idx = right;
	for(int i=right;i>=left;i--){
		if(a[i] > pivot){
			cnt++;
			swap(a[idx], a[i]);
			idx--;
		}
	}
}

int main(){
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	k--;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n == 1){printf("%d\n",a[0]); return 0;}
	int left = 0, right = n-1;
	srand(time(NULL));
	// printf("left, right: %d %d\n",left,right );
	while(left <= right) {
		int cntSearch = right-left + 1;
		int idx = rand() % cntSearch;
		idx += left;
		int bil = a[idx];

		shuffle(a, left, right, a[idx]);

		if(cnt > k) {
			left = n-cnt; right = n-1;
			cnt = 0;
		}else if(cnt == k){
			printf("%d\n",bil);
			break;
		}else{
			right = n-cnt-1;
		}
	}
	return 0;
};