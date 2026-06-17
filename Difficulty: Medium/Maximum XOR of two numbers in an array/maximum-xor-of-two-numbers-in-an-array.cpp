struct trieNode {
	trieNode* links[2] = {nullptr};

	~trieNode()
	{
		delete links[0];
		delete links[1];
		links[0] = links[1] = nullptr;
	}
};

class trie {
	trieNode* root = new trieNode();
public:
	void insert(int n)
	{
		trieNode* node = root;
		for(int i = 31; i >= 0; i--)
		{
			int bit = (n & (1 << i)) != 0;
			if(node->links[bit] == nullptr)
				node->links[bit] = new trieNode();
			node = node->links[bit];
		}
	}

	int findXOR(int n)
	{
		int ans = 0;
		trieNode* node = root;
		for(int i = 31; i >= 0; i--)
		{
			int bit = (n & (1 << i)) != 0;
			if(node->links[!bit] != nullptr)
			{
				ans += (1 << i);
				node = node->links[!bit];
			}
			else
				node = node->links[bit];
		}

		return ans;
	}
};

class Solution {
  public:
    int maxXor(vector <int> &arr)
    {
        // code here
        int n = arr.size();
    	trie t;
    	t.insert(arr[0]);
    
    	int ans = 0;
    	for(int i = 0; i < n; i++)
    	{
    		ans = max(ans, t.findXOR(arr[i]));
    		t.insert(arr[i]);
    	}
    
    	return ans;
    }
};
