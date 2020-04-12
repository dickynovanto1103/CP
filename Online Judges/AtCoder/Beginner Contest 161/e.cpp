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

//the definition of must-working days is that working on these days is a must, cannot be earlier and cannot be later. For example, we can define the earliest
// and the latest day for x-th working day, we can use greedy operation
int main(){
	int n,k,c;
	string s;
	scanf("%d %d %d",&n,&k,&c);
	cin>>s;

	//for first iteration, we pick greedily so that we get the earliest day for x-th working day. earliest[x] = the earliest day for x-th working day
	vi earliest, latest;
	int i;
	for(i=0;i<n;i++){
		if(s[i] == 'o'){
			earliest.pb(i);
			// printf("push earliest: %d\n",i);
			if(earliest.size() == k){break;}
			i += c;
		}
	}
	for(i=n-1;i>=0;i--){
		if(s[i] == 'o'){
			latest.pb(i);
			// printf("push latest: %d\n",i);
			if(latest.size() == k){break;}
			i -= c;
		}
	}

	assert(earliest.size() == latest.size() && latest.size() == k);
	reverse(latest.begin(), latest.end());
	for(i=0;i<k;i++){
		if(earliest[i] == latest[i]){
			printf("%d\n",earliest[i] + 1);
		}
	}
	return 0;
};