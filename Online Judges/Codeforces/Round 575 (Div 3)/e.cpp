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
	int q,i,j;
	scanf("%d",&q);
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	while(q--){
		int b,w, tempB, tempW;
		scanf("%d %d",&b,&w);
		assert(b >= 1 && w >= 1);
		tempB = b; tempW = w;
		vii listKoor;
		map<ii,int> mapper;
		int cnt = 0;
		int start;
		if(b > w){
			start = 4;
		}else{
			start = 3;
		}
		int minim = 2*min(b,w);
		for(i=start;i<=start + minim - 1;i++){
			listKoor.pb(ii(2,i));
		}
		b-=minim/2; w -= minim/2;
		// printf("sini b: %d w: %d\n",b,w);
		if(b > 0) {
			for(i=start;i<=start + minim - 1;i++){
				if(((3 + i) % 2) == 1){
					listKoor.pb(ii(3,i));
					b--;
					if(b == 0){break;}
				}
			}
			if(b > 0){
				for(i=start;i<=start + minim - 1;i++){
					if(((1 + i) % 2) == 1){
						listKoor.pb(ii(1,i));
						b--;
						if(b == 0){break;}
					}
				}	
			}
			if(b == 1){
				listKoor.pb(ii(2, start-1));
				b--;
			}			
		}
		if(w > 0) {
			for(i=start;i<=start + minim - 1;i++){
				if(((3 + i) % 2) == 0){
					listKoor.pb(ii(3,i));
					w--;
					if(w == 0){break;}
				}
			}
			if(w > 0){
				for(i=start;i<=start + minim - 1;i++){
					if(((1 + i) % 2) == 0){
						listKoor.pb(ii(1,i));
						w--;
						if(w == 0){break;}
					}
				}	
			}

			if(w == 1){
				listKoor.pb(ii(2,start-1));
				w--;
			}
			
		}
		// printf("b: %d w: %d\n",b,w);
		if(b == 0 && w == 0){
			printf("YES\n");
			int sumB = 0, sumW = 0;
			for(i=0;i<listKoor.size();i++){
				ii pas = listKoor[i];
				printf("%d %d\n",pas.first, pas.second);
				if((pas.first + pas.second)%2 == 0){
					sumW++;
				}else{
					sumB++;
				}
			}
			assert(sumB == tempB && sumW == tempW);
		}else{
			printf("NO\n");
		}
		
	}
	return 0;
};