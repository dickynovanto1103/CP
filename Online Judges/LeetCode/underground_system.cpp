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
typedef pair<int,string> is;
typedef pair<double, int> di;
typedef pair<string, string> ss;
typedef vector<ii> vii;

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        lastTimeCustomer[id] = is(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
    	is last = lastTimeCustomer[id];
    	assert(last != is(-1, ""));

    	ss stationPair = ss(last.second, stationName);
    	di curAvgRes = mapper[stationPair];
    	double newAvg = (curAvgRes.first * (double)curAvgRes.second + (double)(t - last.first)) / (double)(curAvgRes.second + 1);
    	mapper[ss(last.second, stationName)] = di(newAvg, curAvgRes.second + 1);

        lastTimeCustomer[id] = is(-1, "");
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mapper[ss(startStation, endStation)].first;
    }
private:
	is lastTimeCustomer[1000001];
	map<ss, di> mapper;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(){
	UndergroundSystem* u = new UndergroundSystem();
	u->checkIn(1, "a", 10);
	u->checkOut(1, "b", 11);

	printf("%lf\n", u->getAverageTime("a", "b"));

	u->checkIn(2, "a", 100);
	u->checkOut(2, "b", 102);

	printf("%lf\n", u->getAverageTime("a", "b"));
	return 0;
};