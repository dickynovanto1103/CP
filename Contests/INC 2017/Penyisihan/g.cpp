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

const int maxn = 301;

vector<vii> vec;

int main(){
	int n,i,j,listBilangan[maxn][maxn];
	scanf("%d",&n);
	vec.assign(100010,vii());
	set<int> s;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&listBilangan[i][j]);
			s.insert(listBilangan[i][j]);
			vec[listBilangan[i][j]].pb(ii(i,j));
		}
	}
	set<int>::iterator it;
	int cnt = 0;
	vi listBilanganUnik;
	for(it=s.begin();it!=s.end();it++){
		listBilanganUnik.pb(*it);
	}
	reverse(listBilanganUnik.begin(),listBilanganUnik.end());
	int maks = 0;
	int bilangan;
	bool found = false;
	for(int iter=0;iter<listBilanganUnik.size();iter++){
		int bil = listBilanganUnik[iter];
		cnt = 0;
		int ukuran = vec[bil].size();
		for(i=0;i<ukuran;i++){
			ii pair1 = vec[bil][i];
			for(j=i+1;j<ukuran;j++){
				ii pair2 = vec[bil][j];
				int a = pair1.first, b = pair1.second, c = pair2.first, d = pair2.second;
				if(a!=c || b!=c){
					if(a<=c && b<=d){
						//printf("yang cocok idx: %d %d %d %d\n",a,b,c,d);
						cnt++;
					}
				}
			}////
		}
		if(cnt>=1){
			found = true;
			bilangan=bil;
			break;
		}
		//maks = max(maks,cnt);

	}
	if(!found){printf("-1\n"); return 0;}
	printf("%d\n",bilangan);

	return 0;
};