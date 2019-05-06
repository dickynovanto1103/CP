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

bool a[11];

bool isAllVisited(){
	for(int i=1;i<=9;i++){
		if(!a[i]){return false;}
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	set<int> s;

	memset(a, false, sizeof a);
	s.insert(n);
	while(1){
		n++;
		while(n%10 == 0){
			n/=10;
		}
		if(n > 0 && n<=9){a[n]=true;}
		s.insert(n);
		if(isAllVisited()){break;}
	}
	
	printf("%d\n",(int)s.size());
	return 0;
};