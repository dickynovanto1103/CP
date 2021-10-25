//this approach: (just binary search directly the edges in the input) is wrong because of this case:
/*
	5
	1 4 1
	2 3 1
	3 4 2
	3 5 1
*/
// with that test case, we ignore edge 3 4 which is the correct answer
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

int n;
vii edges;
int ansAll = -1;

int askEdgesBetweenIdx(int a, int b) {
	set<int> s;
	set<int>::iterator it;
	for(int i=a;i<=b;i++){
		int x, y;
		x = edges[i].first, y = edges[i].second;
		s.insert(x); s.insert(y);
	}

	printf("? %d",int(s.size()));
	for(it=s.begin(); it!=s.end();it++){
		printf(" %d",*it);		
	}
	printf("\n");
	fflush(stdout);

	int ans;
	scanf("%d",&ans);
	return ans;
}

void askAll() {
	printf("? %d", n);
	for(int i=0;i<n;i++){
		printf(" %d",i+1);
	}
	printf("\n");
	fflush(stdout);

	scanf("%d",&ansAll);
	assert(ansAll != -1);
}

int main(){
	scanf("%d",&n);
	edges.resize(n-1);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edges[i] = ii(a,b);
	}

	sort(edges.begin(), edges.end());

	askAll();

	int kiri = 0, kanan = n-2, mid;
	ii ansEdge = ii(-1, -1);
	while(kiri <= kanan) {
		mid = (kiri + kanan) / 2;
		// printf("kiri: %d mid: %d\n", kiri, mid);
		int ans = askEdgesBetweenIdx(kiri, mid);
		if(ans == ansAll && kiri == mid) {
			ansEdge = edges[kiri];
			break;
		}
		if(ans < ansAll) {
			kiri = mid+1;
			if(kiri == kanan) {
				ansEdge = edges[kiri];
				break;
			}
		}else if(ans == ansAll){
			kanan = mid;
		}else{
			exit(100);
		}
	}

	assert(ansEdge != ii(-1,-1));
	
	printf("! %d %d\n",ansEdge.first, ansEdge.second);
	fflush(stdout);
	return 0;
};