#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Sort meetings by original start time
        sort(meetings.begin(), meetings.end());

        // Min-heap of available rooms (by room number)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        // Min-heap of busy rooms: {endTime, roomNumber}
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> busy;

        vector<long long> count(n, 0); // meetings per room

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // Free rooms that have finished before current meeting starts
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            // Case 1: A room is available
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({end, room});
                count[room]++;
            }
            // Case 2: No room available → delay meeting
            else {
                auto [freeTime, room] = busy.top();
                busy.pop();

                long long newEnd = freeTime + duration;
                busy.push({newEnd, room});
                count[room]++;
            }
        }

        // Find room with maximum meetings (tie → smallest index)
        long long maxMeetings = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                ans = i;
            }
        }

        return ans;
    }
};
