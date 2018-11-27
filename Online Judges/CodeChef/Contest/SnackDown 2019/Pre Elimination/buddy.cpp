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

const int maxn = 1e2 + 2;
int a[maxn], b[maxn];
vi v1, v2;

bool isSama(int n){
	int i;
	for(i=0;i<n;i++){
		if(v1[i] != v2[i]){return false;}
	}
	return true;
}

int main(){
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		
		int sor1 = 0, sor2 = 0;
		
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=0){v1.pb(a[i]);}
			sor1 += a[i];
		}
		for(i=0;i<m;i++){
			scanf("%d",&b[i]);
			if(b[i]!=0){v2.pb(b[i]);}
			sor2 += b[i];
		}
		sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
		n = v1.size(), m = v2.size();
		// printf("n: %d m: %d\n",n,m);
		if(sor1 == 0 && sor2 == 0){printf("Bob\n"); continue;}
		if(n == 1 && n == m){
			if(v1[0] > v2[0]){printf("Alice\n"); }
			else{printf("Bob\n");}
			v1.clear(); v2.clear();continue;
		}
		if(sor1 == sor2){
			if(n!=m){printf("Alice\n");}
			else{
				if(isSama(n)){printf("Bob\n");}
				else{printf("Alice\n");}
			}
		}else{
			if(n==m && n == 1){printf("Bob\n");}
			else{printf("Alice\n");}
			
		}
		v1.clear(); v2.clear();
		// if(n != m){
		// 	if(sor1 == sor2){printf("Bob\n");}
		// 	else{printf("Alice\n");}
		// }
		// else{
		// 	if(isSama(n)){printf("Bob\n");}
		// 	else{
		// 		if(sor1 == sor2){printf("Bob\n");}
		// 		else{printf("Alice\n");}
		// 	}
		// }
	}
	return 0;
};