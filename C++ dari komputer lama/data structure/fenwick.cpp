#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef vector<int> vi;
#define LSOne(X) (X & (-X))

class fenwick{
	public:
		fenwick(){}
		fenwick(int n){ft.assign(n+1,0);}//biar bs 1 sampe n
		int rsq(int a){
			int sum = 0;
			for(;a;a-=LSOne(a)) sum+=ft[a];
			return sum;
		}
		int rsq(int a,int b){
			return rsq(b)-(a==1 ? 0 : rsq(a-1));
		}
		void adjust(int k,int v){//memasukkan bilangan k ke dalam array sebanyak v
			for(;k<(int)ft.size();k+=LSOne(k)) ft[k]+=v;
		}
	private:
		vi ft;
};

int main(){
	int n,bil;
	fenwick ft(10);
	  ft.adjust(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
	  ft.adjust(4, 1);        // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
	  ft.adjust(5, 2);        // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
	  ft.adjust(6, 3);        // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
	  ft.adjust(7, 2);        // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
	  ft.adjust(8, 1);        // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
	  ft.adjust(9, 1);        // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,10 => +1
	  printf("%d\n", ft.rsq(1, 1));  // 0 => ft[1] = 0
	  printf("%d\n", ft.rsq(1, 2));  // 1 => ft[2] = 1
	  printf("%d\n", ft.rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
	  printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
	  printf("%d\n", ft.rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1

	  ft.adjust(5, 2); // update demo
	  printf("%d\n", ft.rsq(1, 10)); // now 13
	  printf("%d\n", ft.rsq(5, 5)); // now 4
}