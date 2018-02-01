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
	int a[110];
	scanf("%d",&n);
	vi listNegatif, listPositif, listNol;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0){listNegatif.pb(a[i]);}
		else if(a[i]==0){listNol.pb(a[i]);}
		else{listPositif.pb(a[i]);}
	}
	if(listPositif.size()==0){
		int ukuran = listNegatif.size();
		listPositif.pb(listNegatif[ukuran-1]);
		listPositif.pb(listNegatif[ukuran-2]);
		listNegatif.pop_back();
		listNegatif.pop_back();
	}
	if(listNegatif.size()%2==0){
		int bil = listNegatif[listNegatif.size()-1];
		listNegatif.pop_back();
		listNol.pb(bil);
	}
	printf("%d",(int)listNegatif.size());
	for(i=0;i<listNegatif.size();i++){printf(" %d",listNegatif[i]);}
	printf("\n");

	printf("%d",(int)listPositif.size());
	for(i=0;i<listPositif.size();i++){printf(" %d",listPositif[i]);}
	printf("\n");

	printf("%d",(int)listNol.size());
	for(i=0;i<listNol.size();i++){printf(" %d",listNol[i]);}
	printf("\n");
	return 0;
};