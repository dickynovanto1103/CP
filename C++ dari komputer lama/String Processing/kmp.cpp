#include <iostream>
#include <cstdio>

using namespace std;
#define MAX_N 100010

string text, pattern;
int b[MAX_N], n,m;

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while(i<m) {
		while(j >= 0 && pattern[i]!=pattern[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void kmpSearch() {
	int i = 0, j = 0;
	while(i<n) {
		while(j >= 0 && text[i]!=pattern[j]) j = b[j];
		i++; j++;
		if(j == m) {
			printf("pattern found in index %d\n",i-j);
			j = b[j];
		}
	}
}

int main() {
	int i;
	getline(cin,text);
	getline(cin,pattern);
	cout<<text<<endl;
	cout<<pattern<<endl;
	n = text.length();
	m = pattern.length();
	kmpPreprocess();
	kmpSearch();
	
	/*for(i = 0;i <= m; i++) {
		printf("b[%d]: %d\n",i,b[i]);
	}*/
}