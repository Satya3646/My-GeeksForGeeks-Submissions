struct trieNode {
    trieNode* links[26] = {nullptr};
    bool isEnd = false;
    
    ~trieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            delete links[i];
            links[i] = nullptr;
        }
    }
};

class trie {
    trieNode* root = new trieNode();
public:
    void insert(string &s)
    {
        trieNode* node = root;
        for(char c : s)
        {
            if(node->links[c - 'a'] == nullptr)
                node->links[c - 'a'] = new trieNode();
            node = node->links[c - 'a'];
        }
        
        node->isEnd = true;
    }
    
    int wordQuery(string &s)
    {
        int cnt = 0;
        trieNode* node = root;
        for(char c : s)
        {
            if(node->links[c - 'a'] == nullptr)
                return false;
            if(node->isEnd)
                cnt++;
            node = node->links[c - 'a'];
        }
        
        return (cnt + node->isEnd);
    }
    
    bool prefixQuery(string &s)
    {
        trieNode* node = root;
        for(char c : s)
        {
            if(node->links[c - 'a'] == nullptr)
                return false;
            node = node->links[c - 'a'];
        }
        
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector <string> &words)
    {
        // code here
        trie t;
        for(string &s : words)
            t.insert(s);
        
        string ans = "";
        for(string &s : words)
        {
            int cnt = t.wordQuery(s);
            if(cnt == s.size())
            {
                if(ans.empty())
                    ans = s;
                else if(ans.size() < s.size())
                    ans = s;
                else if(ans.size() == s.size())
                    ans = min(ans, s);
            }
        }
        
        return ans;
    }
};
