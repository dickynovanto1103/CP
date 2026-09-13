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

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head){
    	if(head == NULL || head->next == NULL) {return false;}
    	ListNode* slow = head;
    	ListNode* fast = head->next;

    	while(fast != NULL) {
    		slow = slow->next;
    		fast = fast->next;
    		if(fast == NULL) {
    			break;
    		}
    		fast = fast->next;
    		if(slow == fast) {
    			return true;
    		}
    	}

    	return false;
    }
};

void solve(){
	ListNode* two = new ListNode(2);
	ListNode* list = new ListNode(3);
	ListNode* next = two;
	list->next = next;
	next = list->next;
	next->next = new ListNode(0);
	next = next->next;
	next->next = new ListNode(4);
	next = next->next;
	next->next = two;

	Solution sol;
	printf("%d\n", sol.hasCycle(list));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};