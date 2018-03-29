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

int mat[10][10];
int hasilParse[5], temp[5];

void printTemp() {
	int i;
	for(i=0;i<5;i++) {

	}
}

void reset() {
	for(int i=0;i<5;i++) {
		temp[i] = hasilParse[i];
	}
}

void determineLast() {
	int bil = 0;
	for(int i=0;i<4;i++) {
		bil = mat[bil][hasilParse[i]];
	}
	hasilParse[4] = bil;
}

void parse(int n) {
	int idx = 3;
	while(idx>=0) {
		int bil = n%10;
		hasilParse[idx] = bil;
		n/=10;
		idx--;
	}
	determineLast();
	reset();
}

bool check() {
	int bil = 0;
	for(int i=0;i<5;i++) {
		bil = mat[bil][temp[i]];
	}
	return bil == 0;
}

bool isSame() {
	for(int i=0;i<5;i++) {
		if(temp[i] != hasilParse[i]) {return false;}
	}
	return true;
}

bool hasilUbah1Digit() {
	int i,j;
	for(i=0;i<5;i++) {
		for(j=0;j<=9;j++) {
			temp[i] = j;

			if(isSame()){continue;}
			if(check()){
				return true;
			}
			reset();
		}
	}
	return false;
}


bool hasilTranspose() {
	for(int i=0;i<4;i++) {
		swap(temp[i], temp[i+1]);

		if(isSame()){continue;}
		if(check()){
			return true;
		}
		reset();
	}
	return false;
}

int main(){
	int i,j;

	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	int cnt = 0;
	for(i=0;i<10000;i++) {
		parse(i);
		
		 
		
		if(hasilUbah1Digit()) {
			cnt++; continue;
		}
		if(hasilTranspose()) {
			cnt++; continue;
		}
	}
	printf("%d\n",cnt);
	return 0;
};