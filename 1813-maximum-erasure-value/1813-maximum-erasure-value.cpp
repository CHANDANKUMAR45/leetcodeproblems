class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int start=0,end=0,sum=0,MaxSum=0;

        map<int,int>m;
 
     while(end<nums.size())
     {
        sum+=nums[end];
        m[nums[end]]++;

        while(m[nums[end]]>1)
        {
            sum-=nums[start];
            m[nums[start]]--;
            start++;
        }
        
        MaxSum=max(MaxSum,sum);
        end++;
     }

     return MaxSum;

    }
};