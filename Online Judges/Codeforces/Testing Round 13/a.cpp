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
	vi listBil;
	int sisa = n;
	for(i=1;i<=n;i++){
		if(sisa >= i){
			sisa -= i;
			listBil.pb(i);
		}else{
			listBil[listBil.size()-1] += sisa;

			break;
		}
	}
	int ukuran = listBil.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		if(i){printf(" ");}
		printf("%d",listBil[i]);
	}
	printf("\n");
	return 0;
};