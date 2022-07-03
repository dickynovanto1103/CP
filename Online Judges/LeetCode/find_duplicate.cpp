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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
  		int tortoise = nums[0];
  		int hare = nums[0];
  		do{
  			tortoise = nums[tortoise];
  			hare = nums[nums[hare]];
  		}while(tortoise != hare);

  		// printf("tortoise: %d\n", tortoise);
  		tortoise = nums[0];

  		while(tortoise != hare) {
  			tortoise = nums[tortoise];
  			hare = nums[hare];
  		}
  		// printf("now tortoise; %d\n", tortoise);

  		return tortoise;
    }
};

int main(){
	int n;
	while(scanf("%d",&n) != EOF) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		Solution sol;
		cout<<sol.findDuplicate(a)<<endl;
	}
	
	return 0;
};