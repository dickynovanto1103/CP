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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	multiset<int> s;
	int bil;
	for(i=0;i<n;i++){scanf("%d",&bil); s.insert(bil);}
	int big = *(--s.end());
	s.erase(big);
	if(s.empty()){printf("0\n");}
	else{printf("%d\n",*(--s.end()));}
	return 0;
};