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

const int maxn = 2e5 + 5;

int p[maxn];
int a[maxn], b[maxn];

void computePrefix(int n) {
	int j;
	for(int i=1;i<n;i++){
		j = p[i-1];
		while(j > 0 && b[i] != b[j]) {
			j = p[j-1];
		}
		if(b[i] == b[j]){
			j++;
		}
		p[i] = j;
	}
}

int kmp(int n, int w) {
	int i,j;
	i = 0, j = 0;
	int cnt = 0, cntBeda = 0;
	while(i < n) {
		while(j > 0 && a[i] != b[j]){
			j = p[j-1];
		}
		// printf("i:%d j: %d a: %d b: %d\n",i,j,a[i], b[j]);
		if(a[i] == b[j]){
			j++;
			// printf("i: %d j: %d\n",i,j);
			if(j == w){
				cnt++;
				// printf("sama di %d\n",i-j);
				j = p[j-1];
			}
		}
		i++;
	}
	return cnt;
}

int main(){
	int n,w,i,j;
	scanf("%d %d",&n,&w);
	if(w == 1){printf("%d\n",n); return 0;}
	else if(w > n){printf("0\n"); return 0;}
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<w;i++){scanf("%d",&b[i]);}
	n--; w--;
	
	for(i=0;i<n;i++){
		a[i] = a[i+1]-a[i];
	}
	for(i=0;i<w;i++){
		b[i] = b[i+1]-b[i];
	}
	computePrefix(w);
	//kmp
	int cnt = 0;
	printf("%d\n",kmp(n, w));
	return 0;
};