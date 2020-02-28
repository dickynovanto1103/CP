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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool beda(int n) {
	set<int> s;
	int cnt = 0;
	while(n){
		s.insert(n%10);
		n /= 10;
		cnt++;
	}
	return s.size() == cnt;
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int i,j;
	for(i=a;i<=b;i++){
		if(beda(i)){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
};