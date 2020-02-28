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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[100010];
	vi genap, ganjil;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil); 
		a[i] = bil;
		if(bil % 2 == 0){
			genap.pb(bil);
			// ev.insert(bil);
		}else{
			ganjil.pb(bil);
			// od.insert(bil);
		}
	}
	if(genap.size() >= 1 && ganjil.size() >= 1){
		sort(a,a+n);
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}else{
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	// vi ans;
	// while(od.size() && ev.size()) {
	// 	int satu = *od.begin(), dua = *ev.begin();
	// 	if(satu < dua){
	// 		ans.pb(satu);
	// 		od.erase(od.begin());
	// 	}else{
	// 		ans.pb(dua);
	// 		ev.erase(ev.begin());
	// 	}
	// }
	// multiset<int>::iterator it;
	// if(od.size()){
	// 	for(i=0;i<ganjil.size();i++){
	// 		it = od.find(ganjil[i]);
	// 		if(it != od.end()){
	// 			od.erase(it);
	// 			ans.pb(ganjil[i]);
	// 		}
	// 	}
	// }else{
	// 	for(i=0;i<genap.size();i++){
	// 		it = ev.find(genap[i]);
	// 		if(it != ev.end()){
	// 			ev.erase(it);
	// 			ans.pb(genap[i]);
	// 		}
	// 	}
	// }
	// for(i=0;i<ans.size();i++){
	// 	printf("%d ",ans[i]);
	// }
	// printf("\n");
	return 0;
};