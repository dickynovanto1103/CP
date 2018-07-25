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
	scanf("%d",&n);
	vi ans;
	int lastBil = 1;
	int sudah1 = false;
	for(i=0;i<n;i++){
		int bil;

		scanf("%d",&bil);

		if(bil==1){
			if(sudah1){
				ans.pb(lastBil);	
			}else{
				sudah1 = true;
			}
		}
		lastBil = bil;
	}
	ans.pb(lastBil);
	int ukuran = ans.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};