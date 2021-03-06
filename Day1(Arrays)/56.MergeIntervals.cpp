class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> MergeIntervals;
        if(intervals.size()==0){
            return MergeIntervals;
        }
        sort(intervals.begin(),intervals.end());
        for(auto it1 : intervals){
            vector<int> tempInterval=it1;
            for(auto it : intervals){
                if(it[0]<=tempInterval[1]){
                    tempInterval[1]=max(it[1],tempInterval[1]);
                    it1++;
                }
                else{
                    
                    break;
                }
            }
            MergeIntervals.push_back(tempInterval);
        }
    
        return MergeIntervals;
    }
};