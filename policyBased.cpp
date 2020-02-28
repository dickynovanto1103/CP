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
greater<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
	ordered_set s;
	s.insert(1);
	s.insert(2);
	s.insert(4);
	s.insert(8);
	s.insert(16);
	printf("find by order\n");
	printf("%d\n",*s.find_by_order(0));
	printf("%d\n",*s.find_by_order(1));
	printf("%d\n",*s.find_by_order(2));
	printf("%d\n",*s.find_by_order(3));
	printf("%d\n",*s.find_by_order(4));
	printf("%d\n",*s.find_by_order(5));
	printf("order of key\n");
	printf("%lu\n",s.order_of_key(-5));
	printf("%lu\n",s.order_of_key(1));
	printf("%lu\n",s.order_of_key(2));
	printf("%lu\n",s.order_of_key(16));
	printf("%lu\n",s.order_of_key(17));
	return 0;
};