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
typedef pair<ll,ll> ii;
typedef pair<string,ii> iii;
typedef vector<ii> vii;

const int maxn = 50010;
iii listPasangan[maxn];
iii gemas[10], cantik[10];

bool acompare(iii a, iii b){return a.second.first > b.second.first;}
bool bcompare(iii a, iii b){return a.second.second > b.second.second;}

bool isBedaSemua(int i, int j, int k, int idx){
	string nama1 = gemas[i].first, nama2 = gemas[j].first, nama3 = gemas[k].first;
	string nama = cantik[idx].first;
	if(nama!=nama1 && nama!=nama2 && nama!=nama3){return true;}
	
	return false;
}

int main(){
	int tc, n, i,j,k,x,y,z;
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		//printf("test %d:\n",test++);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>listPasangan[i].first;
			scanf("%lld %lld",&listPasangan[i].second.first,&listPasangan[i].second.second);
		}
		/*for(i=0;i<n;i++){
			cout<<listPasangan[i].first<<" "<<listPasangan[i].second.first<<" "<<listPasangan[i].second.second<<endl;
		}*/
		sort(listPasangan,listPasangan+n,acompare);
		for(i=0;i<6;i++){
			gemas[i] = listPasangan[i];
		}
		sort(listPasangan,listPasangan+n,bcompare);
		for(i=0;i<6;i++){
			cantik[i] = listPasangan[i];
		}
		/*printf("gemas:\n");
		for(i=0;i<6;i++){
			cout<<gemas[i].first<<" "<<gemas[i].second.first<<" "<<gemas[i].second.second<<endl;
		}
		printf("cantik:\n");
		for(i=0;i<6;i++){
			cout<<cantik[i].first<<" "<<cantik[i].second.first<<" "<<cantik[i].second.second<<endl;
		}
		printf("\n");*/
		ll ans = 0;
		string listNama[10];
		for(i=0;i<6;i++){
			ll gemas1 = gemas[i].second.first;
			for(j=i+1;j<6;j++){
				ll gemas2 = gemas[j].second.first;
				for(k=j+1;k<6;k++){
					//gemas
					// printf("listNama gemas:\n");
					// cout<<gemas[i].first<<" "<<gemas[j].first<<" "<<gemas[k].first<<endl;
					ll gemas3 = gemas[k].second.first;
					ll nilaiGemas = gemas1*gemas2*gemas3;
					//printf("nilaiGemas: %lld\n",nilaiGemas);
					for(x=0;x<6;x++){
						// printf("cantik1: "); cout<<cantik[x].first;
						// printf("\n");
						if(!isBedaSemua(i,j,k,x)){continue;}
						
						ll cantik1 = cantik[x].second.second;
						for(y=x+1;y<6;y++){
							// printf("cantik2: "); cout<<cantik[y].first;
							// printf("\n");
							if(!isBedaSemua(i,j,k,y)){continue;}
							ll cantik2 = cantik[y].second.second;
							for(z = y+1;z<6;z++){
								// printf("cantik3: "); cout<<cantik[z].first;
								// printf("\n");
								if(!isBedaSemua(i,j,k,z)){continue;}
								ll cantik3 = cantik[z].second.second;
								ll nilaiCantik = cantik1 * cantik2 * cantik3;
								// printf("listNama cantik:\n");
								// cout<<cantik[x].first<<" "<<cantik[y].first<<" "<<cantik[z].first<<endl;
								ll temp = nilaiCantik+nilaiGemas;

								if(ans<temp){
									//printf("nilaiGemas: %lld nilaiCantik: %lld temp: %lld\n",nilaiGemas,nilaiCantik,temp);
									ans = temp;
									listNama[0] = gemas[i].first; listNama[1] = gemas[j].first; listNama[2] = gemas[k].first; 
									listNama[3] = cantik[x].first; listNama[4] = cantik[y].first; listNama[5] = cantik[z].first; 
								}
							}
						}
					}
				}
			}
		}

		printf("%lld\n",ans);
		for(i=0;i<3;i++){
			if(i){printf(" ");}
			cout<<listNama[i];
		}
		printf("\n");
		for(i=3;i<6;i++){
			if(i>3){printf(" ");}
			cout<<listNama[i];
		}
		printf("\n");
	}
	return 0;
};