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

int convertToNum(string s) {
	int ans = 0;
	for(int i=0;i<s.size();i++){
		ans *= 10;
		ans += s[i] - '0';
	}

	return ans;
}

int convertTimeToMinutes(string s) {
	string hour = s.substr(0, 2);
	string minutes = s.substr(3, 2);

	return convertToNum(hour) * 60 + convertToNum(minutes);
}

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {  		
  		ii pas1 = ii(convertTimeToMinutes(event1[0]), convertTimeToMinutes(event1[1]));
  		ii pas2 = ii(convertTimeToMinutes(event2[0]), convertTimeToMinutes(event2[1]));

  		int minY = min(pas1.second, pas2.second);
  		int maxX = max(pas1.first, pas2.first);

  		return maxX <= minY;
    }
};

int main(){
	
	
	return 0;
};