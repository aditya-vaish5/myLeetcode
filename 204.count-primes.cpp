/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    //Sieve of erasthoneses
    int countPrimes(int n) {
        int arr[n+1];
        memset (arr,0,sizeof(arr));
        if(n<2){
            return 0;
        }
        arr[2]=0;
        for(int i=2;i<n;i++){
            if(i == 1){
                continue;
            }
            for(int j = i*2;j<n;j += i){
                arr[j] = 1;
            }
        }
        int count =0;
        for(int i =2;i<n;i++){
            if(arr[i] == 0){
                cout << i << " ";
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

