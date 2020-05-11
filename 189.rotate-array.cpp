/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int temp;
        int n = nums.size();
        if(n  <2) return;
        k = k%n;
        for (int j = 0; j <(n - k)/2; j++)
        {
            temp = nums[j];
            nums[j] = nums[n-k-j-1];
            nums[n-k-j-1] =temp;
        }
        for(int i : nums){
            cout << i << ' ';
        }
        cout << endl;
        for(int i=0;i<k/2;i++){
            temp = nums[n-k+i];
            nums[n-k+i] = nums[n-i-1];
            nums[n-i-1] = temp;
        }
        for(int i : nums){
            cout << i << ' ';
        }
        cout << endl;
        for(int i =0;i<n/2;i++){
            temp = nums[i];
            nums[i] = nums[n-i-1];
            nums[n-i-1] = temp;
        }
        for(int i : nums){
            cout << i << ' ';
        }
        cout << endl;
    }
};
// @lc code=end
