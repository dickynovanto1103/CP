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
	int n,k;
	int i,j;
	int a[19];
	vector<int> s; s.pb(2); s.pb(4); s.pb(6);
	vi jawab;
	while(scanf("%d %d",&n,&k) != EOF){
		// printf("n: %d k: %d --> ",n,k);
		vi jawab;
		for(i=0;i<n;i++){
			a[i] = i+1;
		}
		int ans = 1;
		for(i=0;i<(1<<n);i++){
			vi listBil;
			for(j=0;j<n;j++){
				if(i & (1<<j)){
					listBil.pb(a[j]);
				}
			}
			int ukuran = listBil.size();
			bool valid = true;
			for(j=0;j<ukuran;j++){
				for(int m=j+1;m<ukuran;m++){
					if(__gcd(listBil[j], listBil[m]) != k){valid = false; goto here;}
				}
			}
			here:
			if(valid && ukuran){
				if(ans < ukuran){
					ans = ukuran;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
};