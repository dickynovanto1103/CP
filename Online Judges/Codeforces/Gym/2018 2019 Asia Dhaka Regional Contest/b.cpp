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

const int maxn = 1e5;

int numInversion[maxn+12];

int getNumInversion(int n) {
	vi a;
	while(n > 0){
		int bil = n%10;
		n /= 10;
		a.pb(bil);
	}
	int ukuran = a.size();
	int cnt = 0,i,j;
	for(i=0;i<ukuran;i++){
		for(j=i+1;j<ukuran;j++){
			if(a[i] > a[j]){cnt++;}
		}
	}
	return cnt;
}


int main(){
	int tc,i,j;
	for(i=1;i<=maxn;i++){
		numInversion[i] = getNumInversion(i);
		// printf("numInversion[%d]: %d\n",i,numInversion[i]);
	}
	for(i=2;i<=maxn;i++){
		numInversion[i] += numInversion[i-1];
		printf("%d -> %d\n",i,numInversion[i]);
	}

	scanf("%d",&tc);

	while(tc--){
		int x,y;
		scanf("%d %d",&x,&y);
	}

	return 0;
};