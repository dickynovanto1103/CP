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

const int maxn = 500000;

int a[maxn];

int main(){
	int n,i,j;
	scanf("%d\n",&n);
	int l = 250000, r = 250000;
	int tempat[200010];
	memset(tempat, -1, sizeof tempat);
	// string dum;
	// cin>>dum;
	bool pertama = true;
	for(i=0;i<n;i++){
		char kar;
		int idx;
		scanf("%c %d\n",&kar,&idx);
		// printf("kar: %c idx: %d\n",kar,idx);
		if(kar == 'L'){
			tempat[idx] = l;
			if(pertama){
				r++;
			}
			l--;
		}else if(kar == 'R'){
			tempat[idx] = r;
			if(pertama){l--;}
			r++;

		}else{
			int indeks = tempat[idx];
			// printf("indeks: %d\n",indeks);
			int selisih1 = indeks - l - 1;
			int selisih2 = r - indeks - 1;
			printf("%d\n",min(selisih2, selisih1));
		}
		pertama = false;
		// printf("l jadi: %d r jadi: %d\n",l,r);
	}
	return 0;
};