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
typedef pair<ii, int> iii;
typedef pair<ii,iii> iiii;
typedef vector<ii> vii;

vector<iiii> ver, hor;

bool cmp(iiii a, iiii b){
	if(a.first.first == b.first.first){
		return a.second.second < b.second.second;
	}
	return a.first.first < b.first.first;
}

bool isInside(int a, int b, int c){
	return b <= a && a <= c;
}

bool isSmaller(ii a, ii b){
	int y1 = a.first, y2 = a.second, y3 = b.first, y4 = b.second;
	if(isInside(y1, y3, y4) && isInside(y2, y3, y4)){
		return true;
	}
	return false;
	// if(isInside(y3, y1, y2) && isInside(y4, y1, y2)){
	// 	return true;
	// }
	// return false;
}

bool isCompletelyInside(ii a, ii b) {
	int y1 = a.first, y2 = a.second, y3 = b.first, y4 = b.second;
	if(isInside(y1, y3, y4) && isInside(y2, y3, y4)){
		return true;
	}
	if(isInside(y3, y1, y2) && isInside(y4, y1, y2)){
		return true;
	}
	return false;
}

bool isIntersect(ii a, ii b){
	int y1 = a.first, y2 = a.second, y3 = b.first, y4 = b.second;
	// int x1 = a.first.first, y1 = a.first.second, x2 = a.second.first, y2 = a.second.second;
	// int x3 = b.first.first, y3 = b.first.second, x4 = b.second.first, y4 = b.second.second;
	if(isCompletelyInside(a, b)){return false;}
	if(isInside(y1, y3, y4) || isInside(y2, y3,y4)){return true;}
	if(isInside(y3, y1,y2) || isInside(y4, y1,y2)){return true;}
	return false;
	// if(x1 == x2 && x3 == x4 && x1 == x3) {
	// 	if(y3 <= y1 && y1 <= y4){return true;}
	// 	else if(y3 <= y2 && y2 <= y4){return true;}
	// 	else if(y1 <= y3 && y3 <= y2){return true;}
	// 	else if(y1 <= y4 && y4 <= y2){return true;}
	// 	else{return false;}
	// }else if(y1 == y2 && y3 == y4 && y1 == y3) {
	// 	if()
	// }
}



map<int, int> mapper;

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		ver.pb(iiii(ii(x1,y1), iii(ii(x1,y2), 0)));
		mapper[x1] = x2;
		mapper[x2] = x1;
		ver.pb(iiii(ii(x2,y1), iii(ii(x2,y2), 1)));
	}
	sort(ver.begin(), ver.end(), cmp);
	set<iii> s;
	set<iii>::iterator it;
	for(i=0;i<ver.size();i++){
		iiii an = ver[i];
		int y1 = an.first.second, y2 = an.second.first.second, x = an.first.first;
		int isEnd = an.second.second;
		printf("x: %d y1: %d y2: %d isEnd: %d\n",x, y1,y2,isEnd);
		//cari apakah ada yang intersect
		if(isEnd){
			s.erase(iii(ii(y1,y2), mapper[x]));
		}
		it = s.lower_bound(iii(ii(y1,y2), x));
		if(it != s.end()){
			printf("halo\n");
			iii a = *it;
			iii b = iii(ii(-1,-1),-1), c = iii(ii(-1,-1),-1);
			if(it != s.begin()){
				it--;
				b = *it;
			}
			// printf("ga end\n");
			printf("a: %d %d b: %d %d\n",a.first.first, a.first.second, b.first.first, b.first.second);
			if(isSmaller(ii(y1,y2), ii(a.first.first, a.first.second)) && isEnd){
				int xA = a.second;
				int pasxA = mapper[xA];

				//x pasti lebih besar daripada xA...pertanyaannya apakah pasangan xA lebih kecil daripada x
				if(pasxA > x){
					printf("sinikah\n");
					printf("1\n"); return 0;
				}
			}

			if(isSmaller(ii(a.first.first, a.first.second), ii(y1,y2)) && !isEnd){// lagi di awal
				printf("sinikah2\n");
				printf("1\n"); return 0;
			}

			if(isSmaller(ii(y1,y2), ii(b.first.first, b.first.second)) && isEnd){
				int xA = b.second;
				int pasxA = mapper[xA];

				//x pasti lebih besar daripada xA...pertanyaannya apakah pasangan xA lebih kecil daripada x
				if(pasxA > x){
					printf("sinikah3\n");
					printf("1\n"); return 0;
				}
			}

			if(isSmaller(ii(b.first.first, b.first.second), ii(y1,y2)) && !isEnd){// lagi di awal
				printf("sinikah4\n");
				printf("1\n"); return 0;
			}

			if(isIntersect(ii(y1,y2), ii(a.first.first, a.first.second))){printf("1\n"); return 0;}
			if(isIntersect(ii(y1,y2), ii(b.first.first, b.first.second))){printf("1\n"); return 0;}
			// if(isIntersect(ii(y1,y2), c)){printf("1\n"); return 0;}
		}else{
			printf("masuk sini\n");
			iii a = iii(ii(-1,-1),-1);
			if(it != s.begin()){
				it--;
				a = *it;
			}

			printf("a: %d %d\n",a.first.first, a.first.second);
			if(isIntersect(ii(y1,y2), ii(a.first.first, a.first.second))){printf("1\n"); return 0;}
		}
		//kalo ga ada insert / delete
		if(isEnd){

		}else{
			s.insert(iii(ii(y1,y2), x));

		}
		
	}
	printf("0\n");
	return 0;
};