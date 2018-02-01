#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i;
	scanf("%d",&n);
	int counter[1010];
	memset(counter,0,sizeof counter);
	set<int> listbil;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		counter[bil]++;
		listbil.insert(bil);
	}
	int maks = -inf;
	for(i=0;i<=1000;i++){
		maks = max(maks,counter[i]);
	}
	printf("%d %d\n",maks,listbil.size());
	return 0;
};