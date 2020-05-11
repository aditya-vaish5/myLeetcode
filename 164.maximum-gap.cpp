/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        int ans = abs(nums[1] - nums[0]);
        int low = INT_MAX, high = INT_MIN;
        for (int i : nums)
        {
            low = min(i, low);
            high = max(i, high);
        }
        if(high == low){
            return 0;
        }
        int bucketSize = max(1, (high - low) / (n - 1));
        int numBucket = (high - low) / bucketSize + 1;
        int arr[numBucket][2];
        int bucket;
        for (int i = 0; i < numBucket; i++)
        {
            arr[i][0] = INT_MAX;
            arr[i][1] = INT_MIN;
        }
        cout << "YES1 ";
        cout << "low = " << low << " high = "<<high << endl;
        bool found[numBucket];
        memset(found, false, sizeof(found));
        // memset(arr,-1,sizeof(arr));
        cout << "\n BUCKET SIZE = " << bucketSize << endl;
        cout << "number of buckets = " << numBucket << endl;
        for (int i = 0; i < n; i++)
        {
            bucket = (nums[i] - low) / (bucketSize);
            arr[bucket][0] = min(nums[i], arr[bucket][0]);
            arr[bucket][1] = max(nums[i], arr[bucket][1]);
            found[bucket] = true;
        }
        cout << "Yes2 " << endl;
        for (auto b : arr)
        {
            cout << b[0] << ' ' << b[1] << endl;
        }
        int prev_found = -1;
        int prev_max = 1e9;
        ans = INT_MIN;
        for (int i = 0; i < numBucket; i++)
        {
            if (found[i])
            {
                ans = max(ans, arr[i][0] - prev_max);
                prev_max = arr[i][1];
                prev_found = i;
            }
        }
        return ans;
    }
};
// @lc code=end
