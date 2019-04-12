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

int main(){
	int n,m,i,j;
	int tc = 1;
	while(scanf("%d",&n) != EOF){
		printf("Case %d:\n",tc++);
		set<int> s;
		set<int>::iterator it, it2;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			s.insert(bil);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			int bil;
			scanf("%d",&bil);
			// printf("bil: %d\n\n",bil);
			int minimSelisih = inf;
			int jawab = 0;
			for(it=s.begin();it!=s.end();it++){
				int bil1 = *it;
				// printf("bil1: %d\n",bil1);
				// printf("dicari: %d\n",bil-bil1);
				s.erase(bil1);
				it2 = s.lower_bound(bil-bil1);

				if(it2 == s.end()){
					it2--;
				}
				int bil2 = *it2;
				if(it2 != s.begin()){
					it2--;	
				}
				int bil3 = *it2;
				
				// printf("bil2: %d\n",bil2);
				int sum = bil1+bil2;
				int sum1 = bil1 + bil3;
				int selisih = abs(sum - bil);
				if(selisih < minimSelisih){
					minimSelisih = selisih;
					jawab = sum;
				}
				int selisih1 = abs(sum1 - bil);
				if(selisih1 < minimSelisih){
					minimSelisih = selisih1;
					jawab = sum1;
				}
				s.insert(bil1);
			}
			printf("Closest sum to %d is %d.\n",bil, jawab);
		}
	}
	return 0;
};