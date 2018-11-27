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

const int maxn = 1e5 + 5;

vector<vi> AdjList;
int warna[maxn];

bool bipar;

bool isBipartite(int node, int c){
	warna[node] = c;
	for(int i=0;i<AdjList[node].size();i++){
		int v = AdjList[node][i];
		if(warna[v] == -1){
			bipar = isBipartite(v, 1-c);
		}else{
			if(warna[v] == c){bipar = false;}
		}
	}
	return bipar;
}

multiset<ii> s;
multiset<ii>::iterator it, itTemp;
multiset<int> sAns;
multiset<int>::iterator it2;

void cetakAns(){
	printf("sAns: ");
	for(it2=sAns.begin();it2!=sAns.end();it2++){
		printf("%d ",*it2);
	}
	printf("\n");
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[maxn];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	



	AdjList.assign(n+1,vi());

	for(i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		AdjList[u].pb(v); AdjList[v].pb(u);
	}
	memset(warna, -1, sizeof warna);
	bipar = true;
	if(isBipartite(1, 0)){
	}
	for(i=1;i<=n;i++){
		s.insert(ii(a[i], warna[i]));
	}
	vii listElemen;
	for(it=s.begin();it!=s.end();it++){
		listElemen.pb(*it);
		ii elemen = *it;
		// printf("yang dipush: %d %d\n",elemen.first, elemen.second);
	}
	for(i=0;i<(listElemen.size()-1);i++){
		if(listElemen[i+1].second != listElemen[i].second){
			int jawab = abs(listElemen[i+1].first - listElemen[i].first);
			sAns.insert(jawab);
			// printf("yang diinsert jawab: %d\n",jawab);
		}
	}

	int q;
	scanf("%d",&q);
	while(q--){
		int com, x,y;
		scanf("%d %d %d",&com,&x,&y);
		if(com==0){
			it = s.find(ii(a[x], warna[x]));
			itTemp = it;
			itTemp++;
			// printf("dapet query %d %d\n",x,y);
			// printf("ukuran s: %d\n",(int)s.size());
			// cetakAns();
			if(it == s.begin() && itTemp == s.end()){
				s.erase(it);
				// s.insert(ii(y, warna[x]));
			}else{
				if(it == s.begin()){
					//cek setelahnya

					ii elemen1 = *s.begin();
					it++;
					ii elemen2 = *it;
					it--;
					// printf("elemen1: %d %d elemen2: %d %d\n",elemen1.first,elemen1.second,elemen2.first,elemen2.second);
					if(elemen1.second != elemen2.second){
						int selisihAwal = abs(elemen1.first - elemen2.first);
						it2 = sAns.find(selisihAwal);
						sAns.erase(it2);
					}
				}else if(itTemp == s.end()){
					ii elemen1 = *it;
					it--;
					ii elemen2 = *it;
					it++;
					if(elemen1.second != elemen2.second){
						int selisihAwal = abs(elemen1.first - elemen2.first);
						it2 = sAns.find(selisihAwal);
						sAns.erase(it2);
					}
				}else{
					//ke 2 arah
					ii elemen1 = *it;
					it--;
					ii elemen2 = *it;
					it++; it++;

					ii elemen3 = *it;
					it--;
					// printf("elemen1: %d %d elemen2: %d %d elemen3: %d %d\n",elemen1.first,elemen1.second,elemen2.first,elemen2.second,elemen3.first,elemen3.second);
					if(elemen1.second != elemen2.second){
						// printf("masuk sini 1\n");
						int selisihAwal = abs(elemen1.first - elemen2.first);
						// printf("selisihAwal: %d\n",selisihAwal);
						it2 = sAns.find(selisihAwal);
						// printf("halo it2 = %d\n",(int)*it2);
						sAns.erase(it2);
					}
					if(elemen1.second != elemen3.second){
						int selisihAwal = abs(elemen1.first - elemen3.first);
						it2 = sAns.find(selisihAwal);
						sAns.erase(it2);
					}
					if(elemen2.second != elemen3.second){
						int selisihAwal = abs(elemen3.first - elemen2.first);
						sAns.insert(selisihAwal);//masukin kalo beda tipe
					}
				}
			}
			ii elemen = *it;
			
			s.erase(it);
			a[x] = y;
			// printf("mau erase *it = %d %d dan insert %d %d\n",elemen.first, elemen.second, a[x], warna[x]);
			s.insert(ii(a[x],warna[x]));
			it = s.find(ii(a[x], warna[x]));
			itTemp = it;
			itTemp++;
			if(it == s.begin() && itTemp == s.end()){
				// s.erase(it);
				// s.insert(ii(y, warna[x]));
			}else{
				if(it == s.begin()){
					//cek setelahnya
					ii elemen1 = *s.begin();
					it++;
					ii elemen2 = *it;
					it--;
					if(elemen1.second != elemen2.second){
						int selisihAwal = abs(elemen1.first - elemen2.first);
						sAns.insert(selisihAwal);
					}
				}else if(itTemp == s.end()){
					ii elemen1 = *it;
					it--;
					ii elemen2 = *it;
					it++;
					if(elemen1.second != elemen2.second){
						int selisihAwal = abs(elemen1.first - elemen2.first);
						sAns.insert(selisihAwal);
					}
				}else{
					//ke 2 arah
					ii elemen1 = *it;
					it--;
					ii elemen2 = *it;
					it++; it++;
					ii elemen3 = *it;
					it--;
					if(elemen1.second != elemen2.second){
						int selisihAwal = abs(elemen1.first - elemen2.first);
						sAns.insert(selisihAwal);
						// it2 = sAns.find(selisihAwal);
						// sAns.erase(it2);
					}
					if(elemen1.second != elemen3.second){
						int selisihAwal = abs(elemen1.first - elemen3.first);
						sAns.insert(selisihAwal);
						// it2 = sAns.find(selisihAwal);
						// sAns.erase(it2);
					}
					if(elemen2.second != elemen3.second){
						int selisihAwal = abs(elemen3.first - elemen2.first);
						it2 = sAns.find(selisihAwal);
						sAns.erase(it2);
						// sAns.insert(selisihAwal);//masukin kalo beda tipe
					}
				}
			}
		}else{
			if(!bipar){printf("0\n");}
			else{
				if(warna[x] == warna[y]){printf("0\n");}
				else{
					int ans = *sAns.begin();
					printf("%d\n",ans);
				}
			}
		}
	}

	return 0;
};