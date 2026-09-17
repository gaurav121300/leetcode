class Solution {
public:

    int func(vector<int> &nums, int mid) {
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            totalSum += (nums[i] + mid - 1) / mid;
        }

        return totalSum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int start = 1;
        int end = *max_element(nums.begin(), nums.end());

        while(start <= end) {

            int mid = start + (end - start) / 2;

            int totalSum = func(nums, mid);

            if(totalSum <= threshold) {
                // mid can be an answer
                // Try to find a smaller divisor
                end = mid - 1;
            }
            else {
                // Need a bigger divisor
                start = mid + 1;
            }
        }

        return start;
    }
};