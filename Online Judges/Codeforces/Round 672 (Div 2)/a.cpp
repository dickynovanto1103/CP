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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[50001], temp[50001];
	while(tc--){
		scanf("%d",&n);
		set<int> s;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			temp[i] = a[i];
			s.insert(a[i]);
		}
		if(s.size() != n){
			printf("YES\n");
			continue;
		}
		sort(temp, temp+n, cmp);
		bool sama = true;
		for(i=0;i<n;i++){
			if(a[i] != temp[i]){
				sama = false;
				break;
			}
		}
		if(sama){printf("NO\n");}
		else{printf("YES\n");}
	}
	
	return 0;
};