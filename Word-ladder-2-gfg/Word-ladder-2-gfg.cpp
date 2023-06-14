//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        vector<string> usedOnLevel;
        q.push({beginWord});
        usedOnLevel.push_back(beginWord);
        int level=0;
        
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            
            if(vec.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
        
        string word=vec.back();
        
        if(word == endWord){
            if(ans.size()==0){
                ans.push_back(vec);
            }else if (ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }
        
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a' ; ch <= 'z';ch++){
                word[i]=ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
            }
        }
        return ans;
    }
};