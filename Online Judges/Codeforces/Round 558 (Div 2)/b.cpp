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

const int maxn = 1e5 + 5;

void show(multiset<int> s, set<int> s2){
	printf("multiset:");
	multiset<int>::iterator it;
	set<int>::iterator it2;
	for(it=s.begin();it!=s.end();it++){
		printf(" %d",*it);
	}
	printf("\n");
	printf("set:");
	for(it2=s2.begin();it2!=s2.end();it2++){
		printf(" %d",*it2);
	}
	printf("\n");
}

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	multiset<int> s;
	multiset<int>::iterator it;
	set<int> s2;
	set<int>::iterator it2;
	int cnt[maxn];
	memset(cnt, 0, sizeof cnt);
	int ans = 1;
	for(i=1;i<=n;i++){
		// printf("i: %d\n",i);
		scanf("%d",&a[i]);
		it = s.find(cnt[a[i]]);
		it2 = s2.find(cnt[a[i]]);
		if(it != s.end())
			s.erase(it);
		if(it2 != s2.end() && s.find(cnt[a[i]]) == s.end())
			s2.erase(it2);
		cnt[a[i]]++;

		s.insert(cnt[a[i]]);
		s2.insert(cnt[a[i]]);
		// show(s, s2);
		if(s.size() == 1){ans = i; continue;}

		int maks = *(--s.end()), minim = *s.begin();
		// printf("maks: %d minim; %d\n",maks, minim);
		if(maks == minim) {
			if(maks == 1){
				// printf("ans jd: %d\n",ans);
				ans = i;
			}
		}else{
			if(s2.size() > 2){continue;}	
			// printf("s2 size; %d\n",(int)s2.size());
			if(maks - minim == 1){
				int cntMaks = s.count(maks);
				if(cntMaks == 1){ans = i;}
			}
			if(minim == 1){
				int cntMinim = s.count(minim);
				if(cntMinim == 1){
					// printf("halo ans; %d\n",i);
					ans = i;
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
};