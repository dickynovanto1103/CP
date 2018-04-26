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

const int maxn = 2e5 + 5;

vector<vi> AdjList;

int main(){
	string kata;
	int i,n,j,q;
	string com;
	char kar;
	cin>>kata;
	n = kata.length();
	AdjList.assign(27,vi());
	for(i=0;i<n;i++){
		char kar = kata[i];
		AdjList[kar-'a'].pb(i);
	}

	// for(i=0;i<26;i++){
	// 	printf("node: %c:",i+'a');
	// 	for(j=0;j<AdjList[i].size();j++){
	// 		printf(" %d",AdjList[i][j]);
	// 	}
	// 	printf("\n");
	// }
	scanf("%d",&q);
	string cur = "";
	bool state[maxn];
	int arrCurrentIdx[maxn];
	memset(state, true,sizeof state);
	
	int currentIdx = -1;
	int idxState = 0;
	arrCurrentIdx[0] = -1;

	vi listIdx;
	for(i=0;i<q;i++){
		cin>>com;
		if(com[1]=='u'){
			idxState++;
			cin>>kar;
			// cout<<"com: "<<com<<" kar: "<<kar<<endl;
			cur+=kar;
			// printf("cur jd: "); cout<<cur<<endl;
			if(idxState>0){
				if(state[idxState-1]==false){
					state[idxState] = false;
					
					printf("NO\n");
					continue;
				}
			}
			// printf("currentIdx: %d, yg dicari: %d\n",currentIdx, currentIdx+1);
			//cari indeks
			int idx = lower_bound(AdjList[kar-'a'].begin(), AdjList[kar-'a'].end(), currentIdx+1) - AdjList[kar-'a'].begin();
			if(idx == AdjList[kar-'a'].size()){
				state[idxState] = false;
				// printf("masuk sini\n");
				printf("NO\n");
			}else{
				state[idxState] = true;
				printf("YES\n");
				currentIdx = AdjList[kar-'a'][idx];
				// printf("ketemu currentIdx: %d\n",currentIdx);
				listIdx.pb(currentIdx);
				arrCurrentIdx[idxState] = currentIdx;
				
			}
			
		}else{
			// printf("com: pop\n");
			cur.pop_back();
			idxState--;

			// printf("cur jd: "); cout<<cur<<endl;
			currentIdx = arrCurrentIdx[idxState];
			// printf("idxState: %d\n", idxState);
			if(state[idxState]){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
};