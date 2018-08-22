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

const int maxn = 5e4 + 3;

struct perintah{
	int v, p, c, idx, com;
	string kata;
};

vector<perintah> pas;
vector<perintah> perintahBiasa;

bool cmp(perintah a, perintah b){
	return a.v < b.v;
}

bool cmpIdx (perintah a, perintah b) {
	return a.idx < b.idx;
}

string ans[50001];
string temp = "";

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		int com;
		scanf("%d",&com);
		// printf("com: %d\n",com);
		if(com == 3){
			int v,p,c;
			scanf("%d %d %d",&v,&p,&c);
			perintah pe;
			pe.v = v; pe.p = p; pe.c = c; pe.idx = i;
			pas.pb(pe);
		}else if(com == 1){
			int p;
			string kata;
			perintah pe;
			scanf("%d",&p);
			cin>>kata;
			pe.p = p; pe.kata = kata; pe.com = 1;
			// printf("kata: "); cout<<kata<<endl;
			perintahBiasa.pb(pe);
		}else{
			int p,c;
			scanf("%d %d",&p,&c);
			// printf("p: %d c: %d\n", p,c);
			perintah pe;
			pe.p = p; pe.c = c; pe.com = 2;
			perintahBiasa.pb(pe);
		}
	}
	sort(pas.begin(), pas.end(), cmp);
	int version = 0;
	int indeks = 0;
	// printf("halo\n");
	for(i=0;i<pas.size();i++){
		perintah pe = pas[i];
		int v = pe.v, p = pe.p, c = pe.c, idx = pe.idx;
		// if(v >= perintahBiasa.size()){return 0;}
		int iterasi = v - version;
		for(j=0;j<iterasi;j++){

			int com = perintahBiasa[indeks].com;
			// printf("com: %d j: %d indeks: %d\n",com,j,indeks);
			if(com == 1){
				int pos = perintahBiasa[indeks].p;
				string kata = perintahBiasa[indeks].kata;
				// cout<<"kata: "<<kata<<endl;
				if(pos == 0){
					temp = kata + temp;
				}else{
					temp.insert(pos, kata);
				}
				// printf("temp jd: "); cout<<temp<<endl;
			}else{
				int pos = perintahBiasa[indeks].p;
				int banyakKar = perintahBiasa[indeks].c;
				int sisa = temp.size() - pos + 1;
				if(sisa < banyakKar){
					temp.erase(pos-1, sisa);
				}else{
					temp.erase(pos-1, banyakKar);	
				}
				
				// printf("setelah dihapus temp jd: "); cout<<temp<<endl;
			}
			indeks++;
			// printf("idx: %d\n",idx);
		}

		version = v;
		if(temp.empty()){ans[idx] = ""; continue;}
		int sisa = temp.size() - p + 1;
		if(sisa < c){
			ans[idx] = temp.substr(p-1, sisa);
		}else{
			ans[idx] = temp.substr(p-1,c);	
		}
		
		// printf("ans[%d]: ",idx); cout<<ans[idx]<<endl;
	}
	sort(pas.begin(), pas.end(), cmpIdx);
	for(i=0;i<pas.size();i++){
		int idx = pas[i].idx;
		cout<<ans[idx]<<endl;
	}
	return 0;
};
