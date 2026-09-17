class Solution {
public:
    int func(vector<int> &bloomDay, int day, int k) {
        int cnt = 0;
        int noOfBq = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                cnt++;
            }
            else {
                noOfBq += cnt / k;
                cnt = 0;
            }
        }

        // Remaining consecutive flowers
        noOfBq += cnt / k;

        return noOfBq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long total = 1LL * m * k;

        // Not enough flowers
        if(bloomDay.size() < total)
            return -1;

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        while(start <= end) {

            int mid = start + (end - start) / 2;

            int bouquetNo = func(bloomDay, mid, k);

            if(bouquetNo >= m) {
                // Possible answer, try fewer days
                end = mid - 1;
            }
            else {
                // Not enough bouquets, need more days
                start = mid + 1;
            }
        }

        return start;
    }
};