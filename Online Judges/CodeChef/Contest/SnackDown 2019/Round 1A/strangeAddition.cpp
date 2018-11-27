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

vi list1, list2;
void intToBinary(int bil1, int bil2){
	while(bil1 > 0){
		int belakang = bil1 % 2;
		bil1 /= 2;
		list1.pb(belakang);
	}
	while(bil2 > 0){
		int belakang = bil2 % 2;
		bil2 /= 2;
		list2.pb(belakang);
	}
	while(list1.size() < list2.size()){list1.pb(0);}
	while(list2.size() < list1.size()){list1.pb(0);}
	reverse(list1.begin(), list1.end());
	reverse(list2.begin(), list2.end());

}

int binaryToInt(vi list){
	int sum = 0;
	int i;
	for(i=0;i<list.size();i++){
		int bil = list[i];
		sum += bil*(1<<(list.size()-1-i));
	}
	return sum;
}

int main(){
	int a,b,c;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&c);
		intToBinary(a,b);
		int i;
		for(i=0;i<list1.size();i++){
			printf("%d",list1[i]);
		}
		printf("\n");
		for(i=0;i<list2.size();i++){
			printf("%d",list2[i]);
		}

		printf("\n");	
		// vi listBaru;
		// for(i=0;i<list1.size();i++){
		// 	listBaru.pb(list1[i]);
		// }

		// sort(listBaru.begin(), listBaru.end());
		// int cnt = 0;
		// do{
		// 	int angka = binaryToInt(listBaru);
		// 	// printf("angka: %d\n",angka);
		// 	if(angka + b == c){cnt++;}
		// }while(next_permutation(listBaru.begin(), listBaru.end()));

		// listBaru.clear();
		// for(i=0;i<list2.size();i++){
		// 	listBaru.pb(list2[i]);
		// }
		
		// do{
		// 	int angka = binaryToInt(listBaru);
		// 	if(angka + a == c){cnt++;}
		// }while(next_permutation(listBaru.begin(), listBaru.end()));		
		
		printf("cnt: %d\n",cnt);
		list1.clear(); list2.clear();

	}
	
	return 0;
};