#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	string kata1,kata2;
	int i,j;
	while(cin>>kata1){
		cin>>kata2;
		//cout<<"kata1: "<<kata1<<" kata2: "<<kata2<<endl;
		int n1 = kata1.length(),n2 = kata2.length();
		int last = -1;
		bool found = true;
		for(i=0;i<n1;i++){
			char kar = kata1[i];
			//cari kar di kata2
			for(j=last+1;j<n2;j++){
				if(kar==kata2[j]){last = j; break;}
			}
			if (j==n2){
				found = false; printf("No\n"); break;
			}
		}
		if(found){printf("Yes\n");}
	}
	return 0;
}