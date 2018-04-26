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

int a[1010];

bool isFull(int n){
	for(int i=1;i<=n;i++){
		if(a[i]==0){return false;}
	}
	return true;
}

bool empty1(int n){
	for(int i=1;i<=n;i++){
		a[i]--;
	}
}

int main(){
	int n,m,i,j;
	
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof a);
	int ans = 0;
	for(i=0;i<m;i++){
		int bil;
		scanf("%d",&bil);
		a[bil]++;
		if(isFull(n)){
			empty1(n);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
};