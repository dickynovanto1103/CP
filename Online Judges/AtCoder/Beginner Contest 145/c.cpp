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

int x[9],y[9];

double jarak(int i, int j){
	double selisihx = abs(x[i] - x[j]);
	double selisihy = abs(y[i] - y[j]);
	return sqrt(selisihy*selisihy + selisihx*selisihx);
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){scanf("%d %d",&x[i],&y[i]);}
	int a[10];
	for(i=0;i<n;i++){a[i] = i;}
	double sum = 0;
	int cnt = 0;
	do{
		double tot = 0;
		for(i=0;i<n-1;i++){
			tot += jarak(a[i], a[i+1]);
		}
		sum += tot;
		cnt++;
	}while(next_permutation(a,a+n));
	printf("%.9lf\n",sum/(double)cnt);
	return 0;
};