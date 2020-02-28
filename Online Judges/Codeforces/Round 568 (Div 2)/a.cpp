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

int main(){
	int a,b,c,d;

	scanf("%d %d %d %d",&a,&b,&c,&d);
	int ar[] = {a,b,c};
	sort(ar, ar+3);
	int jarak1 = abs(ar[0] - ar[1]);
	int satu = (abs(ar[0] -ar[1]) < d ? d - jarak1 : 0);
	int jarak2 = abs(ar[1] - ar[2]);
	int dua = (jarak2 < d ? d - jarak2 : 0);
	printf("%d\n",satu + dua);
	return 0;
};