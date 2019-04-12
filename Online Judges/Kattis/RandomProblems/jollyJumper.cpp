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

const int maxn = 3e3 + 3;

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		int a[maxn];
		set<int> s;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		bool isValid = true;
		for(i=0;i<n-1;i++){
			int diff = abs(a[i] - a[i+1]);
			if(diff > n-1 || diff < 1){isValid = false; break;}
			s.insert(diff);
		}
		if(s.size() != n-1){isValid = false;}
		if(isValid){printf("Jolly\n");}
		else{printf("Not jolly\n");}

	}
	return 0;
};