class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e18, high = -1e18;

        // Compute total area and search bounds
        for (auto &sq : squares) {
            double y = sq[1], l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        auto areaBelow = [&](double H) {
            double area = 0;
            for (auto &sq : squares) {
                double y = sq[1], l = sq[2];
                if (H <= y) continue;
                if (H >= y + l) area += l * l;
                else area += l * (H - y);
            }
            return area;
        };

        // Binary search
        for (int i = 0; i < 100; i++) { // enough for 1e-5 precision
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
