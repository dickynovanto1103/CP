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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	int a[maxn], b[maxn], ans[maxn];
	scanf("%d",&n);
	multiset<int> s;
	multiset<int>::iterator it;
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){scanf("%d",&b[i]); s.insert(b[i]);}
	for(i=0;i<n;i++){
		int harapan = n-a[i];
		it = s.lower_bound(harapan);
		if(it == s.end()){
			it = s.begin();
			ans[i] = (a[i] + *it) % n;
			s.erase(it);
		}else{
			ans[i] = (a[i] + *it) % n;
			s.erase(it);
		}
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
};