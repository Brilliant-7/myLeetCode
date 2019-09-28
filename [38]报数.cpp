#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	// 非递归
	string countAndSay1(int n) {
		string result("1");

		if (n <= 1) {
			return result;
		}

		string pre = result;

		while (n - 1) {
			int cnt = 0;
			char say = pre[0];
			char temp;

			result.clear();
			for (size_t i = 0; i < pre.size(); i++)
			{
				temp = pre[i];
				if (temp == say) {
					cnt++;
				}
				else {
					result += to_string(cnt) + say;
					say = pre[i];
					cnt = 1;
				}
			}
			result += to_string(cnt) + say;
			pre = result;
			n--;
		}
		cout << result << endl;

		return result;
	}

	// 递归
	string countAndSay2(int n) {
		if (n == 1) {
			return "1";
		}

		string result;
		string pre = countAndSay2(n - 1);

		int cnt = 0;
		char say = pre[0];
		char temp;

		for (size_t i = 0; i < pre.size(); i++)
		{
			temp = pre[i];
			if (temp == say) {
				cnt++;
			}
			else {
				result += to_string(cnt) + say;
				say = pre[i];
				cnt = 1;
			}
		}
		result += to_string(cnt) + say;

		return result;
	}
};

int main()
{
	Solution t;
	t.countAndSay1(5);

	t.countAndSay2(5);


	system("pause");
	return 0;
}