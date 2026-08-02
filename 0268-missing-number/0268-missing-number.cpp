class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1 = 0;
        int XOR2 = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            XOR1 ^= nums[i] ;
        }
        for(int i = 0 ; i<=nums.size(); i++)
            {
                 XOR2 ^=i;
            }

        return XOR1^XOR2;
            
    }
    
};