/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
class Trie
{
public:
    Trie *next[256];
    bool is_word;
    Trie()
    {
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};
class WordDictionary
{
public:
    /** Initialize your data structure here. */
    Trie *root;
    WordDictionary()
    {
        root = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        Trie *t = root;
        for (char c : word)
        {
            if (t->next[c] == NULL)
            {
                t->next[c] = new Trie();
            }
            t = t->next[c];
        }
        t->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool f(string &word, Trie *t, int index)
    {
        
        if (index == word.length() - 1)
        {
            // cout << "came here for " << word << endl;
            char c = word[index];
            if (c == '.')
            {
                bool ans =false;
                for(auto p : t->next){
                    if(p!=NULL)
                        ans |= p->is_word;
                }
                return ans;
            }
            else
            {
                if (t->next[c])
                {
                    return t->next[c]->is_word;
                }
                else
                {
                    return false;
                }
            }
        }
        bool ans = false;
        char c = word[index];
        if (c == '.')
        {
            for (auto p : t->next)
            {
                if (p != NULL)
                {
                    ans |= f(word, p, index + 1);
                }
            }
            return ans;
        }
        else
        {
            // cout << "running for " << word << ' ' << index << endl;
            if (t->next[c] != NULL)
            {
                return f(word, t->next[c], index + 1);
            }
            else
            {
                return false;
            }
        }
    }
    bool search(string word)
    {
        Trie *t = root;
        return f(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
