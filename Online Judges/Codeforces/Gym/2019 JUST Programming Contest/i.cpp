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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e4 + 4;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n,k;
		scanf("%d %d",&n,&k);
		multiset<int> s;
		multiset<int>::iterator it;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			s.insert(bil);
		}

		while(k--){
			int awal = *s.begin();
			s.erase(s.begin());
			// printf("awal; %d\n",awal);
			s.insert(-awal);
			// printf("dinsert: %d\n",);
		}
		int sum = 0;
		for(it=s.begin();it!=s.end();it++){
			sum += *it;
		}
		printf("%d\n",sum);
	}
	return 0;
};