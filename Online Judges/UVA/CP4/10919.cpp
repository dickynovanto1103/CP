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

void solve(){
	int numCourse, numCategories;
	while(scanf("%d %d",&numCourse,&numCategories) == 2) {
		map<string, bool> selectedCourses;
		for(int i=0;i<numCourse;i++){
			string course;
			cin>>course;
			selectedCourses[course] = true;
		}

		bool lulus = true;
		for(int i=0;i<numCategories;i++){
			int numCourseInCategory;
			int minCourseFulfilled;
			scanf("%d %d",&numCourseInCategory, &minCourseFulfilled);
			int cntCourseFulfilled = 0;
			for(int j=0;j<numCourseInCategory;j++){
				string course;
				cin>>course;
				if(selectedCourses[course]) {
					cntCourseFulfilled++;
				}
			}

			if(cntCourseFulfilled < minCourseFulfilled) {
				lulus = false;
			}
		}

		if(lulus) {
			puts("yes");
		}else{
			puts("no");
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};