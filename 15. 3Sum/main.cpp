class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            
            while (front < back) {
                
                int sum = nums[front] + nums[back];
                
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else{
                    vector<int> res(3, 0);
                    res[0] = nums[i];
                    res[1] = nums[front];
                    res[2] = nums[back];
                    vec.push_back(res);
                    
                   while (front < back && nums[front] == res[1]) front++;
                    
                   while (front < back && nums[back] == res[2]) back--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        return vec;
    }
};