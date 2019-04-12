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

ii convert(int s){
	return ii(s/60, s%60);
}

int main(){
	int n,m,i,j;
	scanf("%d\n",&n);
	int scoreA = 0, scoreH = 0;
	int lamaA = 0, lamaH = 0;
	int curTime = 0;
	for(i=0;i<n;i++){
		char kar;
		int point;
		int mm, ss;
		scanf("%c %d %d:%d\n",&kar,&point,&mm,&ss);
		if(scoreA != scoreH){
			int waktuSekarang = mm*60 + ss;
			if(scoreA > scoreH) {

				lamaA += (waktuSekarang - curTime);
			}else{
				lamaH += (waktuSekarang - curTime);
			}
			if(kar == 'A'){
				scoreA += point;
			}else{
				scoreH += point;
			}
			curTime = waktuSekarang;
		}else{
			if(kar == 'A'){
				scoreA += point;
			}else{
				scoreH += point;
			}
			curTime = mm*60 + ss;
		}

	}
	int mm = 32, ss = 0;
	int waktuSekarang = mm*60 + ss;
	if(scoreA > scoreH) {

		lamaA += (waktuSekarang - curTime);
	}else{
		lamaH += (waktuSekarang - curTime);
	}
	ii ans1 = convert(lamaH);
	ii ans2 = convert(lamaA);

	if(scoreA > scoreH){printf("A ");}
	else{printf("H ");}
	printf("%d:%.2d %d:%.2d\n",ans1.first, ans1.second, ans2.first, ans2.second);
	return 0;
};