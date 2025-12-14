class Solution {
    
    
    
    
    
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue <int> pq; // Max heap.
        for(int i : arr)
        {
            pq.push(i);
            if(pq.size() > k) // if size > k pop. this will ensure that the heap will contain the smallest k elements.
                pq.pop();
        }
        return pq.top(); // After the end of iteration pq will contain top k smallest elememts.
    }
};