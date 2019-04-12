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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	set<int> s;
	set<int>::iterator it;
	for(i=0;i<n;i++){
		int bilawal;
		scanf("%d",&bilawal);
		for(j=1;j<=360;j++){
			int bil = bilawal * j;
			bil %= 360;

			s.insert(bil);
		}
	}
	vi listBil;
	for(it=s.begin();it!=s.end();it++){
		listBil.pb(*it);
	}
	int ukuran = listBil.size();
	for(i=0;i<m;i++){
		int harapan;
		scanf("%d",&harapan);
		bool found = false;
		for(j=0;j<ukuran;j++){
			int bil = listBil[j];
			int cari = abs(bil - harapan);
			if(binary_search(listBil.begin(), listBil.end(), cari)){
				printf("YES\n");
				found = true;
				break;
			}
		}
		if(!found){
			printf("NO\n");
		}
	}
	
	return 0;
};