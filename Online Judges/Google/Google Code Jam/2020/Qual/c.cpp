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

vector<vi> adj;
char ans[1001];

vi getNotDone(int idx) {
	vi jawab;
	for(int i=0;i<adj[idx].size();i++) {
		int idTask = adj[idx][i];
		if(ans[idTask] == '-'){
			jawab.pb(idTask);
		}
	}
	return jawab;
}

vector<char> getWorkerDone(int idx) {
	vector<char> jawab;
	if(idx == 0){
		return jawab;
	}
	
	for(int i=0;i<adj[idx-1].size();i++){
		int taskId = adj[idx-1][i];
		//find taskId in this time
		bool found = false;
		for(int j=0;j<adj[idx].size();j++){
			int taskIdCari = adj[idx][j];
			if(taskId == taskIdCari){found = true; break;}
		}
		if(!found){
			jawab.pb(ans[taskId]);	
		}
	}
	return jawab;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		adj.clear();
		printf("Case #%d: ",tt);
		int n;
		scanf("%d",&n);
		
		for(i=0;i<=1000;i++){
			ans[i] = '-';
		}

		
		int akhir = 24*60;
		adj.assign(24*60 + 10, vi());

		for(i=0;i<n;i++){
			int awal, akhir;
			scanf("%d %d",&awal, &akhir);

			for(j=awal;j<akhir;j++){
				adj[j].pb(i);
			}
		}

		bool valid = true;
		for(i=0;i<=akhir;i++){
			if(adj[i].size() >= 3){printf("IMPOSSIBLE\n"); valid =false; break;}
		}
		if (!valid){continue;}

		queue<char> avail;
		avail.push('C'); avail.push('J');
		for(i=0;i<=akhir;i++){
			vector<char> workerDone = getWorkerDone(i);
			for(j=0;j<workerDone.size();j++){
				avail.push(workerDone[j]);
			}
			vi tasksNotDone = getNotDone(i);
			while(!tasksNotDone.empty()){
				int taskId = tasksNotDone.back(); tasksNotDone.pop_back();
				assert(!avail.empty());
				char worker = avail.front(); avail.pop();
				ans[taskId] = worker;
			}
		}

		for(i=0;i<n;i++){
			assert(ans[i] != '-');
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
};