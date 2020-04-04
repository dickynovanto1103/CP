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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	vector<string> listNama;
	vi listLantai;
	map<string, int> mapper;
	map<int,int> mapLantai;
	for(i=0;i<m;i++){
		int banyak;
		scanf("%d",&banyak);
		vector<pair<string, int> > v;
		for(j=0;j<banyak;j++){
			string s;
			cin>>s;
			if(mapper.find(s) == mapper.end()){
				mapper[s] = 1;
				listNama.pb(s);
			}
			v.pb(pair<string,int>(s, -1));
		}
		for(j=0;j<banyak;j++){
			int lantai;
			cin>>lantai;
			if(mapLantai.find(lantai) == mapLantai.end()){
				mapLantai[lantai] = 1;
				listLantai.pb(lantai);
			}
			v[j].second = lantai;
		}
	}
	for(i=0;i<listNama.size();i++){
		if(i){printf(" ");}
		cout<<listNama[i];
	}
	printf("\n");
	for(i=0;i<listLantai.size();i++){
		if(i){printf(" ");}
		printf("%d",listLantai[i]);
	}
	printf("\n");
	return 0;
};