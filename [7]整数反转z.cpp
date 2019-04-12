class Solution {
public:
	int reverse(int x) {
		int result = 0;

		while (x) {
			temp = x % 10;
			x = x / 10;
			if ((result > max_value / 10) || ((result == max_value / 10) && (temp > 7))) {
				return 0;
			}
			else if ((result < min_value / 10) || ((result == min_value / 10) && (temp < -8))) {
				return 0;
			}
			result = result * 10 + temp;
		}

		return result;
	}
private:
	int temp;
	// 32位有符号数的上下界
	int max_value = 2147483647;
	int min_value = -2147483648;
};