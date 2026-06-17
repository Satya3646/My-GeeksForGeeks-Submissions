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
public:
    trieNode* root = new trieNode();
    int cnt = 0;
    void insert(string &s, int l, int r)
    {
        trieNode* node = root;
        for(int i = l; i <= r; i++)
        {
            char c = s[i];
            if(node->links[c - 'a'] == nullptr)
            {
                cnt++;
                node->links[c - 'a'] = new trieNode();
            }
            node = node->links[c - 'a'];
        }

        node->isEnd = true;
    }
};

class Solution {
  public:
    int countSubs(string &s)
    {
        // code here
        int n = s.size();
        trie t;
    
        for(int i = 0; i < n; i++)
        {
            t.insert(s, i, n-1);
        }
    
        return t.cnt;
    }
};