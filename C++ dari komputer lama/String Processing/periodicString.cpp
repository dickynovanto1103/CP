#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#define MAX_N 100010

string text, pattern;
int b[MAX_N], n,m;
bool found;

void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && pattern[i] != pattern[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

/*int kmpSearch() {
	int i = 0, j = 0;
	int cnt=0;
	while(i<n) {
		while(j >= 0 && text[i]!=pattern[j]) j = b[j];
		i++; j++;
		if(j == m) {
			cnt++;
			cout<<"pattern: "<<pattern<<endl;
			printf("pattern found in index %d\n",i-j);
			j = b[j];
		}
	}
	return cnt;
}*/

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
  int i = 0, j = 0; // starting values
  int cnt=0;
  while (i < n) { // search through string T
    while (j >= 0 && text[i] != pattern[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
      cnt++;
      //cout<<"pattern: "<<pattern<<endl;

      //printf("P is found at index %d in T\n", i - j);
      
      i = i-j+m;
      j = 0; // prepare j for the next possible match
} } 
	return cnt;
}

int main() {
	int tc, i, test=0;
	scanf("%d",&tc);
	while(tc--) {
		if(test>0) {printf("\n");}
		found = false;
		cin>>text;
		n = text.length();
		for(i=0;i<n;i++) {
			m = i+1;
			if(n%m==0) {
				pattern = text.substr(0,m);	
				kmpPreprocess();
				int bil = kmpSearch();
				if(bil == n/m){found = true;}
				if(found) {
					cout<<m<<endl;
					break;
				}
			}
			
			
		}
		test=1;
	}
	return 0;
}