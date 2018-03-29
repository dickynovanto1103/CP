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
	int n,i,j;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		bool salah = false;
		while(n>0){
			int bil = n%10;
			if(bil%2!=0){printf("Tidak\n"); salah = true; break;}
			n/=10;
		}	
		if(!salah){
			printf("Ya\n");
		}
	}
	
	return 0;
};