class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();

        vector<int> neg;
        vector<int> pos;

        // Separate negative and positive numbers
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        // If there are no negative numbers
        if (neg.size() == 0) {
            for (int i = 0; i < pos.size(); i++)
                pos[i] = pos[i] * pos[i];

            return pos;
        }

        // If there are no positive numbers
        if (pos.size() == 0) {
            for (int i = 0; i < neg.size(); i++)
                neg[i] = neg[i] * neg[i];

            reverse(neg.begin(), neg.end());
            return neg;
        }

        int n = neg.size();
        int m = pos.size();

        // Square the negative numbers
        for (int i = 0; i < n; i++)
            neg[i] = neg[i] * neg[i];

        // Reverse because squared negatives are in decreasing order
        reverse(neg.begin(), neg.end());

        // Square the positive numbers
        for (int i = 0; i < m; i++)
            pos[i] = pos[i] * pos[i];

        vector<int> res(n + m);

        int i = 0;
        int j = 0;
        int id = 0;

        // Merge the two sorted arrays
        while (i < n && j < m) {
            if (neg[i] <= pos[j]) {
                res[id++] = neg[i++];
            } else {
                res[id++] = pos[j++];
            }
        }

        // Copy remaining elements
        while (i < n) {
            res[id++] = neg[i++];
        }

        while (j < m) {
            res[id++] = pos[j++];
        }

        return res;
    }
};