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

	//a:      2 2 1 3 3 3 2 3 1
	//sorted: 1 1 2 2 2 3 3 3 3

	//2 1 2 3 3 3 2 3 1
	//2 1 2 2 3 3 3 3 1
	//1 1 2 2 3 3 3 3 2
	//1 1 2 2 2 3 3 3 3

	//3 1 2 1
	//1 1 2 3

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
		if(sorted[i] == a[i]) {
			continue;
		}

		//cari sorted[i]
		int idx = -1;
		bool swapped = false;
		for(j=i+1;j<n;j++){
			if(a[j] == sorted[i]) {
				idx = j;
				if(sorted[j] == a[i]) {
					swap(a[i], a[j]);
					swapped = true;
					cnt++;
					break;
				}
			}
		}
		if(swapped) continue;
		assert(idx != -1);
		swap(a[i], a[idx]);
		cnt++;
	}

	printf("%d\n", cnt);
	
	return 0;
};