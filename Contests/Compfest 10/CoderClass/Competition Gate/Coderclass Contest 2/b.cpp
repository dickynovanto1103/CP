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

const int maxn = 1e4 + 4;

int main(){
	string kata;
	int i,j, cntKategori = -1;
	map<string,int> listKategori;
	ll banyak[maxn];
	bool sudahPertanyaan = false;
	while(getline(cin,kata)){
		if(kata[0] == '#'){
			cntKategori++;
			string namaKategori = "";
			for(i=2;i<kata.length();i++){
				if(kata[i]==' '){continue;}
				namaKategori+=kata[i];
			}
			listKategori[namaKategori] = cntKategori;
		}else if(kata[0] == '!'){
			sudahPertanyaan = true;
		}else{
			if(!sudahPertanyaan){
				banyak[cntKategori]++;	
			}else{
				ll ans = 1;
				string kategori = "";
				for(i=0;i<kata.length();i++){
					char kar = kata[i];
					if(kar == ' '){continue;}
					else if(kar == '+'){
						int idx = listKategori[kategori];
						// printf("kategori: "); cout<<kategori<<" idx: "<<idx<<endl;
						ans *= banyak[idx];
						kategori = "";
						continue;
					}
					kategori += kar;
				}

				int idx = listKategori[kategori];
				// printf("kategori terakhir: "); cout<<kategori<<" idx: "<<idx<<endl;
				ans *= banyak[idx];
				kategori = "";
				printf("%lld\n",ans);
				
			}
			
		}
	}
	return 0;
};