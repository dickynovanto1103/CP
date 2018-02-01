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
typedef pair<char,char> ii;
typedef pair<ii,char> iii;
typedef vector<ii> vii;

int main(){
	set<ii> s;
	set<ii>::iterator it;
	vector<iii> vec;
	char a[256];
	int i,j,k;
	for(i=97;i<97+25;i++){
		char kar = i;
		a[i] = kar;
		printf("kar: %c\n",kar);
	}

	for(i=97;i<97+25;i++){
		for(j=97;j<97+25;j++){
			for(k=97;k<97+25;k++){
				if(i!=j && i!=k && k!=j){
					int bil1 = i, bil2 = j, bil3 = k;
					if(bil1>bil2){swap(bil1,bil2);}
					if(bil1>bil3){swap(bil1,bil3);}
					if(bil2>bil3){swap(bil2,bil3);}
					// if(i>j){swap(i,j);}
					// if(j>k){swap(j,k);}
					// if(i>k){swap(i,k);}
					if(!s.count(ii(bil1,bil2)) && !s.count(ii(bil2,bil3)) && !s.count(ii(bil1,bil2))){
						s.insert(ii(bil1,bil2));
						s.insert(ii(bil2,bil3));
						s.insert(ii(bil1,bil3));
						vec.pb(mp(ii(bil1,bil2),bil3));
					}	
				}
				
				
			}
		}
	}

	// printf("data yang count 1\n");
	// for(it=s.begin();it!=s.end();it++){
	// 	ii data = *it;
	// 	printf("%c %c\n",data.first,data.second);
	// }
	// printf("yang belum\n");
	// 
	// for(i=97;i<97+25;i++){
	// 	for(j=i+1;j<97+25;j++){
	// 		if(!s.count(ii(i,j))){
	// 			printf("i: %c j: %c\n",i,j);
	// 			counter++;
	// 		}
	// 	}
	// }
	int counter = 0;
	printf("counter: %d\n",counter);
	printf("size: %d\n",vec.size());
	for(i=0;i<vec.size();i++){
		iii node = vec[i];
		printf("i: %d %c%c%c\n",i,node.first.first,node.first.second,node.second);
	}
	return 0;
};