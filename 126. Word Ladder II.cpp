class Solution {
    vector<vector<string>>all;
    vector<vector<int> >last;
    vector<string>s;
    vector<string>dict;
    vector<int>dist;
    void dfs(int start,int end){
        if(start == end){
            all.push_back(s);
            return;
        }
        for(int i=0;i<last[end].size();++i){
            s[dist[end]] = dict[end];
            dfs(start, last[end][i]);
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()) return all;
        dict = wordList;
        bool find = false;
        for(int i=0; i<wordList.size(); ++i)
            if(wordList[i] == beginWord)
                find = true;
        if(!find) dict.push_back(beginWord);
        int n = dict.size();
        int l = beginWord.size();
        vector<vector<bool>> ok(n, vector<bool>(n));
        dist.resize(n);
        vector<bool>visited(n);
        
        int start=-1, end=-1;
        for(int i=0; i<n; ++i) {
            ok[i][i] = visited[i] = 0;
            dist[i] = 1e9;
            if(dict[i] == beginWord) start = i;
            if(dict[i] == endWord) end = i;
            for(int j=i+1; j<n; ++j) {
                int cnt = 0;
                for(int k=0; k<l; ++k)
                    if(dict[i][k] != dict[j][k])
                        ++cnt;
                ok[i][j] = ok[j][i] = (cnt==1);
            }
        }
        if(end == -1)return all;
        dist[start]=0;
        vector<int>q;
        q.push_back(start);
        visited[start] = 1;
        last.resize(n);
       
        for(int h=0;h<q.size();++h){
            int now = q[h];
            if(now == end)break;
            for(int i=0;i<n;++i){
                if(ok[now][i]) {
                    if(dist[now] + 1 <= dist[i]) {
                        dist[i] = dist[now] + 1;
                        last[i].push_back(now);
                        if(!visited[i]) {
                            visited[i] = 1;
                            q.push_back(i);
                        }
                    }
                }
            }
        }
        
        if(dist[end] == 1e9)return all;
        s.resize(dist[end] + 1);
        s[dist[end]]=endWord;
        s[0]=beginWord;
        dfs(start, end);
        return all;
    }
};
