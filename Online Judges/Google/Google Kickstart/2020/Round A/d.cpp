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

string a[100001];
map<int, int> mapper;

void computePrefix(int n) {
	int i,j;
	int p=29;
	
	for(i=0;i<n;i++){
		int power = 1;
		int hash = 0;
		int len = a[i].size();
		for(j=0;j<len;j++){
			hash += (a[i][j] - 'A' + 1)*power;
			// printf("hash: %d\n",hash);
			mapper[hash]++;
			power *= p;
		}
	}
}

int solve(int n, int k) {
	int i,j;
	int p=29;
	int ans = 0;
	
	for(i=0;i<n;i++){
		int power = 1;
		int hash = 0;
		int len = a[i].size();
		for(j=0;j<len;j++){
			hash += (a[i][j] - 'A' + 1) * power;
			power *= p;

			int hasil = mapper[hash];
			mapper.erase(hash);
			// printf("hash: %d hasil: %d tot: %d\n",hash, hasil, ans + hasil/k);
			ans += hasil/k;
		}
	}
	return ans;
}

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		mapper.clear();
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		computePrefix(n);

		printf("Case #%d: %d\n",tt, solve(n, k));
	}
	return 0;
};