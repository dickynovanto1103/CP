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

const int maxn = 3e5 + 5;
int cntR[maxn], cntC[maxn];
int a[maxn],b[maxn];

bool cmp(ii a, ii b){
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(){
	int r,c,m,i,j;
	scanf("%d %d %d",&r,&c,&m);

	set<ii> s;
	for(i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--; b[i]--;
		s.insert(ii(a[i], b[i]));
		cntR[a[i]]++;
		cntC[b[i]]++;
	}
	vii listR, listC;
	for(i=0;i<r;i++){
		listR.pb(ii(cntR[i], i));
	}
	for(i=0;i<c;i++){
		listC.pb(ii(cntC[i],i));
	}
	sort(listR.begin(), listR.end(), cmp);
	sort(listC.begin(), listC.end(), cmp);

	int ans = listR[0].first + listC[0].first;
	vi maxR, maxC;
	for(i=0;i<r;i++){
		if(listR[0].first == listR[i].first){
			maxR.pb(listR[i].second);
		}
	}
	for(i=0;i<c;i++){
		if(listC[i].first == listC[0].first){
			maxC.pb(listC[i].second);
		}
	}

	ll totPos = (ll)maxR.size() * (ll)maxC.size();
	if(totPos > m){
		printf("%d\n",ans);
	}else{
		int ukuranR = maxR.size(), ukuranC = maxC.size();
		for(i=0;i<ukuranR;i++){
			for(j=0;j<ukuranC;j++){
				ii pas = ii(maxR[i], maxC[j]);
				if(s.find(pas) == s.end()){
					printf("%d\n",ans);
					return 0;
				}
			}
		}
		printf("%d\n",ans-1);
	}
	
	return 0;
};