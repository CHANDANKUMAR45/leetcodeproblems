class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int n=timePoints.size();
        vector<int>timeMin(n);

        for(int i=0;i<n;i++)
        {
            string times=timePoints[i];

            string h=times.substr(0,2);
            string m=times.substr(3,4);

            int hourint=stoi(h);
            int minint=stoi(m);
           
           timeMin[i]=hourint*60+minint;

        }

        sort(timeMin.begin(),timeMin.end());

        int result=INT_MAX;

        for(int i=1;i<n;i++)
        {
            result=min(result,timeMin[i]-timeMin[i-1]);
        }

        return min(result,(24*60-timeMin[n-1])+timeMin[0]);
    }
};