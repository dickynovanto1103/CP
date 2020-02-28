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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[10];
	int col[] = {1,2,3,4,5,6,1000};
	vii edge;
	set<ii> s, temp;
	set<ii>::iterator it;
	int cntSisa[7];

	for(i=1;i<=6;i++){
		for(j=i;j<=6;j++){
			s.insert(ii(i,j));
			cntSisa[i]++; cntSisa[j]++;
		}
	}
	temp = s;
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge.pb(ii(a,b));
	}

	int ans = 0;
	for(int tt=1;tt<=6;tt++){
		col[6] = tt;
		sort(col, col+7);
		do{
		for(i=1;i<=n;i++){
			a[i] = col[i-1];
			// printf("warna[%d]:%d\n",i,a[i]);
		}
		// printf("\n");
		int cnt = 0;
		for(i=0;i<m;i++){
			int x,y;
			ii pas = edge[i];
			x = a[pas.first], y = a[pas.second];
			if(x > y){swap(x,y);}
			if(s.find(ii(x,y)) != s.end()){
				cnt++;
				s.erase(ii(x,y));
				cntSisa[x]--; cntSisa[y]--;
			}
		}
		// int sisa = s.size();
		// printf("cnt: %d\n",cnt);
		// if(sisa){

		// 	printf("ukuran sisa: %d\n",(int)s.size());

		// 	for(it=s.begin();it!=s.end();it++){
		// 		ii pas = *it;
		// 		printf("%d %d\n",pas.first, pas.second);
		// 	}
		// }
		
		// for(i=0;i<m;i++){
		// 	int x,y;
		// 	ii pas = edge[i];
		// 	x = a[pas.first], y = a[pas.second];
		// 	int idx1000 = -1;
		// 	if(x == 1000){idx1000 = pas.first;}
		// 	else if(y == 1000){idx1000 = pas.second;}
		// 	if(x > y){swap(x,y);}
		// 	if(y == 1000){
		// 		for(j=1;j<=6;j++){
		// 			if(s.find(ii(x,j)) != s.end()){
		// 				cnt++;
		// 				// printf("pas.first: %d pas.second: %d sini x: %d j: %d\n",pas.first, pas.second,x,j);
		// 				a[idx1000] = j;
		// 				s.erase(ii(x,j));
		// 				break;
		// 			}
		// 		}
		// 		// if(s.find(ii(x,y)) != s.end()){
		// 		// 	cnt++;
		// 		// 	s.erase(ii(x,y));
		// 		// }
		// 	}
			
		// }
		// printf("ukuran %d\n",(int)s.size());
		ans = max(ans, cnt);
		s = temp;
	}while(next_permutation(col, col+7));
	}
	
	printf("%d\n",ans);
	return 0;
};