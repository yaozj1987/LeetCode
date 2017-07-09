/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> m_map;
        // hash_map
        // key:target-nums[i] value:index
        for (size_t i = 0; i < nums.size(); i++) {
            if (m_map.find(nums[i]) != m_map.end()) {
                result.push_back(m_map[nums[i]]);
                result.push_back(i);
                break;
            }
            m_map[target - nums[i]] = i;
        }
        return result;
    }
};
