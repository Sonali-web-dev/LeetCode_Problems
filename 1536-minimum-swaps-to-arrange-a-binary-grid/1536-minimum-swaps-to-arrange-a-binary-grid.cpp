class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rightmost(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    rightmost[i] = j;
                    break;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i;

            while (j < n && rightmost[j] > i) {
                j++;
            }

            if (j == n) {
                return -1;
            }

            ans += j - i;

            int temp = rightmost[j];

            for (int k = j; k > i; k--) {
                rightmost[k] = rightmost[k - 1];
            }

            rightmost[i] = temp;
        }

        return ans;
    }
};