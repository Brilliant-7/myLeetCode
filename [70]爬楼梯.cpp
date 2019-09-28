class Solution {
public:
	// f(n) = f(n-1) + f(n-2)
	int climbStairs(int number) {
		if (number == 1) {
			return 1;
		}
		else if (number == 2) {
			return 2;
		}

		long long int fibResult = 0;
		long long int fibOne = 1;
		long long int fibTwo = 2;
		for (int i = 3; i <= number; i++)
		{
			fibResult = fibOne + fibTwo;
			fibOne = fibTwo;
			fibTwo = fibResult;
		}
		return fibResult;
	}
};