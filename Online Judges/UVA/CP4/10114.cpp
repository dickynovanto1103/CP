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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
	int dur, numRecords;
	long double dp, loan;
	while(scanf("%d %Lf %Lf %d", &dur, &dp, &loan, &numRecords) && (dur >= 0)) {
		long double totValue = dp + loan;
		long double totOwe = loan; 
		int depreciationMonths[numRecords + 1];
		long double depreciations[numRecords + 1];
		for(int i=0;i<numRecords;i++){
			scanf("%d %Lf", &depreciationMonths[i], &depreciations[i]);
		}

		// if(dur == 0) {
		// 	puts("0 months");
		// 	continue;
		// }
		double paymentPerMonth = loan / dur;


		int idxRecord = 0;
		totValue = totValue * (1.0 - depreciations[0]);
		if(totOwe < totValue) {
			puts("0 months");
			continue;
		}
		bool printed = false;
		for(int i=1;i<=dur;i++){
			//determining depreciation rate;
			double depr;
			if(idxRecord == numRecords - 1) {
				depr = depreciations[numRecords - 1];
			}else if(i == depreciationMonths[idxRecord + 1]) {
				depr = depreciations[idxRecord + 1];
				idxRecord++;
			}else{
				depr = depreciations[idxRecord];
			}

			totOwe -= paymentPerMonth;
			totValue = totValue * (1 - depr);
			// printf("month: %d --> totOwe: %Lf, totValue: %Lf\n",i, totOwe, totValue);
			if((totOwe < totValue) || i == dur) {
				if(i == 1) {
					puts("1 month");
				}else{
					printf("%d months\n", i);
				}
				printed = true;
				break;
			}
		}
	}
	
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};