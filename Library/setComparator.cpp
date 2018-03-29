struct compare{
	bool operator() (const ii &a, const ii &b) const{
		if(a.second==b.second){return a.first > b.first;}
		return a.second < b.second;
	}
};

set<ii,compare> s;