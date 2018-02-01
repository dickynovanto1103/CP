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

vector<vector<string> > Adj;
unordered_map<string,int> mapper;
int main(){
	int tc,i,j,n;
	string kata[10010];
	bool isVisited[10010];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		Adj.assign(21, vector<string>());
		for(i=0;i<n;i++){
			cin>>kata[i];
			mapper[kata[i]] = i;
			int pjg = kata[i].length();
			Adj[pjg].pb(kata[i]);
		}
		
		if(n==1){printf("0\n"); continue;}
		//printf("\n");
		int cnt = 0;
		/*memset(isVisited,false,sizeof isVisited);
		for(i=1;i<20;i++){
			vector<string> v1 = Adj[i],v2 = Adj[i+1];
			sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
			if(v1.empty() || v2.empty()){
				//printf("masuk sini utk i: %d\n",i);
				continue;
			}

			int idx1 = 0, idx2 = 0;
			while(idx1<v1.size() && idx2<v2.size()){
				string kata1 = v1[idx1], kata2 = v2[idx2];
				// printf("idx1: %d idx2: %d\n",idx1,idx2);
				// cout<<"kata1: "<<kata1<<" kata2: "<<kata2<<endl;
				int indeks1 = mapper[kata1], indeks2 = mapper[kata2];
				kata2.pop_back();
				//printf("kata2 jd: " ); cout<<kata2<<endl;
				if(isVisited[indeks1] || isVisited[indeks2]){
					//printf("masuk\n");
					idx1++; continue;
				}
				if(kata2<kata1){

					idx2++;
				}
				else if(kata2>kata1){idx1++;}
				else{
					cnt++;
					//printf("sama cnt jd: %d\n",cnt);
					isVisited[indeks1] = true; isVisited[indeks2] = true;
					idx1++; idx2++;
				}
			}
		}*/
		//printf("\n");
		int cnt1 = 0;
		memset(isVisited,false,sizeof isVisited);
		for(i=20;i>1;i--){
			vector<string> v1 = Adj[i],v2 = Adj[i-1];
			sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
			if(v1.empty() || v2.empty()){
				//printf("masuk sini utk i: %d\n",i);
				continue;
			}

			int idx1 = 0, idx2 = 0;
			while(idx1<v1.size() && idx2<v2.size()){
				string kata1 = v1[idx1], kata2 = v2[idx2];
				// printf("idx1: %d idx2: %d\n",idx1,idx2);
				// cout<<"kata1: "<<kata1<<" kata2: "<<kata2<<endl;
				int indeks1 = mapper[kata1], indeks2 = mapper[kata2];
				kata1.pop_back();
				//printf("kata2 jd: " ); cout<<kata2<<endl;
				if(isVisited[indeks1] || isVisited[indeks2]){
					//printf("masuk\n");
					idx1++; continue;
				}
				if(kata2<kata1){
					//printf("masuk sini\n");
					idx2++;
				}
				else if(kata2>kata1){idx1++;}
				else{
					cnt1++;
					//printf("sama cnt jd: %d\n",cnt);
					isVisited[indeks1] = true; isVisited[indeks2] = true;
					idx1++; idx2++;
				}
			}
		}
		printf("%d\n",max(cnt1,cnt));
		Adj.clear(); mapper.clear();
	}
	return 0;
};