
class Solution {
public:
    bool canPlace(vector<int>& position, int m, int minDist) {
        int count = 1;                 // First ball is placed
        int last = position[0];        // Position of last placed ball

        for (int i = 1; i < position.size(); i++) {

            // If distance is at least minDist,
            // place another ball here
            if (position[i] - last >= minDist) {
                count++;
                last = position[i];
            }

            
            if (count >= m) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canPlace(position, m, mid)) {
                // mid is possible
                // Try to get a larger minimum distance
                ans = mid;
                low = mid + 1;
            }
            else {
                // mid is not possible
                // Need a smaller distance
                high = mid - 1;
            }
        }

        return ans;
    }
};