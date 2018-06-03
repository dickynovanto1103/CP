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

string kata[2010];
vector<vector<char> > v;

int main(){
	int tc,i,j,n;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int l;
		scanf("%d %d",&n,&l);
		v.assign(30, vector<char>());
		map<string,int> mapper;
		for(i=0;i<n;i++){
			cin>>kata[i];
			mapper[kata[i]] = i;
		}
		ll total = 1;
		bool isPossible = false;

		for(i=0;i<l;i++){
			ll counter[26];
			memset(counter,0,sizeof counter);

			for(j=0;j<n;j++){
				char kar = kata[j][i];
				counter[kar-'A']++;
			}
			ll counterBeda = 0;
			for(j=0;j<26;j++){
				if(counter[j]==0){continue;}
				counterBeda++;
				v[i].pb(j+'A');
			}
			total*=counterBeda;
			if(total>n){
				isPossible = true;
			}
		}
		// for(i=0;i<l;i++){
		// 	printf("i: %d: ",i);
		// 	for(j=0;j<v[i].size();j++){
		// 		printf(" %c",v[i][j]);
		// 	}
		// 	printf("\n");
		// }
		if(!isPossible){printf("-\n"); continue;}
		//proses kemungkinan
		srand(time(NULL));
		while(true){

			string hasil = "";
			for(i=0;i<l;i++){
				int idx = rand() % v[i].size();
				char kar = v[i][idx];
				hasil+=kar;
			}
			if(mapper.find(hasil) == mapper.end()){cout<<hasil<<endl; break;}
		}
	}
	return 0;
};