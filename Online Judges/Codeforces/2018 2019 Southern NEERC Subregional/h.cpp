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
typedef set<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e4 + 4;

map<string,int> mapper;

vector<vi> AdjList;
int cnt;

void insertToMap(string& kata, int idx) {
	if(mapper.find(kata) == mapper.end()){
		mapper[kata] = cnt;
		// printf("kata: "); cout<<kata<<" cnt: "<<cnt<<endl;
		AdjList[cnt].insert(idx);
		cnt++;	
	}else{
		int indeks = mapper[kata];
		AdjList[indeks].insert(idx);
	}
}

int main(){
	int n,i,j,q;
	scanf("%d",&n);
	string kata[maxn];
	AdjList.assign(650000, vi());
	for(i=0;i<n;i++){
		cin>>kata[i];
		mapper[kata[i]] = i;
	}
	cnt = n;
	int k;
	for(i=0;i<n;i++){
		int pjg = kata[i].length();
		for(j=0;j<pjg;j++){
			string sub = "";
			sub += kata[i][j];
			insertToMap(sub,i);
			
			for(k=j+1;k<pjg;k++){
				sub += kata[i][k];
				insertToMap(sub, i);
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		string word;
		cin>>word;
		if(mapper.find(word) == mapper.end()){
			printf("0 -\n");
		}else{
			int idx = mapper[word];
			int banyak = AdjList[idx].size();
			int contoh = *AdjList[idx].begin();
			printf("%d ",banyak); cout<<kata[contoh]<<endl;
		}
	}
	return 0;
};