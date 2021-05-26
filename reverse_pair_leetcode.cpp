Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2

Example 2:

Input: nums = [2,4,3,5,1]
Output: 3

 

Constraints:

    1 <= nums.length <= 5 * 104
    -231 <= nums[i] <= 231 - 1

//code starts
      class Solution {
public:
    void merge(vector<int> &arr,int l,int m, int r,int& count)
{
     // Your code here
     int sz1=m-l+1;
     int sz2=r-m;
     int larr[sz1];
     int rarr[sz2];
     int i,j,k;
     for(i=0;i<sz1;i++)
     larr[i]=arr[l+i];
     
     for(j=0;j<sz2;j++)
     rarr[j]=arr[l+sz1+j];
     
     j=0;
        while(j<sz2){//checking for both subarray for number of reverse pairs
     long long int sm=rarr[j];
        sm*=2;
        if(larr[sz1-1]<sm){
            j++;continue;
        }
        for(i=0;i<sz1;i++)
        {
            
         //   cout<<sz1<<' '<<sz2<<' '<<sm/2<<' '<<larr[i]<<'\n';
            if(larr[i]>sm)
            {
                count+=(sz1-i);
                break;
            }
        }
            j++;
        }
        
        
     
     i=0,j=0,k=l;
     
     while(i<sz1 && j<sz2)
     {
         
         if(larr[i]<rarr[j])
         {
         arr[k]=larr[i];
         i++;
         }
         else
         {
             arr[k]=rarr[j];
             j++;
         }
         
         k++;
     }
     while(i<sz1)
     {
         arr[k]=larr[i];
         i++;k++;
     }
     
     while(j<sz2)
     {
         arr[k]=rarr[j];
         j++;k++;
     }
  
}
    void mergeSort(vector<int> &arr, int l,int r,int& count) {
    if (l < r)   {
        long long int m = l+(r-l)/2;
        mergeSort(arr, l, m,count);
        mergeSort(arr, m+1, r,count);
        merge(arr, l, m, r,count);
    }
} 
    int reversePairs(vector<int>& nums) {
         int count=0;
    mergeSort(nums,0,nums.size()-1,count);
    
    return count;
    }
};
