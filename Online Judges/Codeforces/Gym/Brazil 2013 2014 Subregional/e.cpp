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

bool a[10003];

int main(){
	memset(a, true, sizeof a);
	int n, m, t;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d", &t);
		a[t] = false;
	}
	bool awal=true;
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(awal){
				printf("%d", i);
				awal = false;
			}
			else{
				printf(" %d", i);
			}
		}
	}
	if(awal){
		printf("*");
	}
	puts("");
	return 0;
};