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

int main(){
	int tc,i,j;
	scanf("%d",&tc);

	while(tc--){
		int n;
		scanf("%d",&n);
		set<int> s;
		set<int>::iterator it;
		for(i=1;i<=n;i++){s.insert(i);}
		int last = 1;
		set<int> listNotBiggest;
		while(s.size() > 6){
			printf("?");
			int cnt = 0;
			for(it = s.begin(); it!=s.end();it++) {
				printf(" %d",*it);
				cnt++;
				if(cnt == 5){break;}
			}
			printf("\n");
			fflush(stdout);
			int ans1, ans2;
			scanf("%d %d",&ans1,&ans2);
			last = ans1;
			s.erase(ans1); s.erase(ans2);

		}
		if(s.size() == 5){
			s.insert(last);
		}
		vi a;
		for(it=s.begin();it!=s.end();it++){
			a.pb(*it);
		}

		int counter[101];
		memset(counter, 0, sizeof counter);
		ii jawab[101];
		for(i=0;i<6;i++){
			printf("?");
			for(j=0;j<6;j++){
				if(i!=j){
					printf(" %d",a[j]);
				}
			}
			printf("\n");
			fflush(stdout);
			int ans1, ans2;
			scanf("%d %d",&ans1,&ans2);
			counter[ans1]++; counter[ans2]++;
			int minim = min(ans1, ans2);
			int maks = max(ans1, ans2);
			jawab[a[i]] = ii(minim, maks);
			// printf("jawab[%d]: %d,%d\n",a[i], minim, maks);
			listNotBiggest.insert(ans1);
			listNotBiggest.insert(ans2);

		}
		int minim = inf, maks = -inf, idxMin, idxMaks;
		for(i=0;i<=100;i++){
			if(minim > counter[i] && counter[i]!=0){
				minim = counter[i]; idxMin = i;
			}
			if(maks < counter[i] && counter[i]!=0){
				maks = counter[i]; idxMaks = i;
			}
		}

		minim = min(idxMin, idxMaks);
		maks = max(idxMin, idxMaks);
		// printf("minim: %d maks: %d\n",minim, maks);
		bool printed = false;
		for(i=0;i<=100;i++){
			// printf("i: %d\n",i);
			if(jawab[i] == ii(minim, maks)){
				if(listNotBiggest.count(i) == 0){printf("! %d\n",i); fflush(stdout); printed = true; break;}
			}
		}
		if(!printed){assert(false);}
	}
	return 0;
};