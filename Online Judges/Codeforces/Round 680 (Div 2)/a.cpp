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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int tc,i,j,n,x;
	scanf("%d",&tc);
	int a[51], b[51];
	while(tc--){
		scanf("%d %d",&n,&x);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		sort(a, a+n);
		sort(b, b+n, cmp);
		bool valid = true;
		for(i=0;i<n;i++){
			if((a[i] + b[i]) > x){
				valid = false;
				break;
			}
		}
		if(valid){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
};