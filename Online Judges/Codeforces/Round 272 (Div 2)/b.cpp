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

int main(){
	string kata1,kata2;
	cin>>kata1>>kata2;
	int delta = 0;
	int i,j;
	for(i=0;i<kata1.length();i++){
		if(kata1[i] == '-'){delta--;}
		else{delta++;}
	}
	int sekarang = 0;
	int banyakTandaTanya = 0;
	for(i=0;i<kata2.length();i++){
		if(kata2[i] == '-'){sekarang--;}
		else if(kata2[i] == '+'){
			sekarang++;
		}else{
			banyakTandaTanya++;
		}
	}

	int banyakBener = 0;
	int butuh = delta - sekarang;
	for(i=0;i<(1<<banyakTandaTanya);i++){
		int tambah = 0;
		for(j=0;j<banyakTandaTanya;j++){
			if((1<<j) & i){
				tambah++;
			}else{
				tambah--;
			}
		}

		if(tambah==butuh){
			banyakBener++;
		}
	}

	double ans = (double)banyakBener / (double)(1<<banyakTandaTanya);
	printf("%.10lf\n",ans);

	return 0;
};