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
	int n,i,j;
	int a[110], b[110];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	int cnt = 0;
	for(i=0;i<n;i++){
		int bil1 = a[i], bil2 = b[i];
		for(j=0;j<n;j++){
			if(a[j]<bil1 && b[j] > bil2){
				cnt++; break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};