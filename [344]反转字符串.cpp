class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.empty()) {
			return;
		}
		int front = 0;
		int rear = s.size() - 1;
		while (front < rear) {
			mySwap(s[front], s[rear]);
			front++;
			rear--;
		}
	}
private:
	void mySwap(char& a1, char& a2) {
		char temp;
		temp = a1;
		a1 = a2;
		a2 = temp;
	}
};
// answer is above！！！