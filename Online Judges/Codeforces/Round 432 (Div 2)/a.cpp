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
	int n,k,t;
	scanf("%d %d %d",&n,&k,&t);
	if(t>k){
		if(t<=n){
			printf("%d\n",k);
		}else{
			int selisih = n+k - t;
			printf("%d\n",selisih);
		}
	}else{
		printf("%d\n",t);
	}
	return 0;
};