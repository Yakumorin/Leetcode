class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty()) return s;
        int l=0, r=s.size()-1;
        unordered_map<char, bool> vowel;
        vowel['a'] = vowel['i'] = vowel['u'] = vowel['e'] = vowel['o'] = 1;
        vowel['A'] = vowel['I'] = vowel['U'] = vowel['E'] = vowel['O'] = 1;
        while(l<r) {
            while(l<r && !vowel[s[l]]) ++l;
            while(l<r && !vowel[s[r]]) --r;
            if(l<r) swap(s[l], s[r]);
            ++l; --r;
        }
        return s;
    }
};
