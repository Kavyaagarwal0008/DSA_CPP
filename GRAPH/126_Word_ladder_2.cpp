#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string> usedOnLevel;

        usedOnLevel.push_back(beginWord);
        int level=0;

        vector<vector<string>>ans;
        while(!q.empty()){

            vector<string> vec=q.front();
            q.pop();

            //erase all words used at prev level 
            if(vec.size()>level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }

            string word= vec.back();

            if(word == endWord){
                if(ans.size()==0){
                    ans.push_back(vec);

                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);

                }
            }
            
            for(int i =0 ;i<word.size();i++){

                char original = word[i];
                for(char ch='a'; ch<='z' ; ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);

                        //visited on the level
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
int main(){

    string beginWord="hit";
    string endWord="cog";
    vector<string> wordlist={"hot" , "dot", "dog", "lot" , "log", "cog"};
    Solution s;
    vector<vector<string>> ans=s.ladderLength(beginWord,endWord,wordlist);
    for( auto &seq : ans){
        for(auto &w: seq){
            cout<<w<<" ";

        }
        cout<<endl;
    }
    return 0;

}                       