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

int main(){
	int i,n,t;
	scanf("%d %d",&n,&t);
	int sum = 0;
	for(i=0;i<n-1;i++){
		int bil;
		scanf("%d",&bil);
		sum += bil;
	}
	printf("%d\n",(sum + (t-1)) / t);
	return 0;
};