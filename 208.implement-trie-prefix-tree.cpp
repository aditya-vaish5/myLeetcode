/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode()
    {
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    char c;
    vector<TrieNode *> e;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *curr = root;
        int i = 0;
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            char c = word[i];
            if (curr->next[c - 'a'] == NULL)
            {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            char c =word[i];
            if (curr->next[c - 'a'] == NULL)
            {
                return false;
            }
            curr = curr->next[c-'a'];
        }
        return curr->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            char c =prefix[i];
            if (curr->next[c - 'a'] == NULL)
            {
                return false;
            }
            curr = curr->next[c-'a'];
            ;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
