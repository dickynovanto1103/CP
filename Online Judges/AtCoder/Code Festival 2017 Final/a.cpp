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
	string kata;
	int i,j;
	cin>>kata;
	int pjg = kata.length();
	int cntK = 0, cntI = 0, cntH = 0, cntB = 0, cntR = 0, cntA=0, lain = 0;;
	int idxK = 0, idxI = 0, idxH = 0, idxB = 0, idxR = 0;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar=='K'){cntK++; idxK = i;}
		else if(kar=='I'){cntI++; idxI = i;}
		else if(kar=='H'){cntH++; idxH = i;}
		else if(kar=='B'){cntB++; idxB = i;}
		else if(kar=='R'){cntR++; idxR = i;}
		else if(kar=='A'){cntA++;}
		else{lain++;}
	}
	if(lain>0){printf("NO\n"); return 0;}
	if(cntK!=1 || cntI!=1 || cntB!=1 || cntH!=1 || cntR!=1){printf("NO\n"); return 0;}
	
	if(cntA>4){printf("NO\n"); return 0;}
	//cek sebelah kiri K

	cntA = 0;
	for(i=idxK-1;i>=0;i--){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>1){printf("NO\n"); return 0;}
	//cek sebelah kanan R
	cntA = 0;
	for(i=idxR+1;i<pjg;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>1){printf("NO\n"); return 0;}
	//cek banyak Aantara tiap indeks
	//K I
	if(idxK > idxI){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxK;i<=idxI;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>0){printf("NO\n"); return 0;}
	//K H
	if(idxK > idxH){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxK;i<=idxH;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>0){printf("NO\n"); return 0;}
	//K B
	if(idxK > idxB){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxK;i<=idxB;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>1){printf("NO\n"); return 0;}
	//K R
	if(idxK > idxR){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxK;i<=idxR;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>2){printf("NO\n"); return 0;}

	//I H
	if(idxI > idxH){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxI;i<=idxH;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>0){printf("NO\n"); return 0;}
	//I B
	if(idxI > idxB){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxI;i<=idxB;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>1){printf("NO\n"); return 0;}

	//I R
	if(idxI > idxR){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxI;i<=idxR;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>2){printf("NO\n"); return 0;}
	//H B
	if(idxH > idxB){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxH;i<=idxB;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>1){printf("NO\n"); return 0;}
	//H R
	if(idxH > idxR){printf("NO\n"); return 0;}
	cntA = 0;
	for(i=idxH;i<=idxR;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>2){printf("NO\n"); return 0;}
	//B R
	cntA = 0;
	if(idxB > idxR){printf("NO\n"); return 0;}
	for(i=idxB;i<=idxR;i++){
		if(kata[i]=='A'){cntA++;}
	}
	if(cntA>1){printf("NO\n"); return 0;}
	printf("YES\n");
	return 0;
};