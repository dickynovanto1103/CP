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

int main(){
	int n,i,j;
	scanf("%d",&n);
	deque<int> dq;
	for(i=0;i<n;i++){
		string s;
		int bil;
		cin>>s;
		if(s == "push_back" || s == "push_front") {
			cin>>bil;
		}

		if(s == "push_back"){
			dq.push_back(bil);
		}else if(s == "pop_back") {
			dq.pop_back();
		}else if(s == "push_front") {
			dq.push_front(bil);
		}else if(s == "pop_front") {
			dq.pop_front();
		}

		
	}

	while(!dq.empty()) {
		int angka = dq.front(); dq.pop_front();
		// printf("test angka: %d size: %d\n", angka, dq.size());
		printf("%d\n", angka);
	}
	
	return 0;
};