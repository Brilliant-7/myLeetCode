#include <iostream>
using namespace std;

class Solution {
public:
	// 位运算
	bool isPowerOfTwo(int n) {
		if (n <= 0) {
			return false;
		}
		if ((n & n - 1) == 0)
			return true;
		else
			return false;
	}
};
// answer is above！！！

int main() {
	Solution t;
	cout << t.isPowerOfTwo(1) << endl;

	system("pause");

	return 0;
}