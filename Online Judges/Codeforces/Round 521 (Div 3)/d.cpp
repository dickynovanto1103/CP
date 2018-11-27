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

const int maxn = 2e5 + 5;

int cnt[maxn];
int a[maxn];
vii counter;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]); cnt[a[i]]++;}
	for(i=1;i<=200000;i++){
		if(cnt[i] > 0){
			counter.pb(ii(cnt[i], i));
		}
	}
	sort(counter.begin(), counter.end(), cmp);
	int ukuran = counter.size();
	vi listBil;
	for(i=0;i<ukuran;i++){
		
	}
	return 0;
};