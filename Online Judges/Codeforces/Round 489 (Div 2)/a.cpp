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
	set<int> s;
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(bil!=0){
			s.insert(bil);
		}
	}
	printf("%d\n",(int)s.size());
	return 0;
};