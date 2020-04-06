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

bool isChanged(int step) {
	return (step > 10 && step % 10 == 1);
}

int ans[101];

const int FLIP = 0, REVERSE = 1, GAB = 2, NO = 3;

void apply(int b, int op) {
	if(op == NO){return;}

	for(int i=1;i<=b;i++){
		if(ans[i] == -1){continue;}
		if(op == FLIP) {
			ans[i] = 1 - ans[i];
		} else if(op == REVERSE) {
			int pas = b-i+1;
			if(i > pas){break;}
			swap(ans[i], ans[pas]);
		} else if(op == GAB) {
			int pas = b-i+1;
			if(i > pas){break;}
			swap(ans[i], ans[pas]);
			ans[i] = 1 - ans[i];
			ans[pas] = 1 - ans[pas];
		}
	}
}

int determineOperation(int idx1, int idx2, int cur1, int cur2) {
	if(ans[idx1] != cur1 && ans[idx2] != cur2) {
		return FLIP;
	}else if(ans[idx1] == cur1 && ans[idx2] != cur2){
		return REVERSE;
	}else if(ans[idx1] != cur1 && ans[idx2] == cur2){
		return GAB;
	}else if(ans[idx1] == cur1 && ans[idx2] == cur2){
		return NO;
	}else{
		return NO;
	}
}

int query(int idx) {
	printf("%d\n",idx);
	fflush(stdout);
	int cur;
	scanf("%d",&cur);
	return cur;
}

int step = 1;
vii listSama, listBeda;

void doStep(int b){
	if(listSama.size() == 0 || listBeda.size() == 0) {

		if(listSama.size() == 0){
			int idx = listBeda[0].first;
			int cur = query(idx);
			if(cur != ans[idx]) {
				apply(b, FLIP);
			}
		} else if(listBeda.size() == 0) {
			int idx = listSama[0].first;
			int cur = query(idx);
			if(cur != ans[idx]){
				apply(b, FLIP);
			}
		}

		int idx = 1;
		query(idx);

		step+=2;
	} else {
		int idxSama = listSama[0].first;
		int curSama = query(idxSama);
		
		int idxBeda = listBeda[0].first;
		int curBeda = query(idxBeda);

		int op = determineOperation(idxSama, idxBeda, curSama, curBeda);
		apply(b, op);

		step+=2;
	}
}


int main(){
	int tc,b,i,j;
	scanf("%d %d",&tc,&b);
	while(tc--){
		int awal = 1, akhir = b;
		for(i=1;i<=b;i++){
			ans[i] = -1;
		}
		
		step = 1;
		
		listSama.clear(); listBeda.clear();
		while(awal <= akhir) {
			if(isChanged(step)) {
				doStep(b);
			}

			printf("%d\n",awal);
			fflush(stdout);
			scanf("%d",&ans[awal]);
			step++;
			awal++;

			if(isChanged(step)){
				doStep(b);
			}

			printf("%d\n", akhir);
			fflush(stdout);
			scanf("%d",&ans[akhir]);
			step++;
			akhir--;

			if(ans[awal-1] == ans[akhir+1]){listSama.pb(ii(awal-1, akhir+1));}
			else{listBeda.pb(ii(awal-1, akhir+1));}
		}

		for(i=1;i<=b;i++){
			assert(ans[i] != -1);
			printf("%d",ans[i]);
		}

		printf("\n");
		fflush(stdout);
		string ans;
		cin>>ans;
		if(ans == "N"){return 0;}
	}
	return 0;
};