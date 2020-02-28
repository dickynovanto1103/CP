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
	scanf("%d",&n);
	int a[maxn];
	int idx[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		idx[a[i]] = i;
	}
	int awal = idx[n];
	int satu = awal-1, dua = awal + 1;
	for(i=n-1;i>=1;i--){
		if(idx[i] == satu || idx[i] == dua){
			if(idx[i] == satu){
				satu--;
			}else{
				dua++;
			}
		}else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
};