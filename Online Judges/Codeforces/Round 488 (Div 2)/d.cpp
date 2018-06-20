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

vector<set<int> > AdjList1,AdjList2;

int main(){
	int n,m,i,j;
	vii a, b;
	scanf("%d %d",&n,&m);

	AdjList1.assign(n+1,set<int>() );
	AdjList2.assign(m+1,set<int>() );

	for(i=0;i<n;i++){
		int bil1, bil2;
		scanf("%d %d",&bil1,&bil2);
		a.pb(ii(bil1,bil2));
	}
	for(i=0;i<m;i++){
		int bil1, bil2;
		scanf("%d %d",&bil1,&bil2);
		b.pb(ii(bil1,bil2));
	}
	for(i=0;i<n;i++){
		int a1 = a[i].first,a2 = a[i].second;
		for(j=0;j<m;j++){
			int b1 = b[j].first ,b2 = b[j].second;
			if((a1==b1 && a2 == b2) || (a1==b2 && a2 == b1)){
				continue;
			}
			if(a1 == b1 || a1 == b2 || a2==b1 || a2==b2) {
				if(a1==b1 || a1==b2){
					// printf("a1: %d i: %d\n",a1,i);
					AdjList1[i].insert(a1);
					AdjList2[j].insert(a1);
				}else if(a2==b1 || a2==b2) {
					// printf("a2: %d i: %d\n",a2,i);
					AdjList1[i].insert(a2);
					AdjList2[j].insert(a2);
				}
			}
		}
	}

	// for(i=0;i<m;i++){
	// 	int a1 = b[i].first,a2 = b[i].second;
	// 	for(j=0;j<n;j++){
	// 		// printf("i: %d j: %d\n",i,j);
	// 		int b1 = a[j].first ,b2 = a[j].second;
	// 		if((a1==b1 && a2 == b2) || (a1==b2 && a2 == b1)){
	// 			continue;
	// 		}
	// 		if(a1 == b1 || a1 == b2 || a2==b1 || a2==b2) {
	// 			if(a1==b1 || a1==b2){
	// 				AdjList2[i].insert(a1);
	// 			}else if(a2==b1 || a2==b2) {
	// 				AdjList2[i].insert(a2);
	// 			}
	// 		}
	// 	}
	// }

	int jumlah1 = 0, cnt1 = 0;
	bool isValid = true;
	int ans;
	int minUkuran = inf;
	set<int> s;
	for(i=0;i<n;i++){

		int ukuran = AdjList1[i].size();
		// printf("i: %d ukuran: %d\n",i,ukuran);
		if(ukuran>1){
			minUkuran = min(minUkuran,ukuran);
			isValid = false;
		}
		else if(ukuran == 1){
			ans = *AdjList1[i].begin();
			s.insert(ans);
			// printf("ans diassign ke %d\n",ans);
			jumlah1++;
		}
	}

	for(i=0;i<m;i++){
		int ukuran = AdjList2[i].size();
		if(ukuran>1){
			minUkuran = min(minUkuran,ukuran);
			isValid = false;
		}
		else if(ukuran == 1){
			ans = *AdjList2[i].begin();
			s.insert(ans);
			// printf("ans diassign ke %d\n",ans);
			cnt1++;
		}

	}
	if(!isValid){
		// printf("minUkuran: %d jumlah1 : %d cnt1: %d\n",minUkuran, jumlah1, cnt1);
		printf("-1\n");
		// if(jumlah1>0 && cnt1>0){printf("0\n");}
		// else{
		// 	printf("-1\n");	
		// }
		
	}
	else{
		if(s.size()==1){
			printf("%d\n",*(s.begin()));
		}else{
			printf("0\n");
		}
	}

	return 0;
};