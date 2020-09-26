#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
	
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	ordered_set s;
	multiset<int> ms;
	multiset<int>::iterator mit;
	int a[100001];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	sort(a, a+n);
	ll tot = 0;
	for(i=0;i<n-1;i++){
		ms.insert(a[i+1] - a[i]);
		tot += a[i+1] - a[i];
	}

	ll biggest = 0;
	if(ms.size() > 0) {
		biggest = *ms.rbegin();
	}

	printf("%lld\n",tot - biggest);

	while(q--){
		int com, bil;
		scanf("%d %d",&com,&bil);
		// printf("com: %d bil: %d\n",com, bil);

		if(com){
			//sebelum insert check ada ga di setelahnya
			if(s.size() == 0){
				s.insert(bil);
				printf("0\n");
				continue;
			}
			int pos = s.order_of_key(bil);
			if(pos == s.size()) {
				int sebelum = *s.find_by_order(pos - 1);
				ms.insert(bil - sebelum);
				tot += (bil - sebelum);

			}else if(pos == 0) {
				int element = *s.find_by_order(0);
				assert(element - bil > 0);
				ms.insert(element - bil);
				tot += (element - bil);
			}else{
				int sebelum = *s.find_by_order(pos-1);
				int sesudah = *s.find_by_order(pos);
				
				mit = ms.find(sesudah - sebelum);
				assert(mit != ms.end());
				ms.erase(mit);
				ms.insert(sesudah - bil);
				ms.insert(bil - sebelum);
			}

			s.insert(bil);

		}else{
			if(s.size() == 1){
				s.erase(bil);
				printf("0\n");
				continue;
			}
			assert(s.size() > 1);
			int pos = s.order_of_key(bil);
			if(pos == 0) {
				int sesudah = *s.find_by_order(1);
				mit = ms.find(sesudah - bil);
				assert(mit != ms.end());
				ms.erase(mit);
				tot -= (sesudah - bil);
			}else if(pos == (int)s.size() - 1) {
				int sebelum = *s.find_by_order(pos - 1);
				mit = ms.find(bil - sebelum);
				assert(mit != ms.end());
				ms.erase(mit);
				tot -= (bil - sebelum);
			}else{
				assert(s.size() >= 3);
				int sesudah = *s.find_by_order(pos + 1);
				int sebelum = *s.find_by_order(pos - 1);
				mit = ms.find(sesudah - bil);
				assert(mit != ms.end());
				ms.erase(mit);
				mit = ms.find(bil - sebelum);
				assert(mit != ms.end());
				ms.erase(mit);

				ms.insert(sesudah - sebelum);
			}

			s.erase(bil);
		}

		int kurang = 0;
		if((int)ms.size() > 0){
			kurang = *ms.rbegin();
		}
		printf("%lld\n",tot - kurang);

	}
	return 0;
};