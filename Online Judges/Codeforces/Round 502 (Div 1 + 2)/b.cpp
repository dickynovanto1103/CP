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

const int maxn = 1e5 + 5;
ll cnt01, cnt10, cnt11, cnt00;

int main(){
	int n,i,j;
	string kata1,kata2;
	scanf("%d",&n);
	cin>>kata1>>kata2;
	
	for(i=0;i<n;i++){
		char kar1 = kata1[i], kar2 = kata2[i];
		if(kar1 == '0' && kar2 == '1'){cnt01++;}
		else if(kar1 == '0' && kar2 == '0'){cnt00++;}
		else if(kar1 == '1' && kar2 == '0'){cnt10++;}
		else{cnt11++;}
	}
	ll sum = 0;
	for(i=0;i<n;i++){
		char kar1 = kata1[i], kar2 = kata2[i];
		if(kar1 == '0' && kar2 == '1'){

		}
		else if(kar1 == '0' && kar2 == '0'){
			sum += (cnt10 + cnt11);
		}
		else if(kar1 == '1' && kar2 == '0'){
			sum += cnt01;
		}
		else{}
	}
	printf("%lld\n",sum);
	return 0;
};