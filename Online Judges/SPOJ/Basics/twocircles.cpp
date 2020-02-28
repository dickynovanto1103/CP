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

double com(int x1, int y1, int x2,int y2){
	int s1 = x1-x2;
	int s2 = y1 - y2;
	return sqrt(s1*s1 + s2*s2);
}

int main(){
	int tc,x1,y1,x2,y2,r1,r2;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		double jarak = com(x1,y1,x2,y2);
		if(r1 + jarak == r2){
			printf("E\n");
		}else if(r2 + jarak == r1){
			printf("E\n");
		}else if(r1 + jarak < r2){
			printf("I\n");
		}else if(r2 + jarak < r1){
			printf("I\n");
		}else{
			printf("O\n");
		}
	}
	return 0;
};