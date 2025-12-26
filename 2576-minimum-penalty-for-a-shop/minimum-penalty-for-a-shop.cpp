class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        int bestHr = 0;
        int hr = 0;
        for(char c : customers){
            if(c == 'Y') penalty++;
        }

        int min_penalty = penalty;

        for(char c : customers){
            if(c == 'Y') penalty -= 1;
            else penalty += 1;

            if(penalty < min_penalty){
                bestHr = hr + 1;
                min_penalty = penalty;
            }
            hr++;
        }
        return bestHr;
    }
};