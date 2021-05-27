Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]//code goes here


Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

 

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109

//code goes here
      class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> anslist;
        sort(nums.begin(),nums.end());
        int i,j;
        int n=nums.size();
        map<vector<int>,bool> mvec;
        for(i=0;i<n-3;i++)
        {
            int sum=nums[i];
            for(j=i+1;j<n;j++)
            {
                int twosum=sum+nums[j];
                
                int tsum=target-twosum;
                int hi=n-1;int low=j+1;
               // cout<<tsum<<' '<<i<<' '<<j<<'\n';
                while(low<hi)
                {
                    if(nums[low]+nums[hi]>tsum)
                        hi--;
                    else if(nums[low]+nums[hi]<tsum)
                        low++;
                    else
                    {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[low]);
                        ans.push_back(nums[hi]);
                        if(!mvec[ans]){
                            mvec[ans]=1;
                        anslist.push_back(ans);
                    }
                        low++;hi--;
                    }
                        
                }
            }
        }
        
        return anslist;
    }
};
