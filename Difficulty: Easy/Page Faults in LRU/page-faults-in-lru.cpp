// User function Template for C++

class Solution {
  public:
    int pageFaults(int n, int cap, int pages[]) {
        // code here
        unordered_set <int> mem; // Memory to store the pages
        unordered_map <int, int> usedAtIndx; // To keep track of the last index the page has been used
        int faults = 0;
        for(int i = 0; i < n; i++)
        {
            if(mem.size() < cap) // Memory is not full yet
            {
                if(mem.find(pages[i]) == mem.end()) // if page not present already then increment faults and insert the page into memory
                {
                    faults++;
                    mem.insert(pages[i]);
                }
                usedAtIndx[pages[i]] = i; // Update the index of the page we worked on
            }
            else // Memory is full so we need to replace the LRU Page if the current page is not present in the memory
            {
                if(mem.find(pages[i]) == mem.end())
                {
                    // Find the page that has the least used index from the map
                    int lru_indx = INT_MAX;
                    int lru_page = 0;
                    for(int i : mem)
                    {
                        if(lru_indx > usedAtIndx[i])
                        {
                            lru_indx = usedAtIndx[i];
                            lru_page = i;
                        }
                    }
                    // Erase the LRU page from the memory
                    mem.erase(lru_page);
                    // Insert the new page into memory
                    mem.insert(pages[i]);
                    faults++;
                }
                usedAtIndx[pages[i]] = i; // Update the index of the page we worked on
            }
        }
        return faults;
    }
};