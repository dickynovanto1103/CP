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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int tt = 0;

void solve(){
	int numPerson;
	while(scanf("%d",&numPerson) == 1) {
		if(tt){puts("");}
		if(tt == 0){tt = 1;}
		vector<string> persons(numPerson);
		unordered_map<string, int> reserves;
		for(int i=0;i<numPerson;i++){
			cin>>persons[i];
		}
		for(int i=0;i<numPerson;i++){
			string person;
			cin>>person;
			int money, numPersonToShare;
			scanf("%d %d",&money, &numPersonToShare);
			if(numPersonToShare == 0) {
				continue;
			}
			int eachPersonGet = money / numPersonToShare;
			int remainder = money % numPersonToShare;
			reserves[person] += (-money + remainder);
			while(numPersonToShare--){
				string personGiven;
				cin>>personGiven;
				reserves[personGiven] += eachPersonGet;
			}
		}
		for(int i=0;i<numPerson;i++){
			cout<<persons[i]<<" "<<reserves[persons[i]]<<endl;
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};