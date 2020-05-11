class Solution {
    bool helper(vector<string>& results, 
                const string& s, 
                unordered_set<string>& dict, 
                int index, 
                int maxKeyLen, 
                string& partialRes, 
                unordered_map<int, bool>& memo) {
        
        const int N = s.size();
        if (index >= N) {
            partialRes.pop_back();
            results.push_back(partialRes);
            return true;
        }
        
        if (memo.count(index)) {
            return false;
        }
        
        bool canBreak = false;
        int minLen = min(N, index + maxKeyLen) + 1;
        for (int i = index + 1; i < minLen; ++i) {
            string remainingStr = s.substr(index, i - index);
            
            if (dict.count(remainingStr) == 1) {
                size_t oldSize = partialRes.size();
                partialRes += remainingStr + " ";
                
                canBreak |= helper(results, s, dict, i, maxKeyLen, partialRes, memo);
                
                // backtrack
                partialRes.resize(oldSize);
            }
        }
        
        if (!canBreak) {
            memo[index] = false;
        }
        
        return canBreak;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& words) {
        if (s.empty()) return {};
        if (words.empty()) return {};
        
        size_t maxKeyLen = 0;
        for (const string& s : words) {
            maxKeyLen = max(maxKeyLen, s.size());
        }
        
        vector<string> res;
        unordered_set<string> dict(begin(words), end(words));
        string partialRes;
		// optimization: partialRes.reserve(4 * maxKeyLen);
        unordered_map<int, bool> memo;
        helper(res, s, dict, 0, maxKeyLen, partialRes, memo);
        return res;
    }
};