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

vector<set<int> > storiesCreatedByUser;
vector<set<int> > storiesFollowedByUser;
vector<set<int> > usersFollowedByUser;

vector<int> getStoriesCreatedByUser(int user) {
	vi ans;
	set<int>::iterator it;
	set<int> s = storiesCreatedByUser[user];

	for(it=s.begin();it!=s.end();it++){
		ans.pb(*it);
	}
	return ans;
}

vector<int> getStoriesFollowedByUser(int user) {
	vi ans;
	set<int>::iterator it;
	set<int> s = storiesFollowedByUser[user];

	for(it=s.begin();it!=s.end();it++){
		ans.pb(*it);
	}
	return ans;
}

bool cmp(ii a, ii b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	storiesCreatedByUser.assign(250, set<int>());
	storiesFollowedByUser.assign(250, set<int>());
	usersFollowedByUser.assign(250, set<int>());
	for(i=i;i<=n;i++){
		int user;
		scanf("%d",&user);
		storiesCreatedByUser[user].insert(i);
	}
	int p,q;
	scanf("%d %d",&p,&q);
	for(i=1;i<=p;i++){
		int user1, user2;
		scanf("%d %d",&user1,&user2);
		usersFollowedByUser[user1].insert(user2); //user1 follows user2
	}
	for(i=1;i<=q;i++){
		int user, story;
		scanf("%d %d",&user,&story);
		storiesFollowedByUser[user].insert(story);
	}

	//calculate
	for(i=1;i<=m;i++){
		vii scoreList;
		for(j=1;j<=n;j++){
			//hitung score 
			if(storiesCreatedByUser[i].find(j) != storiesCreatedByUser[i].end() || storiesFollowedByUser[i].find(j) != storiesFollowedByUser[i].end()) {
				scoreList.pb(ii(-1, j));
				printf("pushed -1 %d\n",j);
				continue;
			}
			int sum = 0;
			for(int k=1;k<=m;k++){
				int bil1 = 0, bil2 = 0;

				vi storiesCreatedByUserK = getStoriesCreatedByUser(k);
				bool oneOfTheStoriesCreatedByUserKIsFollowed = false, oneOfTheStoriesFollowedByUserKIsFollowed = false;
				for(int val: storiesCreatedByUserK) {
					if(storiesFollowedByUser[i].find(val) != storiesFollowedByUser[i].end()) {
						oneOfTheStoriesCreatedByUserKIsFollowed = true;
						break;
					}
				}
				vi storiesFollowedByUserK = getStoriesFollowedByUser(k);
				for(int val: storiesFollowedByUserK) {
					if(storiesFollowedByUser[i].find(val) != storiesFollowedByUser[i].end()) {
						oneOfTheStoriesFollowedByUserKIsFollowed = true;
						break;
					}
				}

				if(usersFollowedByUser[i].find(k) != usersFollowedByUser[i].end() && 
					storiesCreatedByUser[k].find(j) != storiesCreatedByUser[k].end()) {
					sum += 6;
					printf("case 1\n");
				} else if(usersFollowedByUser[i].find(k) != usersFollowedByUser[i].end() &&
					storiesFollowedByUser[k].find(j) != storiesFollowedByUser[k].end()) {
					sum += 3;
					printf("case 2\n");
				} else if(oneOfTheStoriesCreatedByUserKIsFollowed) {
					if(storiesCreatedByUser[k].find(j) != storiesCreatedByUser[k].end()) {
						sum += 2 * 2;
						printf("case 3\n");
					} else if(storiesFollowedByUser[k].find(j) != storiesFollowedByUser[k].end()) {
						sum += 2 * 1;
						printf("case 4\n");
					}
				} else if(oneOfTheStoriesFollowedByUserKIsFollowed) {
					if(storiesCreatedByUser[k].find(j) != storiesCreatedByUser[k].end()){
						sum += 1 * 2;
						printf("case 5\n");
					}else if(storiesFollowedByUser[k].find(j) != storiesFollowedByUser[k].end()){
						sum += 1 * 1;
						printf("case 6\n");
					}
				}
				
				// if(k == i) {
				// 	continue;
				// }else if (usersFollowedByUser[i].find(k) != usersFollowedByUser[i].end()){
				// 	bil1 = 3;
				// }else if(isTrue2) {
				// 	bil1 = 2;
				// }else if(oneOfTheStoriesFollowedByUserKIsFollowed) {
				// 	bil1 = 1;
				// }

				// if(storiesCreatedByUser[k].find(j) != storiesCreatedByUser[k].end()){
				// 	bil2 = 2;
				// }else if(storiesFollowedByUser[k].find(j) != storiesFollowedByUser[k].end()){
				// 	bil2 = 1;
				// }

				// printf("j: %d k: %d bil1: %d bil2: %d kali: %d\n", j, k, bil1, bil2, bil1*bil2);

				// sum += bil1 * bil2;
			}
			printf("pushed sum: %d j: %d\n",sum, j);
			scoreList.pb(ii(sum, j));
		}

		sort(scoreList.begin(), scoreList.end(), cmp);
		printf("%d %d %d\n", scoreList[0].second, scoreList[1].second, scoreList[2].second);
	}
	
	return 0;
};