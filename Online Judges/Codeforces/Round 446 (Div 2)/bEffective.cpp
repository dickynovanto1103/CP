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

const int maxn = 1000010;
ll a[maxn];
bool isVisited[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	memset(isVisited,false,sizeof isVisited);
	
	for(i=n-1;i>=0;i--){
		
		ll bil = a[i];
		ll batasBawah = max((ll)i-a[i],0LL);
		for(j=batasBawah;j<i;j++){
			if(isVisited[j]){break;}
			else{isVisited[j] = true;}
		}
		
	}
	int cnt = 0;
	for(i=0;i<n;i++){
		if(!isVisited[i]){cnt++;}
	}
	printf("%d\n",cnt);
	return 0;
};