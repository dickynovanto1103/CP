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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
multiset<int> q1;
multiset<int>::iterator it;
multiset<int> q2;

void addBil(int bil) {
	// printf("add bil: %d\n",bil );
	if(q2.empty()) {
		it = --q1.end();
		int front = *(it);
		if(bil <= front) {
			q1.insert(bil);
			q1.erase(it);
			q2.insert(front);
		}else{
			q2.insert(bil);
		}
		int selisih = abs((int)q1.size() - (int)q2.size());
		if(selisih >= 2) {
			if(q1.size() > q2.size()) {
				int front = *(it); q1.erase(it);
				q2.insert(front);
			}else{
				int front = *(q2.begin()); q2.erase(q2.begin());
				q1.insert(front);
			}
		}
	}else if(q1.empty()){
		it = q2.begin();
		int front = *(it);
		if(bil >= front) {
			q2.insert(bil);
			q2.erase(it);
			q1.insert(front);
		}else{
			q1.insert(bil);
		}
		int selisih = abs((int)q1.size() - (int)q2.size());
		if(selisih >= 2) {
			if(q1.size() > q2.size()) {
				it = --q1.end();
				int front = *(it); q1.erase(it);
				q2.insert(front);
			}else{
				int front = *(q2.begin()); q2.erase(q2.begin());
				q1.insert(front);
			}
		}
	}else{
		it = --q1.end();
		int front1 = *(it); int front2 = *(q2.begin());
		// printf("front1: %d front2: %d bil: %d\n",front1, front2,bil );
		if(bil <= front1){q1.insert(bil);}
		else{q2.insert(bil);}
		int selisih = abs((int)q1.size() - (int)q2.size());
		if(selisih >= 2) {
			if(q1.size() > q2.size()) {
				
				int front = *(it); q1.erase(it);
				q2.insert(front);
			}else{
				int front = *(q2.begin()); q2.erase(q2.begin());
				q1.insert(front);
			}
		}
	}
}

void removeBil(int bil) {
	// printf("removeBil: %d\n",bil );
	if(q1.empty()) {
		//cari di q2
		it = q2.find(bil);
		q2.erase(it);
	}else if(q2.empty()) {
		it = q1.find(bil);
		q1.erase(it);
	}else {
		it = --q1.end();
		int front1 = *(it), front2 = *q2.begin();
		if(bil <= front1) {
			it = q1.find(bil);
			q1.erase(it);
		}else{
			it = q2.find(bil);
			q2.erase(it);
		}
	}
	
	int selisih = abs((int)q1.size() - (int)q2.size());
	if(selisih >= 2) {
		if(q1.size() > q2.size()) {
			int front = *(it); q1.erase(it);
			q2.insert(front);
		}else{
			int front = *(q2.begin()); q2.erase(q2.begin());
			q1.insert(front);
		}
	}
}

int n;


int getMaxMedian(vector<int> a, int k) {
	int i;
	q1.clear(); q2.clear();
	q1.insert(a[0]);
	// printf("pertama add %d\n",a[0]);

	for(i=1;i<k;i++){
		int bil = a[i];
		addBil(bil);
		
	}
	int maks = 0;
	if(q1.size() > q2.size()){
		maks = max(maks, *(--q1.end()));
		// printf("q1.end; %d\n", *(--q1.end()));
		// printf("maks jd: %d\n",maks);
	}else {
		maks = max(maks, *(q2.begin()));
		// printf("q2 begin; %d\n", *q2.begin());
		// printf("maks jd: %d\n",maks);
	}
	int kiri = 0, kanan = k-1;
	while(kanan < (n-1)) {
		kanan++;
		int bil = a[kanan];
		addBil(bil);
		removeBil(a[kiri]);
		kiri++;
		// printf("kiri: %d kanna: %d ukuran: %d %d\n",kiri, kanan,(int)q1.size() ,(int)q2.size());
		// it = --q1.end();

		// printf("it; %d size; %d %d\n", *it,(int)q1.size(),(int)q2.size());
		if(q1.size() > q2.size()){
			maks = max(maks, *(--q1.end()));
			// printf("maks jd: %d\n",maks);
		}else {
			maks = max(maks, *(q2.begin()));
			// printf("maks jd: %d\n",maks);
		}
	}
	// printf("direturn maks; %d\n", maks);
	return maks;
}

int main(){
	int k,i,j;
	scanf("%d %d",&n,&k);
	vector<int> a(maxn), b(maxn), c(maxn);
	// int a[maxn], b[maxn], c[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	
	vi ans;
	ans.pb(getMaxMedian(a,k));
	ans.pb(getMaxMedian(b,k));
	ans.pb(getMaxMedian(c,k));
	sort(ans.begin(), ans.end());
	// for(int bil: ans) {
	// 	printf("%d\n",bil );
	// }
	printf("%d\n",ans[1]);
	return 0;
};