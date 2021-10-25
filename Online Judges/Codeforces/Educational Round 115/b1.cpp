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
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[1010][6];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<5;j++){
				scanf("%d",&a[i][j]);
			}
		}

		bool found = false;
		for(i=0;i<5;i++){
			for(j=i+1;j<5;j++){
				int c1 = 0, c2 = 0, no = 0;
				for(int k=0;k<n;k++){
					if(a[k][i]) c1++;
					if(a[k][j]) c2++;
					if(!a[k][i] && !a[k][j]) no++;
				}
				if(c1 >= n/2 && c2 >= n/2 && !no) {found = true; break;}
			}
		}

		found ? puts("YES"): puts("NO");

	}
	
	return 0;
};