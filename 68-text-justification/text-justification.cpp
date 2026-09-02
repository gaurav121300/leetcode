class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j,int eachGaddhaSpace,int extraSpaceGaddha,vector<string>& words){
        string line;

        for(int k = i; k < j; k++){
            line += words[k];

            if(k == j - 1) continue;

            for(int z = 1; z <= eachGaddhaSpace; z++){
                line += " ";
            }

            if(extraSpaceGaddha > 0){
                line += " ";
                extraSpaceGaddha--;
            }
        }
        while(line.length() < MAX_WIDTH){
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int n = words.size();

        MAX_WIDTH = maxWidth;
        int i = 0;

        while(i < n){
            int letterCount = words[i].length();
            int j = i + 1;
            int gaddhe = 0;

            while(j < n && words[j].length() + 1 + gaddhe + letterCount <= maxWidth){
                 letterCount += words[j].length();
                gaddhe += 1;
                j++;
            }

            int remainingGaddhe = maxWidth - letterCount;

            int eachGaddhaSpace = gaddhe == 0 ? 0 : remainingGaddhe / gaddhe;

            int extraSpaceGaddha = gaddhe == 0 ? 0 : remainingGaddhe % gaddhe;

            if(j == n){
                eachGaddhaSpace = 1;
                extraSpaceGaddha = 0;
            }

            result.push_back(findLine(i,j,eachGaddhaSpace,extraSpaceGaddha,words));

            i = j;


        }
        return result;
    }
};