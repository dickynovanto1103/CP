//not done
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

bool cmp(int a, int b) {
	return a > b;
}

ll needToFull[100001];

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int mulFull, int mulPartial) {
        sort(flowers.begin(), flowers.end(), cmp);
        int n = flowers.size();
        int numFull = 0;
        for(int i=0;i<n;i++){
        	if(flowers[i] >= target) {
        		numFull++;
        		break;
        	}
        }

        
        memset(needToFull, 0, sizeof needToFull);
        //precompute
        needToFull[numFull] = 0;
        int add = 0;
        for(int i=0;i<n;i++) {
        	if(flowers[i] < target) {
        		add++;
        		int tambah = (target - flowers[i])
        		needToFull[numFull + add] = needToFull[numFull + add - 1] + tambah;
        	}
        }

        ll ans = 0;
        //cari num full optimal
        for(int full=numFull;full <= n;full++) {
        	//qn to answer: is it possible to achieve full? bs diprecompute
        	int sisaFlowers = newFlowers;
        	if(needToFull[full] > sisaFlowers) {
        		break;
        	}
        	
        	ll currAns = (full * mulFull);

        	if(full == n) {
        		ans = max(ans, currAns);
        		break;
        	}

        	sisaFlowers -= needToFull[full];
        	//cari num partial * mulPartial
        	//lalu kita dapet sisa new flowers yang bs ditanam, kita bs cari maks minimal number
        	//caranya gmn biar ga O(N)?
        	//  kita tau next angkanya brp
        	// dikasih banyak 
        }

        return ans;
    }
};

int main(){
	int n, target, full, partial;
	ll newFlowers;

	while(cin>>n>>newFlowers>>target>>full>>partial) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		Solution sol;
		cout<<sol.maximumBeauty(a, newFlowers, target, full, partial);
	}

	
	return 0;
};