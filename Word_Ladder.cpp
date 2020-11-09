class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        bool flag=false;
         for(int i=0;i<wordList.size();i++)
         {
             st.insert(wordList[i]);
             if(wordList[i]==endWord)
             {
                 flag=true;
             }
         }
        if(!flag)
            return 0;
        queue<string> q;
        int ans;
        q.push(beginWord);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string s=q.front();
                q.pop();
                for(int j=0;j<s.size();j++)
                {
                    for(char k='a';k<='z';k++)
                    {
                        string curr=s;
                        if(k!=s[j])
                        {
                            curr[j]=k;
                            if(st.find(curr)!=st.end())
                            {
                                if(curr==endWord)
                                {
                                    return depth+1;
                                }
                                q.push(curr);
                                st.erase(curr);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};