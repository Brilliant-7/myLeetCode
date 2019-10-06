class Solution {
public:
    // 最小堆
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> minHeap;

		for (auto it : nums)
		{
			if (minHeap.size() < k)
			{
				minHeap.push_back(it);
				push_heap(minHeap.begin(), minHeap.end(), greater<>());
			}
			else if (it > minHeap.front())
			{
				pop_heap(minHeap.begin(), minHeap.end(), greater<>());
				minHeap.pop_back();
				minHeap.push_back(it);
				push_heap(minHeap.begin(), minHeap.end(), greater<>());
			}
		}

		return minHeap.front();
	}
};