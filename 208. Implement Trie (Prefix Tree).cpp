class TrieNode{
public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode() {
        isEnd = 0;
        for(int i=0; i<26; ++i)
            next[i] = NULL;
    }
};
class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(auto ch:word) {
            if(!p->next[ch-'a'])
                p->next[ch-'a'] = new TrieNode();
            p = p->next[ch-'a'];
        }
        p->isEnd = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(auto ch:word) {
            if(!p->next[ch-'a'])
                return 0;
            p = p->next[ch-'a'];
        }
        return p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(auto ch:prefix) {
            if(!p->next[ch-'a'])
                return 0;
            p = p->next[ch-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
