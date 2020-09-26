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

ordered_set s;

int n;

ll f(int mid){
	int minim = *s.find_by_order(0);
	int maks = *s.find_by_order(n-1);
	int tengah = *s.find_by_order(mid);
	int tengah1;
	if(mid+1 <= n) {
		tengah1 = *s.find_by_order(mid+1);
	}else{
		tengah1 = maks;
	}
	// printf("mid: %d tengah: %d tengah1: %d minim: %d maks: %d\n",mid, tengah, tengah1, minim, maks);
	return (tengah - minim) + (maks - tengah1);
}

ll binser() {
	int kiri = 0, kanan = n-1, mid;
	ll ans = (ll)inf*(ll)inf;
	while((kanan - kiri) > 1) {
		// printf("kiri: %d kanan: %d\n",kiri, kanan);
		mid = (kiri + kanan)/2;
		ll ans1 = f(mid);
		ll ans2 = f(mid+1);
		// printf("mid: %d ans1: %lld ans2: %lld\n",mid, ans1, ans2);
		if(ans1 > ans2) {
			ans = min(ans2, ans);
			kiri = mid;
		}else{
			ans = min(ans1, ans);
			kanan = mid;
		}
	}
	// printf("%lld\n",ans);
	return ans;
}

int main(){
	
	int q,i,j;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		s.insert(a);
	}

	binser();

	while(q--){
		int com, bil;
		scanf("%d %d",&com,&bil);
		if(com){
			s.insert(bil);
			n++;
		}else{
			s.erase(bil);
			n--;
		}
		ll ans = binser();
		if(n <= 1){
			printf("0\n");
		}else{
			int bil1 = *s.find_by_order(1);
			int last = *s.find_by_order(n-1);
			ans = min(ans, (ll)(last - bil1));

			int bilnminus = *s.find_by_order(n-2);
			int first = *s.find_by_order(0);
			ans = min(ans, (ll)(bilnminus-first));

		}
		printf("%lld\n",ans);

	}
	// s.insert(1);
	// s.insert(2);
	// s.insert(4);
	// s.insert(8);
	// s.insert(16);
	// s.erase(16);
	// printf("find by order\n");
	// printf("%d\n",*s.find_by_order(0));
	// printf("%d\n",*s.find_by_order(1));
	// printf("%d\n",*s.find_by_order(2));
	// printf("%d\n",*s.find_by_order(3));
	// printf("%d\n",*s.find_by_order(4));
	// printf("%d\n",*s.find_by_order(5));
	// printf("order of key\n");
	// printf("%lu\n",s.order_of_key(-5));
	// printf("%lu\n",s.order_of_key(1));
	// printf("%lu\n",s.order_of_key(2));
	// printf("%lu\n",s.order_of_key(16));
	// printf("%lu\n",s.order_of_key(17));
	return 0;
};