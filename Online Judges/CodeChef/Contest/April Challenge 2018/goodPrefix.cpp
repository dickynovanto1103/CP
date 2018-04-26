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
	int tc,i,j,n;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata;
		scanf("%d",&n);
		int pjg = kata.length();
		ll banyakA = 0, banyakB = 0;
		ll sum = 0, curCnt = 0;
		for(i=0;i<n;i++){
			ll cnt = 0;
			for(j=0;j<pjg;j++){
				char kar = kata[j];
				if(kar=='a'){banyakA++;}
				else{banyakB++;}
				if(banyakA > banyakB){cnt++;}
			}
			// sum+=cnt;
			if(curCnt < cnt){curCnt = cnt; sum+=cnt;}
			else if(curCnt == cnt){
				sum += (((ll)n-(ll)i)*(cnt));
				break;
			}else{
				curCnt = cnt; sum+=cnt;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
};