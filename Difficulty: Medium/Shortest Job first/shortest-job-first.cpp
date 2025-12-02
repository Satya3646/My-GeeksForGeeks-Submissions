// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& process) {
        // code here
        int n = process.size();
        // Sort the processes to have the shortest task first
        sort(process.begin(), process.end());
        int wait = 0; // The witing time for current task
        int tot_wait = 0; // Total waiting time for all the tasks
        for(int i = 0; i < n; i++)
        {
            // The current task is now being completed so its wait time
            // will be "wait"
            // The total wait time for all the processed is also updated
            tot_wait += wait;
            wait += process[i];
        }
        return tot_wait / n;
    }
};