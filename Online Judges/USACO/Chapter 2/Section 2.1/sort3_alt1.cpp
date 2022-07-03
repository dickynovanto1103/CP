/*
ID: dickyno1
LANG: C++14
TASK: sort3
*/

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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	int n,i,j;
	scanf("%d",&n);
	int a[1010], sorted[1010];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sorted[i] = a[i];
	}

	sort(sorted, sorted + n);
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] != sorted[i] && a[j] != sorted[j] && a[i] == sorted[j] && a[j] == sorted[i]) {
				swap(a[i], a[j]);
				cnt++;
				break;
			}
		}
	}

	//other left are cycle of 1 2 and 3 not in the right places
	int cntOther = 0;
	for(int i=0;i<n;i++){
		if(a[i] != sorted[i]) {
			cntOther++;
		}
	}




	printf("%d\n", cnt + (cntOther / 3) * 2);
	
	return 0;
};