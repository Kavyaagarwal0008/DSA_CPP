#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()){
            return 0;
        }
        queue<pair<string , int>>q;
        q.push({beginWord,1});
        while(!q.empty()){

            string word=q.front().first;
            int level=q.front().second;
            q.pop();

            if(word==endWord){
                return level;

            }
            for(int i =0 ;i<word.length();i++){

                char original = word[i];
                for(char ch='a'; ch<='z' ; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word); //visited
                    }
                }
                word[i]=original;
            }
            
        }
        return 0;
    }
};
int main(){

    string beginWord="hit";
    string endWord="cog";
    vector<string> wordlist={"hot" , "dot", "dog", "lot" , "log", "cog"};
    Solution s;
    int ans=s.ladderLength(beginWord,endWord,wordlist);
    cout<<ans<<endl;
    return 0;

}