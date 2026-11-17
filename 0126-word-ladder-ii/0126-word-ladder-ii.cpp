class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string beginWord) {

        if(word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for(string p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> dict(
            wordList.begin(), wordList.end()
        );

        if(!dict.count(endWord))
            return ans;

        queue<string> q;
        q.push(beginWord);

        dict.erase(beginWord);

        bool found = false;

        while(!q.empty() && !found) {

            int size = q.size();

            unordered_set<string> used;

            for(int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                for(int j = 0; j < word.size(); j++) {

                    char original = word[j];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        if(ch == original)
                            continue;

                        word[j] = ch;

                        if(dict.count(word)) {

                            if(word == endWord)
                                found = true;

                            parent[word].push_back(
                                q.empty() ? "" : ""
                            );

                            parent[word].pop_back();
                            parent[word].push_back(q.empty() ? "" : "");

                            // Store the previous word
                            parent[word].back() = 
                                word.substr(0, j) + original +
                                word.substr(j + 1);

                            if(used.insert(word).second)
                                q.push(word);
                        }
                    }

                    word[j] = original;
                }
            }

            for(string w : used)
                dict.erase(w);
        }

        if(found) {
            path.push_back(endWord);
            dfs(endWord, beginWord);
        }

        return ans;
    }
};