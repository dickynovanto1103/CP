#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

void AtoR(int A) {
  map<int, string> cvt;
  cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
  cvt[100]  = "C"; cvt[90]  = "XC"; cvt[50]  = "L"; cvt[40]  = "XL";
  cvt[10]   = "X"; cvt[9]   = "IX"; cvt[5]   = "V"; cvt[4]   = "IV";
  cvt[1]    = "I";
  // process from larger values to smaller values
  for (map<int, string>::reverse_iterator i = cvt.rbegin();
       i != cvt.rend(); i++)
    while (A >= i->first) {
      printf("%s", ((string)i->second).c_str());
      A -= i->first; }
  printf("\n");
}

int RtoA(string R) {
  map<char, int> RtoA;
  RtoA['I'] = 1;   RtoA['V'] = 5;   RtoA['X'] = 10;   RtoA['L'] = 50;
  RtoA['C'] = 100; RtoA['D'] = 500; RtoA['M'] = 1000;

  int value = 0;
  for (int i = 0; i<R.length(); i++)
    if (R[i+1] && RtoA[R[i]] < RtoA[R[i+1]]) {     // check next char first
      value += RtoA[R[i+1]] - RtoA[R[i]];                // by definition
      i++; }                                              // skip this char
    else value += RtoA[R[i]];
  //printf("%d\n", value);
  return value;
}

int main(){
	int tt,tc,i,j;
	string a,b;
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		cin>>a>>b;

		int bil1 = RtoA(a), bil2 = RtoA(b);

		int jumlah = bil1 + bil2;
		//printf("bil1: %d bil2: %d jumlah: %d\n",bil1,bil2,jumlah);
		AtoR(jumlah);
	}
	return 0;
};