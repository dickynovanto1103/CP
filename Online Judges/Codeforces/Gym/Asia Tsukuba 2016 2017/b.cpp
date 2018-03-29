#include <bits/stdc++.h>

using namespace std;


int result;
bool has_error;

class SSN {
public:
	int abcde[5] = {0, 0, 0, 0, 0};
	int abcde_test[5] = {0, 0, 0, 0, 0};

	void iterate(const vector<vector<int>> &op) {
		abcde[3] = (abcde[3] + 1) % 10;
		if (abcde[3] == 0) {
			abcde[2] = (abcde[2] + 1) % 10;
			if (abcde[2] == 0) {
				abcde[1] = (abcde[1] + 1) % 10;
				if (abcde[1] == 0) {
					abcde[0] = (abcde[0] + 1) % 10;
				}
			}
		}
		abcde[4] = op[op[op[op[0][abcde[0]]][abcde[1]]][abcde[2]]][abcde[3]];

		reset();
	}

	void reset() {
	 	abcde_test[0] = abcde[0];
	 	abcde_test[1] = abcde[1];
		abcde_test[2] = abcde[2];
	 	abcde_test[3] = abcde[3];
	 	abcde_test[4] = abcde[4];
	}

	bool check(const vector<vector<int>> &op) {
		return op[op[op[op[0][abcde_test[0]]][abcde_test[1]]][abcde_test[2]]][abcde_test[3]] == abcde_test[4];
	}

	void check_permute(const vector<vector<int>> &op) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j <= 9; j++) {
				abcde_test[i] = j;

				if (!isSame() && check(op)) {
					has_error = true;
				}
			}

			reset();
		}
	}

	void check_transpose(const vector<vector<int>> &op) {
		for (int i = 0; i < 4; i++) {
			int temp = abcde_test[i];
			abcde_test[i] = abcde_test[i + 1];
			abcde_test[i + 1] = temp;

			if (!isSame() && check(op)) {
				has_error = true;
			}

			reset();
		}
	}

	bool is_same() {
		for (int i = 0; i < 5; i++) {
			if (abcde[i] != abcde_test[i])
				return false;
		}

		return true;
	}

	bool is_end() {
		for (int i = 0; i < 4; i++) {
			if (abcde[i] != 9)
				return false;
		}
		return true;
	}
};

int main() {
	vector<vector<int>> op(10, vector<int>(10));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> op[i][j];
		}
	}

	SSN ssn;
	result = 0;
	has_error = false;


	while (true) {
		ssn.check_permute(op);
		ssn.check_transpose(op);

		if (has_error)
			result += 1;

		if (ssn.is_end())
			break;

		ssn.iterate(op);
		has_error = false;
	}

	cout << result << '\n';
}