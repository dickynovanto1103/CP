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
	set<int>::iterator it;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int bil;
		scanf("%d",&bil); s.insert(bil);
	}
	s.insert(2000000000);
	int bil;
	scanf("%d",&bil);
	
	it = s.lower_bound(bil);
	
	
	printf("hasil lower_bound: %d\n",*it);
	if(it==s.begin()){printf("ini awal bro\n");}
	else{printf("ga awal\n");}
	return 0;
};