/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int found=-5;
        int l=0,h=nums.size()-1,mid=0;
        int pivot=-1;
        while(l<h){
            mid = (l+h)/2;
            if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
                pivot=mid;
                break;
            }
            if(mid-1>=0 &&nums[mid-1]>nums[mid]){
                pivot=mid-1;
                break;
            }
            if(nums[mid]>nums[l]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        int left=0,right=pivot;
        cout << pivot;
        if(pivot!=-1){
            while(left<right){

                mid=(left+right)/2;
                cout<<mid;
                if(nums[mid]==target){
                    found = mid;
                    return found;
                }
                if(nums[mid]<target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
                    
            if(left==right){
                if(nums[left]==target){
                    found =left;
                    return found;
                }
            }
        }
        

        left=pivot+1;
        right=nums.size()-1;
        
        while(left<right){
            mid=(left+right)/2;
            cout << '\n' << mid;
            if(nums[mid]==target){
                found = mid;
                return found;
            }
            if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        if(left==right){
            if(nums[left]==target){
                found =left;
                return found;
            }
        }
        return -1;
        
    }
};
// @lc code=end

