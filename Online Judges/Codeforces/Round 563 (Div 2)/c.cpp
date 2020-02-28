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

int main(){
	int n;
	scanf("%d",&n);
	int a[100010];
	int bil = 1;
	memset(a, -1, sizeof a);
	int i,j;
	for(i=2;i<=n;i++){
		if(a[i] == -1){
			for(j=i;j<=n;j+=i){
				a[j] = bil;
			}
			bil++;	
		}
		
	}
	for(i=2;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
};