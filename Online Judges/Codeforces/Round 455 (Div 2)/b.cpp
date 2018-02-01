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

multiset<ii> listPair;
multiset<ii>::iterator it;

bool cmp(ii a, ii b){
	return((a.second-a.first) > (b.second-b.first));
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=1;j<=n;j++){
			if((i+j)>n){break;}
			listPair.insert(ii(i,i+j));
		}
	}
	vii listPasangan;
	for(it=listPair.begin();it!=listPair.end();it++){
		ii pas = *it;
		int awal = pas.first, akhir = pas.second;
		//printf("yang dipush: %d %d\n",awal,akhir);
		listPasangan.pb(ii(awal,akhir));
	}
	for(j=0;j<listPasangan.size();j++){
		
		int awal = listPasangan[j].first, akhir = listPasangan[j].second;
		//printf("awal: %d akhir: %d\n",awal,akhir);
		//untuk awal
		for(i=0;i<=awal;i++){
			if(listPair.count(ii(i,awal)) && listPair.count(ii(awal,akhir))){
				//printf("awal, yang dihapus: %d %d\n",i,awal);
				listPair.erase(ii(i,awal));
				listPair.erase(ii(awal,akhir));
				listPair.insert(ii(i,akhir));
			}
		}
		for(i=n;i>=akhir;i--){
			
			if(listPair.count(ii(akhir,i)) && listPair.count(ii(awal,akhir))){
				//printf("akhir, yang dihapus: %d %d\n",akhir,i);
				listPair.erase(ii(akhir,i));
				listPair.erase(ii(awal,akhir));
				listPair.insert(ii(awal,i));
			}
		}
		
	}
		int jawab = 0;
	for(i=0;i<inf;i++){
		jawab++;
	}
	printf("%d\n",(int)listPair.size());

	return 0;
};