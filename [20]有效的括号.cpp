#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			// 将左括号入栈
			if ((*iter == '(') || (*iter == '{') || (*iter == '[')) {
				st.push(*iter);
			}
			else {
				// 若没有左括号则不进行匹配
				if (st.empty())
					return false;
				// 将右括号与入栈的左括号进行匹配
				if ((st.top() == '(') && (*iter == ')')) {
					st.pop();
				}
				else if ((st.top() == '{') && (*iter == '}')) {
					st.pop();
				}
				else if ((st.top() == '[') && (*iter == ']')) {
					st.pop();
				}
				else
					return false;
			}
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};
// answer is above！！！



int main() {
	Solution t;
	string input;

	while (cin >> input) {
		cout << t.isValid(input) << endl;
	}

	return 0;
}