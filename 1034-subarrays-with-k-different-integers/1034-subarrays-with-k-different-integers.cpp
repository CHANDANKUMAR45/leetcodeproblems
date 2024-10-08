class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int total=0;
        //Atleast(k)-Atleast(k+1)
        unordered_map<int ,int>freq;

        int start=0,end=0,n=nums.size(),count=0;

        //count of different integer in that window

        while(end<n)
        {
            freq[nums[end]]++; //add the freq of that number

            if(freq[nums[end]]==1)
            count++;

            //increase the window size tiil
            //number of differnt integer equal to k

            //Decrease the window size
            while(count==k)
            {
                total+=n-end;
                freq[nums[start]]--;
                if(freq[nums[start]]==0)
                count--;
                
                start++;
            }
            end++;

        }

        start=0,end=0,count=0;
        freq.clear();
        k++;

        
        while(end<n)
        {
            freq[nums[end]]++; //add the freq of that number

            if(freq[nums[end]]==1)
            count++;

            //increase the window size tiil
            //number of differnt integer equal to k

            //Decrease the window size
            while(count==k)
            {
                total-=n-end;
                freq[nums[start]]--;
                if(freq[nums[start]]==0)
                count--;
                
                start++;
            }
            end++;

        }
        return total;

    }
};