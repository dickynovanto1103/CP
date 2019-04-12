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

vector<vi> mat, harapan;
void cetak(const vector<vi>& mat){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

vector<vi> tambah(const vector<vi>& mat, int x, int y){
	vector<vi> ans;
	ans.assign(3,vi(3));
	ans = mat;
	// printf("ans awal:\n");
	// cetak(ans);
	int i,j;
	for(i=0;i<3;i++){
		ans[i][y]++; ans[i][y]%=4;
		// printf("ans[%d][%d]: %d\n",i,j,ans[i][y]);
	}
	for(j=0;j<3;j++){
		ans[x][j]++; ans[x][j]%=4;
		// printf("ans[%d][%d]: %d\n",i,j,ans[i][j]);
	}
	ans[x][y]--;
	if(ans[x][y] < 0){ans[x][y] += 4;}
	// printf("ans jd:\n");
	// cetak(ans);
	return ans;
}


int main(){
	int i,j;
	mat.assign(3, vi(3));
	harapan.assign(3, vi(3,0));
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			int bil;
			scanf("%d",&bil);
			mat[i][j] = bil;
		}
	}
	map<vector<vi>, int> mapper;
	mapper[mat] = 0;
	queue<vector<vi> > q;
	q.push(mat);
	// cetak(harapan);
	while(!q.empty()){
		vector<vi> front = q.front(); q.pop();

		// cetak(front);
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				// printf("i: %d j: %d\n",i,j);
				vector<vi> baru = tambah(front, i,j);
				// printf("baru:\n");
				// cetak(baru);
				if(mapper.find(baru) == mapper.end()){
					mapper[baru] = mapper[front] + 1;
					q.push(baru);
				}
			}
		}
	}

	if(mapper.find(harapan) == mapper.end()){printf("-1\n");}
	else{printf("%d\n",mapper[harapan]);}
	return 0;
};