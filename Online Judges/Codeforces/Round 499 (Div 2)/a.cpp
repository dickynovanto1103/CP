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

int main(){
	int n,k,i,j;
	string kata;
	scanf("%d %d",&n,&k);
	cin>>kata;
	sort(kata.begin(), kata.end());
	char harapan = 'a';
	int tot = 0;
	for(i=0;i<k;i++){
		int idx = lower_bound(kata.begin(), kata.end(), harapan) - kata.begin();
		if(idx == n){printf("-1\n"); return 0;}
		char karBaru = kata[idx];
		harapan = karBaru + 2;
		tot += (karBaru - 'a' + 1);
	}
	printf("%d\n",tot);
	return 0;
};