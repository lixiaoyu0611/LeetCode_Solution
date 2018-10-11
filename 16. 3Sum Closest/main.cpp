class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        
        sort(nums.begin(), nums.end());
        
        int closet = nums[0] + nums[1] + nums[2];
        
        int dif = abs (closet - target);
        
        for (int i = 0; i < nums.size(); i++) {
            
            int temp = target - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            
            while (front < back) {
                
                int sum = nums[front] + nums[back];
                
                if (abs(sum - temp) < dif){
                    closet = sum + nums[i];
                    dif = abs(sum - temp);
                }
                
                if(closet == target)
                    return target;
                
                if ((sum - temp) > 0)
                    back--;
                else 
                    front++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        return closet;
    }
};