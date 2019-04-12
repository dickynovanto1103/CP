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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	char a[maxn][maxn], b[maxn][maxn];
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%s",b[i]);
	}
	//adakah tempat kosong
	bool found = false;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j] == 'O'){found = true; goto oke;}
		}
	}
	if(!found){
		// if(n!=2){assert(false);}
		printf("0\n"); return 0;
	}
	oke:
	for(i=0;i<n;i++){
		int cnt = 0;
		for(j=0;j<m;j++){
			if(b[i][j] == 'X'){cnt++;}
		}
		if(cnt >= 2){
			// if(n!=2){assert(false);}
			assert(false);
			printf("0\n"); return 0;
		}
	}
	for(j=0;j<m;j++){
		int cnt = 0;
		for(i=0;i<n;i++){
			if(b[i][j] == 'X'){cnt++;}
		}
		if(cnt >= 2){
			assert(false);
			printf("0\n"); return 0;
		}
	}
	// if(n!=4){assert(false);}
	printf("1\n");
	return 0;
};