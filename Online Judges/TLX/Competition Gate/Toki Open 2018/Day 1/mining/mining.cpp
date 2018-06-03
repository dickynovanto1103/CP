#include "mining.h"
#include <bits/stdc++.h>

using namespace std;
void findGold() {
	//random x,y;
	//random x dulu..nanti cek 3 indeks 1,2,3
	srand(time(NULL));
	int x,y;
	bool isVisitedX[1001], isVisitedY[1001];
	memset(isVisitedY, false, sizeof isVisitedY);
	memset(isVisitedX, false, sizeof isVisitedX);
	while(true) {
		x = rand()%1000 + 1;
		if(isVisitedX[x]){continue;}
		isVisitedX[x] = true;
		bool isValid = true;
		for(int i=1;i<=2;i++){
			
			if(!isIntegerDistance(x,i)) {
				isValid = false;
				break;
			}
		}
		if(isValid){
			break;
		}
	}

	//cari y

	while(true) {
		y = rand()%1000 + 1;
		if(isVisitedY[y]){continue;}
		isVisitedY[y] = true;
		bool isValid = true;
		for(int i=1;i<=2;i++) {
			if(!isIntegerDistance(i,y)) {
				isValid = false;
				break;
			}
		}
		if(isValid) {
			break;
		}
	}

	

  answer(x, y);
}
