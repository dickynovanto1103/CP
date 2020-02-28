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
	int tc,i,j;
	scanf("%d",&tc);

	int pangkat2[100], pangkatAkar2[100];
	memset(pangkat2, 0, sizeof pangkat2);
	memset(pangkatAkar2, 0, sizeof pangkatAkar2);
	pangkat2[1] = 0; pangkatAkar2[1] = 0;
	for(i=2;i<100;i++){
		if(i%2 == 0){
			pangkat2[i] = pangkat2[i-1] + 1;
			pangkatAkar2[i] = pangkatAkar2[i-1];
		}else{
			pangkat2[i] = pangkat2[i-1] - 1;
			pangkatAkar2[i] = pangkatAkar2[i-1] + 1;
			if(pangkatAkar2[i] == 2){
				pangkat2[i]++;
				pangkatAkar2[i] = 0;
			}
		}
		// printf("i; %d 2: %d pangkatAkar2: %d\n",i,pangkat2[i], pangkatAkar2[i]);
	}

	while(tc--){
		int r,k;
		scanf("%d %d",&r,&k);
		ll luas = 0;
		ll totPangkat2 = pangkat2[k]*2 + pangkatAkar2[k];
		// printf("totPangkat2: %lld\n",totPangkat2 );
		if(k%2 == 0) {
			printf("%lld\n",(1LL<<totPangkat2)*(ll)r*r );
		}else{
			printf("%lldPI\n",(1LL<<totPangkat2)*(ll)r*r );
		}
	}
	return 0;
};