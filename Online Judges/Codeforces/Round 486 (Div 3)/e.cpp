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

vector<vi> AdjList;
int n;
string kata;

int minMove(string permintaan) {
	if(permintaan == "00") {
		if(AdjList[0].size() <2){
			return inf;
		}else{
			//ambil 2 terakhir
			int ukuran = AdjList[0].size();
			int idx1 = AdjList[0][ukuran-1], idx2 = AdjList[0][ukuran-2];
			int sum1 = (n-1) - idx1;
			int sum2 = (n-2) - idx2;
			return sum1+sum2;
		}
	}else if(permintaan=="25") {
		if(AdjList[2].size() == 0 || AdjList[5].size() == 0){return inf;}
		int ukuran2 = AdjList[2].size(), ukuran5 = AdjList[5].size();
		int idx2 = AdjList[2][ukuran2-1], idx5 = AdjList[5][ukuran5-1];
		if(idx2==0 && idx5==1) {
			if(kata[idx5+1] == '0'){return inf;}
		}
		if(idx2 > idx5) {
			idx2--;
		}
		if(idx2==0){
			if(kata[idx2+1] == '0'){return inf;}
		}
		if(idx5==0){
			if(kata[idx5+1] == '0'){return inf;}
		}


		int sum1 = (n-1) - idx5;
		int sum2 = (n-2) - idx2;
		return sum1 + sum2;
	}else if(permintaan == "50") {
		int ukuran5 = AdjList[5].size(), ukuran0 = AdjList[0].size();
		if(ukuran5 == 0 || ukuran0 == 0){return inf;}
		int idx0 = AdjList[0][ukuran0-1], idx5 = AdjList[5][ukuran5-1];
		if(idx5==0 && kata[idx5+1] == '0') {
			if(idx0!=1){return inf;}
			// if(kata[idx5+1] == '0'){return inf;}
		}
		if(idx5 > idx0) {
			idx5--;
		}

		if(idx0==0){
			if(kata[idx0+1] == '0'){return inf;}
		}
		swap(kata[idx0], kata[n-1]);
		if(idx5==0){
			if(kata[idx5+1] == '0'){return inf;}
		}
		swap(kata[idx0], kata[n-1]);
		int sum1 = (n-1) - idx0;
		int sum2 = (n-2) - idx5;
		return sum1 + sum2;
	}else if(permintaan=="75") {
		int ukuran5 = AdjList[5].size(), ukuran7 = AdjList[7].size();
		if(ukuran5 == 0 || ukuran7 == 0){return inf;}
		int idx5 = AdjList[5][ukuran5 - 1], idx7 = AdjList[7][ukuran7 - 1];
		if(idx7==0 && idx5==1){
			if(kata[idx5+1] == '0'){return inf;}
		}
		if(idx7 > idx5) {
			idx7--;
		}
		if(idx7==0){
			if(kata[idx7+1] == '0'){return inf;}
		}
		if(idx5==0){
			if(kata[idx5+1] == '0'){return inf;}
		}
		int sum1 = (n-1) - idx5;
		int sum2 = (n-2) - idx7;
		return sum1 + sum2;
	}
}

int main(){
	
	int i,j;
	cin>>kata;
	n = kata.length();
	int idx[10];
	AdjList.assign(10,vi());
	memset(idx,-1,sizeof idx);
	if(kata.length()==1){printf("-1\n"); return 0;}
	else if(kata.length()==2){
		if(kata == "25"){printf("0\n");}
		else if(kata == "50"){printf("0\n");}
		else if(kata=="75"){printf("0\n");}
		else if(kata=="52"){printf("1\n");}
		else if(kata=="57"){printf("1\n");}
		else{printf("-1\n");}
		// else{printf("-1\n");}
		return 0;
	}
	for(i=0;i<n;i++){
		int bil = kata[i] - '0';
		AdjList[bil].pb(i);
	}
	int ans = minMove("00");
	ans = min(ans, minMove("25"));
	ans = min(ans, minMove("50"));
	ans = min(ans, minMove("75"));
	if(ans==inf){printf("-1\n");}
	else{printf("%d\n",ans);}

	return 0;
};