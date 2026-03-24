class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, right = nums.size()-1;
        for(int i = right; i >0; i--){
            if(nums[i] > nums[i-1]){
                pivot=i-1; 
                break;
            } 
        }

        if (pivot >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[pivot]) {
                j--;
            }
            swap(pivot, j, nums);

        }

        int left = pivot + 1;
        while(left < right){
            swap(left, right, nums);
            left++; right--;
        }
        
    }
    void swap(int left, int right, vector<int>& nums){
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }
}; 