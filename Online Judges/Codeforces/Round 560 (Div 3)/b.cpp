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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	set<int> s;
	for(i=0;i<n;i++){scanf("%d",&a[i]); s.insert(a[i]);}
	sort(a,a+n);
	int day = 1;
	for(i=0;i<n;i++){
		if(a[i] < day) {
			continue;
		}else{
			day++;
			// printf("i: %d day: %d\n",i,day);
		}
	}
	printf("%d\n",day -1);
	// // while(true){
	// // 	while(!s.empty() && *s.begin() < day) {
	// // 		s.erase(s.begin());
	// // 	}
	// // 	s.erase(s.begin());
	// // 	day++;
	// // }
	// printf("%d\n",day);
	
	return 0;
};