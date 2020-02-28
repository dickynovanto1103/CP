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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	swap(a[n-1], a[n-2]);
	bool valid = true;
	for(i=0;i<n;i++) {
		int prev = i - 1;
		prev += n; prev %= n;
		int next = (i + 1) % n;
		if(a[i] < a[next] + a[prev]){

		}else{
			valid = false; break;
		}
	}
	if(valid){
		printf("YES\n");
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}else{
		printf("NO\n");
	}
	return 0;
};