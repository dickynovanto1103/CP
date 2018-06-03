/*
ID: dickyno1
LANG: C++
TASK: beads
*/

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

const int maxn = 351;
int n;
string kata;
bool isVisited[maxn], isVisited1[maxn], isVisited2[maxn];


int ubahIndeks(int idx, bool isMaju) {
	if(isMaju){
		idx++;	
		idx%=n;
	}else{
		idx--;
		if(idx<0){idx+=n;}
	}
	return idx;
}

int hitung(char curWarna, int idx, bool isMaju) {
	int ans = 0;
	while(true) {
		if(isVisited[idx]){break;}
		if(isVisited1[idx]){break;}
		if(curWarna != kata[idx]) {
			if(kata[idx] == 'w') {
				ans++;
				isVisited[idx] = true;
				idx = ubahIndeks(idx, isMaju);
			}else{
				break;	
			}
		}else{
			ans++;
			isVisited[idx] = true;
			idx = ubahIndeks(idx, isMaju);
		}
	}
	return ans;
}

int determineIdxAwal(int idx, bool isMaju) {
	int idxAwal;
	if(isMaju) {
		idxAwal = idx;
	}else{
		idxAwal = idx;
		if(idxAwal < 0){idxAwal+=n;}
	}
	return idxAwal;
}

int process(int idx, bool isMaju) {
	int idxAwal = determineIdxAwal(idx, isMaju);

	char curWarna = kata[idx];
	if(curWarna=='w'){
		curWarna = 'r';
	}
	
	//nanti buat curWarna yang b
	int ans1, ans2;
	// if(isMaju){
	// 	printf("maju ");
	// }else{
	// 	printf("mundur ");
	// }
	// printf("idxAwal: %d\n",idxAwal);
	ans1 = hitung(curWarna, idxAwal, isMaju);
	int i;
	if(isMaju) {
		for(i=0;i<n;i++){
			if(isVisited[i]) {
				isVisited1[i] = true;
			}else{
				isVisited1[i] = false;
			}
		}
	}

	memset(isVisited, false, sizeof isVisited);
	
	curWarna = kata[idxAwal];
	if(curWarna=='w'){
		curWarna = 'b';
	}
	ans2 = hitung(curWarna, idxAwal, isMaju);
	if(isMaju) {
		for(i=0;i<n;i++){
			if(isVisited[i]) {
				isVisited2[i] = true;
			}else{
				isVisited2[i] = false;
			}
		}
	}
	
	if(ans1 < ans2) {
		for(i=0;i<n;i++){
			isVisited1[i] = isVisited2[i];
		}
	}

	// printf("ans1: %d ans2: %d\n",ans1,ans2);
	return max(ans1,ans2);

}

int main(){
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int i,j;
	
	scanf("%d",&n);
	cin>>kata;
	
	int ans = -1;

	for(i=0;i<n;i++){
		memset(isVisited, false, sizeof isVisited);
		int ans1 = process(i, true);
		memset(isVisited, false, sizeof isVisited);
		int ans2 = process(i-1, false);
		ans = max(ans, ans1+ans2);
	}
	printf("%d\n",ans);
	return 0;
};