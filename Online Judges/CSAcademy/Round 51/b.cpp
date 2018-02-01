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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

bool cmp(iii a, iii b){
	if(a.second.first==b.second.first){return a.second.second < b.second.second;}
	return a.second.first < b.second.first;
}

int main(){
	int n,i,j;
	ii a[110];
	scanf("%d",&n);
	vector<iii> listBil;
	vii::iterator it;
	for(i=1;i<=n;i++){scanf("%d",&a[i].first); a[i].second = i; listBil.pb(mp(i,ii(i+a[i].first,a[i].first)));}
	sort(listBil.begin(),listBil.end(),cmp);
	
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",listBil[i].first);
		// bool found = false;
		// for(it=listBil.begin();it!=listBil.end();it++){
		// 	ii pas = *it;
		// 	if(pelanggaran<pas.first){found = true; listBil.insert(it,ii(pelanggaran,idx));}
		// 	else{
		// 		if(pelanggaran==pas.first && )
		// 	}
		// }
		// if(!found){listBil.pb(ii(pelanggaran,idx));}
	}
	printf("\n");
	

	return 0;
};