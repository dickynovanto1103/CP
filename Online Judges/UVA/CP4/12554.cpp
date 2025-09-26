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

vector<string> words = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

void solve(){
	int n;
	scanf("%d",&n);
	vector<string> persons(n+1);
	for(int i=0;i<n;i++){
		cin>>persons[i];
	}

	int cntSongPlayed = (n + 15) / 16;
	int idxPerson = 0;
	while(cntSongPlayed--) {
		for(string word: words) {
			cout<<persons[idxPerson]<<": "<<word<<endl;
			idxPerson++;
			if(idxPerson == n) {
				idxPerson = 0;
			}		
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