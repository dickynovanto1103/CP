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

int ar[9000001];
int mat[3001][3001];
int pre[3001][3001];

deque<int> d;

void add(int bil) {
	while(!d.empty() && d.back() > bil){
		d.pop_back();
	}
	d.push_back(bil);
}

void remove(int bil) {
	if(!d.empty()) {
		if(d.front() == bil) {
			d.pop_front();
		}else if(d.back() == bil) {
			d.pop_back();
		}
	}
}

int main(){
	int n,m,a,b,i,j;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	ll g0, x,y,z;
	scanf("%lld %lld %lld %lld",&g0,&x,&y,&z);
	ar[0] = g0;
	for(i=1;i<n*m;i++){
		ll temp = (ll)ar[i-1]*x;
		temp %= z;
		temp += y; temp %=z;
		ar[i] = temp;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat[i][j] = ar[((i)*m)+j];
			// printf("%d ",mat[i][j]);
		}
		// printf("\n");
	}
	// printf("\n");
	
	int idxRow = 0, idxCol = 0, maksCol = 0;
	for(i=0;i<n;i++){
		idxCol = 0;
		int kiri = 0, kanan = b-1;
		for(j=kiri;j<=kanan;j++){
			add(mat[i][j]);
		}
		pre[idxRow][idxCol] = d.front();
		// printf("%d ",pre[idxRow][idxCol]);
		while((kanan+1) < m) {
			int bilKiri = mat[i][kiri], bilKanan = mat[i][kanan+1];
			remove(bilKiri);
			add(bilKanan);
			
			pre[idxRow][++idxCol] = d.front();
			// printf("%d ", pre[idxRow][idxCol]);
			maksCol = max(maksCol, idxCol);
			kiri++; kanan++;
		}
		// printf("\n");
		idxRow++;
		d.clear();
	}

	ll sum = 0;

	for(j=0;j<=maksCol;j++){
		// printf("j; %d\n",j);
		int kiri = 0, kanan = a-1;
		for(i=kiri;i<=kanan;i++){
			add(pre[i][j]);
			// printf("inserted: %d\n",pre[i][j]);
		}
		sum += d.front();
		// printf("sum jd; %lld\n",sum);
		while((kanan + 1) < idxRow) {
			int bilKiri = pre[kiri][j], bilKanan = pre[kanan+1][j];
			// printf("bilKiri: %d bilKanan: %d\n",bilKiri, bilKanan);
			remove(bilKiri);
			add(bilKanan);
			
			sum += d.front();
			// printf("sum jd; %lld\n",sum);
			kiri++; kanan++;
		}
		d.clear();
	}
	printf("%lld\n",sum);
	return 0;
};