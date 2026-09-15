#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

class Solution {
public:
	bool isOverlap(ii a, ii b) {
		return min(a.second, b.second) > max(a.first, b.first);
	}

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
  		//check horizontal first
    	int x1 = rec1[0], x2 = rec1[2], y1 = rec1[1], y2 = rec1[3];
    	int x3 = rec2[0], x4 = rec2[2], y3 = rec2[1], y4 = rec2[3];

    	return isOverlap({x1,x2}, {x3,x4}) && isOverlap({y1, y2}, {y3, y4});
    }
};

int main() {
	Solution sol;
	vi rec1, rec2;
	for(int i=0;i<4;i++){
		int num;
		scanf("%d",&num);
		rec1.push_back(num);
	}

	for(int i=0;i<4;i++){
		int num;
		scanf("%d",&num);
		rec2.push_back(num);
	}
	printf("%d\n", sol.isRectangleOverlap(rec1, rec2));
	return 0;
}