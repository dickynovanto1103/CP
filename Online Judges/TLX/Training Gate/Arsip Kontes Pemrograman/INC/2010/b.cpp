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
	int tc,a,b,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&k,&a,&b);
		while(a!=b){
			if(a>b){
				int parent = a/k;
				int sisa = a%k;
				if(sisa>1){parent++;}
				a = parent;
			}else{
				int parent = b/k;
				int sisa = b%k;
				if(sisa>1){parent++;}
				b = parent;
			}
		}
		printf("%d\n",a);
	}
	return 0;
};