int cnt = 0;
 priority_queue<int, vector<int>, greater<int>> pq;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) { 
        while(!pq.empty()){
            pq.pop();
        }
        cnt = k;
       for(int i=0;i<nums.size();i++){
           pq.push(nums[i]);
       }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>cnt){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */