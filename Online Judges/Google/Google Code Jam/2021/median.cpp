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

int query(int a, int b, int c){
	printf("%d %d %d\n", a, b, c);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}

ii getNewPas(ii pas, int thirdNum, int ans) {
	// fprintf(stderr, "pas: %d %d thirdNum: %d ans: %d", pas.first, pas.second, thirdNum, ans);
	if(ans == thirdNum) {
		return pas;
	}
	if(ans == pas.first) {
		pas.first = thirdNum;
		return pas;
	}
	if(ans == pas.second){
		pas.second = thirdNum;
		return pas;
	}

	exit(103);
	assert(false);
}

void cetakVector(vi a){
	for(int el: a){
		printf("%d ",el);
	}
	printf("\n");
}

vi removeElementFromVector(vi a, int elementToRemove) {
	for(int i=0;i<a.size();i++) {
		if(a[i] == elementToRemove) {
			a.erase(a.begin() + i);
			return a;
		}
	}

	assert(false);
}

ii answerLevel[50];
void sortAnswerLevel(int maxLevel) {
	for(int i=1;i<maxLevel;i++) {
		int ans = query(answerLevel[0].first, answerLevel[i].first, answerLevel[i].second);
		assert(ans != answerLevel[0].first);
		if(ans == answerLevel[i].second) {
			swap(answerLevel[i].first, answerLevel[i].second);
		}

	}
}

int main(){
	int tc,n,q,i,j;
	scanf("%d %d %d",&tc,&n,&q);

	while(tc--){
		vi candidate;
		for(int i=1;i<=n;i++){
			candidate.pb(i);
		}
		int level = 0;
		
		while(candidate.size() > 2) {
			ii pas;
			pas.first = candidate[0], pas.second = candidate[1];
			for(i=2;i<candidate.size();i++){
				int ans = query(pas.first, pas.second, candidate[i]);
				if(ans == -1){
					return 0;
				}
				pas = getNewPas(pas, candidate[i], ans);
			}
			candidate = removeElementFromVector(candidate, pas.first);
			candidate = removeElementFromVector(candidate, pas.second);
			answerLevel[level++] = pas;
		}
		assert(candidate.size() == 2);
		answerLevel[level++] = ii(candidate[0], candidate[1]);
		// printf("level: %d\n",level);
		sortAnswerLevel(level);
		vi answerList;
		for(int i=0;i<level;i++){
			answerList.pb(answerLevel[i].first);
		}
		for(int i=level-1;i>=0;i--){
			answerList.pb(answerLevel[i].second);
		}
		for(int i=0;i<answerList.size();i++){
			if(i){printf(" ");}
			printf("%d",answerList[i]);
			assert(answerList[i] != 0);
		}
		printf("\n");
		fflush(stdout);
		
		int judgeResult;
		scanf("%d",&judgeResult);
		if(judgeResult != 1){
			return 0;
		}

	}
	
	return 0;
};