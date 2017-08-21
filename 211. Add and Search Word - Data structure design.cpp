class Trienode{
public:
    Trienode* next[26];
    bool isEnd;
    Trienode() {
        isEnd = 0;
        for(int i=0; i<26; ++i)
            next[i] = NULL;
    }
};
class WordDictionary {
    int tot;
    Trienode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        tot = 0;
        root = new Trienode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trienode* p = root;
        for(auto ch:word) {
            if(!p->next[ch-'a']) 
                p->next[ch-'a'] = new Trienode();
            p = p->next[ch-'a'];
        }
        p->isEnd = 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        vector<Trienode*> pos;
        pos.push_back(root);
        for(auto ch:word) {
            vector<Trienode*> now;
            for(auto h:pos) {
                if(ch == '.') {
                    for(int i=0; i<26; ++i)
                        if(h->next[i])
                            now.push_back(h->next[i]);
                } else {
                    if(h->next[ch-'a'])
                        now.push_back(h->next[ch-'a']);
                }
            }
            pos = now;
        }
        if(pos.empty()) return 0;
        bool ok = 0;
        for(auto x:pos)
            if(x->isEnd)
                ok = 1;
        return ok;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
