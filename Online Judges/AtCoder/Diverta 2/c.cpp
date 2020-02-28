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

int main(){
	int n,i,j;
	scanf("%d",&n);
	multiset<int> pos, neg;
	int cnt0 = 0;
	int totAbs = 0;
	for(i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		totAbs += abs(a);
		if(a < 0) {neg.insert(a);}
		else if(a == 0){cnt0++;}
		else{pos.insert(a);}
	}
	if(neg.size() && pos.size()){
		printf("%d\n",totAbs);
		while(pos.size() > 1) {
			int beginNeg = *neg.begin();
			neg.erase(neg.begin());
			int beginPos = *pos.begin();
			pos.erase(pos.begin());
			printf("%d %d\n",beginNeg, beginPos);
			neg.insert(beginNeg - beginPos);
		}
		while(neg.size()) {
			int beginNeg = *neg.begin();
			neg.erase(neg.begin());
			int beginPos = *pos.begin();
			pos.erase(pos.begin());
			printf("%d %d\n",beginPos, beginNeg);
			pos.insert(beginPos - beginNeg);
		}
		for(i=0;i<cnt0;i++){
			printf("%d 0\n",*pos.begin());
		}
		assert(*pos.begin() == totAbs);
	}else{
		if(neg.size()) {
			if(cnt0){
				printf("%d\n",totAbs);

				int beginNeg = *neg.begin();
				neg.erase(neg.begin());
				printf("0 %d\n",beginNeg);
				pos.insert(-beginNeg);
				cnt0--;
				while(cnt0){
					printf("%d 0\n",*pos.begin());
					cnt0--;
				}
				if(neg.size() == 0){return 0;}

				while(pos.size() > 1) {
					int beginNeg = *neg.begin();
					neg.erase(neg.begin());
					int beginPos = *pos.begin();
					pos.erase(pos.begin());
					printf("%d %d\n",beginNeg, beginPos);
					neg.insert(beginNeg - beginPos);
				}
				while(neg.size()) {
					int beginNeg = *neg.begin();
					neg.erase(neg.begin());
					int beginPos = *pos.begin();
					pos.erase(pos.begin());
					printf("%d %d\n",beginPos, beginNeg);
					pos.insert(beginPos - beginNeg);
				}
				assert(*pos.begin() == totAbs);

			}else{
				//pos ga ada, neg doang, 0 ga ada
				int minim = *neg.begin();
				int maks = *(--neg.end());
				if(pos.size() == 2){
					printf("%d\n",maks - minim);
					printf("%d %d\n", maks, minim);
					return 0;
				}else{
					vii listAns;
					listAns.pb(ii(maks, minim));

					pos.insert(maks - minim);
					neg.erase(neg.begin());
					neg.erase(--neg.end());
					while(pos.size() > 1) {
						int beginNeg = *neg.begin();
						neg.erase(neg.begin());
						int beginPos = *pos.begin();
						pos.erase(pos.begin());
						listAns.pb(ii(beginNeg, beginPos));
						// printf("%d %d\n",beginNeg, beginPos);
						neg.insert(beginNeg - beginPos);
					}
					while(neg.size()) {
						int beginNeg = *neg.begin();
						neg.erase(neg.begin());
						int beginPos = *pos.begin();
						pos.erase(pos.begin());
						listAns.pb(ii(beginPos, beginNeg));
						// printf("%d %d\n",beginPos, beginNeg);
						pos.insert(beginPos - beginNeg);
					}
					printf("%d\n",*pos.begin());
					for(i=0;i<listAns.size();i++){
						printf("%d %d\n", listAns[i].first, listAns[i].second);
					}
				}
			}
		}else if(pos.size()) {
			if(cnt0){
				printf("%d\n",totAbs);
				if(pos.size() == 1){
					for(i=0;i<cnt0;i++){
						printf("%d 0\n",*pos.begin());
					}
					return 0;
				}
				int beginPos = *pos.begin();
				pos.erase(pos.begin());

				printf("0 %d\n",beginPos);
				cnt0--;
				neg.insert(-beginPos);
				while(cnt0){
					printf("%d 0\n",-beginPos);
					cnt0--;
				}

				while(pos.size() > 1) {
					int beginNeg = *neg.begin();
					neg.erase(neg.begin());
					int beginPos = *pos.begin();
					pos.erase(pos.begin());
					printf("%d %d\n",beginNeg, beginPos);
					neg.insert(beginNeg - beginPos);
				}
				while(neg.size()) {
					int beginNeg = *neg.begin();
					neg.erase(neg.begin());
					int beginPos = *pos.begin();
					pos.erase(pos.begin());
					printf("%d %d\n",beginPos, beginNeg);
					pos.insert(beginPos - beginNeg);
				}
			}else{
				int minim = *pos.begin();
				int maks = *(--pos.end());
				if(pos.size() == 2){
					printf("%d\n",maks - minim);
					printf("%d %d\n", maks, minim);
					return 0;
				}else{
					vii listAns;
					listAns.pb(ii(minim, maks));

					neg.insert(minim - maks);
					pos.erase(pos.begin());
					pos.erase(--pos.end());
					while(pos.size() > 1) {
						int beginNeg = *neg.begin();
						neg.erase(neg.begin());
						int beginPos = *pos.begin();
						pos.erase(pos.begin());
						listAns.pb(ii(beginNeg, beginPos));
						// printf("%d %d\n",beginNeg, beginPos);
						neg.insert(beginNeg - beginPos);
					}
					while(neg.size()) {
						int beginNeg = *neg.begin();
						neg.erase(neg.begin());
						int beginPos = *pos.begin();
						pos.erase(pos.begin());
						listAns.pb(ii(beginPos, beginNeg));
						// printf("%d %d\n",beginPos, beginNeg);
						pos.insert(beginPos - beginNeg);
					}
					printf("%d\n",*pos.begin());
					for(i=0;i<listAns.size();i++){
						printf("%d %d\n", listAns[i].first, listAns[i].second);
					}
				}
			}
		}else{
			//ga ada neg ga ada pos..cuman 
			printf("0\n");
			for(i=0;i<cnt0-1;i++){
				printf("0 0\n");
			}
		}
	} 
	return 0;
};