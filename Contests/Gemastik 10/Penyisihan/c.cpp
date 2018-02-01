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

const int maxn = 55;

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	int s[maxn],c[maxn];
	while(tc--){
		scanf("%d",&n);
		set<int> perusahaan, orang;
		set<int>::iterator it;
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			orang.insert(i);
			s[i]--;
		}
		for(i=0;i<n;i++){
			int banyak;
			scanf("%d",&banyak);
			for(j=0;j<banyak;j++){
				scanf("%d",&c[j]);
				if(s[i]>0){
					it=perusahaan.find(c[j]);
					if(it==perusahaan.end()){
						perusahaan.insert(c[j]);
						s[i]--;
					}
				}
				
			}
		}
		printf("%d\n",orang.size() + perusahaan.size());
	}
	return 0;
};