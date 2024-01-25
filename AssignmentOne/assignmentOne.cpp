#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    std::vector<int> nums1 = {1, 5, 8, 2};
    int target1 = 10;
    std::vector<int> result1 = twoSum(nums1, target1);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]" << std::endl;

    std::vector<int> nums2 = {4, 3, 9, 7};
    int target2 = 12;
    std::vector<int> result2 = twoSum(nums2, target2);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]" << std::endl;
    
    return 0;
}
