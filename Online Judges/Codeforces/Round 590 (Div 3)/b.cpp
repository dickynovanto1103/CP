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

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	set<int> s;
	queue<int> q;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(s.find(bil) == s.end()) {
			if(q.size() == k){
				int depan = q.front();
				s.erase(depan);
				q.pop();	
			}
			q.push(bil);
			s.insert(bil);
		}
	}
	vi a;
	int ukuran = q.size();
	while(!q.empty()){
		a.pb(q.front()); q.pop();
	}
	reverse(a.begin(), a.end());
	printf("%d\n",ukuran);
	for(i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
};