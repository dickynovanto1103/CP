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
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;
typedef vector<iiii> viiii;

const int maxn = 1e5 + 5;

string kata[maxn];

vector<int> listMatch[1000001][5];

vector<vi> listSameVowel;

bool isVowel(char c) {
	return c == 'o' || c == 'e'|| c == 'u'|| c == 'i'|| c == 'a';
}

int mapper[256];

void store(const string& s, int idx) {
	int pjg = s.length();
	int cnt = 0;
	char last = 'z';
	for(int i=0;i<pjg;i++){
		if(isVowel(s[i])){cnt++; last = s[i];}
	}

	listMatch[cnt][mapper[last]].pb(idx);
}

vii listPair;
set<int> setSisa;
bool isSisaMin2[1000001];

void constructPair(){
	int i,j;
	for(i=1;i<=1000000;i++){
		for(j=0;j<5;j++){
			if(listMatch[i][j].size() & 1){
				int idxTerakhir = listMatch[i][j].size();
				listSameVowel[i].pb(listMatch[i][j][idxTerakhir-1]);
				if(listSameVowel[i].size() >= 2){
					setSisa.insert(i);
				}
				listMatch[i][j].pop_back();
			}

			for(int k=0;k<listMatch[i][j].size();k+=2){
				int first = listMatch[i][j][k];
				int second = listMatch[i][j][k+1];
				listPair.pb(ii(first, second));
			}
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	listSameVowel.assign(1000001, vi());
	mapper['a'] = 0;
	mapper['i'] = 1;
	mapper['u'] = 2;
	mapper['e'] = 3;
	mapper['o'] = 4;
	for(i=0;i<n;i++){
		cin>>kata[i];
		store(kata[i], i);
	}

	constructPair();
	// for(i=0;i<listPair.size();i++){
	// 	printf("pair %d: %d %d\n",i,listPair[i].first,listPair[i].second);
	// }
	// for(i=0;i<=5;i++){
	// 	printf("vowel: %d=>",i);
	// 	for(j=0;j<listSameVowel[i].size();j++){
	// 		printf(" %d",listSameVowel[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// set<int>::iterator it;
	// for(it=setSisa.begin();it!=setSisa.end();it++){
	// 	printf(" %d",*it);
	// }
	// printf("\n");
	viiii listJawaban;
	for(i=0;i<listPair.size();i++){
		// printf("i: %d\n",i);
		if(!setSisa.empty()){
			// printf("halo\n");
			int pjgSisa = *setSisa.begin();
			// printf("pjgSisa: %d\n",pjgSisa);
			int pertama = listSameVowel[pjgSisa].back(); listSameVowel[pjgSisa].pop_back();
			int kedua = listSameVowel[pjgSisa].back(); listSameVowel[pjgSisa].pop_back();
			// printf("pertama; %d kedua: %d\n",pertama , kedua);
			if(listSameVowel[pjgSisa].size() < 2){
				setSisa.erase(pjgSisa);
			}	
			listJawaban.pb(iiii(ii(pertama, kedua), listPair[i]));
			// printf("dipush: %d %d %d %d\n",pertama, kedua, listPair[i].first, listPair[i].second);
		}else{
			if((i+1) < listPair.size()){
				// printf("masuk haram\n");
				listJawaban.pb(iiii(listPair[i], listPair[i+1]));
				// printf("dipush: %d %d %d %d\n",listPair[i].first, listPair[i].second, listPair[i+1].first, listPair[i+1].second);
				i++;
			}else{
				break;
			}
		}
		
	}
	printf("%d\n",(int)listJawaban.size());
	for(i=0;i<listJawaban.size();i++){
		iiii jawab = listJawaban[i];
		ii pertama = jawab.first, kedua = jawab.second;
		cout<<kata[pertama.first]<<" "<<kata[kedua.first]<<endl;
		cout<<kata[pertama.second]<<" "<<kata[kedua.second]<<endl;
	}
	return 0;
};