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
	int tc,n,d,a[210],i,j;
	bool isVisited[210];
	scanf("%d",&tc);
	bool valid = true;
	srand(time(NULL));
	for(int tt=1;tt<=tc;tt++){
		memset(isVisited,false,sizeof isVisited);
		int cnt[210];
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		if(n==-1){valid = false; break;}
		// cerr<<"n: "<<n<<endl;
		for(i=0;i<n;i++){

			scanf("%d",&d);
			// cerr<<"d dibaca: "<<d<<endl;
			if(d==0){cout<<-1<<flush<<endl; continue;}
			if(d==-1){valid = false; break;}
			
			vi listBisa;
			for(j=0;j<d;j++){
				scanf("%d",&a[j]);
				cnt[a[j]]++;
				if(!isVisited[a[j]]){
					listBisa.pb(a[j]);
					// printf("yangdipush: %d\n",a[j]);
				}
			}

			if(listBisa.size() == 0){cout<<-1<<flush<<endl;}
			else{
				int minimalMuncul = cnt[listBisa[0]];
				for(j=0;j<listBisa.size();j++){
					
					minimalMuncul = min(minimalMuncul, cnt[listBisa[j]]);
				}
				// printf("minimalMuncul: %d\n",minimalMuncul);
				vi listIdxSama;
				for(j=0;j<listBisa.size();j++){
					if(minimalMuncul == cnt[listBisa[j]]){
						listIdxSama.pb(listBisa[j]);
					}
				}
				
				int idx = rand() % listIdxSama.size();
				isVisited[listIdxSama[idx]] = true;
				cout<<listIdxSama[idx]<<flush<<endl;
				

				listIdxSama.clear();
			}
			listBisa.clear();
			
		}
		if(!valid){break;}
	}
	return 0;
};