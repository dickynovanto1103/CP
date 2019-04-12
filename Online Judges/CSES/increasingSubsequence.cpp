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
	int n,i,j;
	scanf("%d",&n);
	vi listBil;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		int idx = lower_bound(listBil.begin(), listBil.end(), bil) - listBil.begin();
		if(idx == listBil.size()){
			listBil.pb(bil);
		}else{
			listBil[idx] = bil;
		}
	}
	printf("%d\n",(int)listBil.size());
	return 0;
};