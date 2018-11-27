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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[maxn],b[maxn];
	int idx[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		idx[a[i]] = i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int idxSekarang = 0;
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		if(idx[b[i]] != -1){
			int cnt = 0;
			for(j=idxSekarang;j<=idx[b[i]];j++){
				cnt++;
				idx[a[j]] = -1;
			}
			idxSekarang = j;
			printf("%d",cnt);
		}else{
			printf("0");
		}

	}
	printf("\n");
	return 0;
};