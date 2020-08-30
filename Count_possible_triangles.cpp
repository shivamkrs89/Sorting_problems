/*
Count possible triangles

Given an unsorted array arr[] of positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 

Example 1:

Input: N = 3, arr[] = {3, 5, 4}
Output: 1
Explanation: A triangle is possible 
with all the elements 5, 3 and 4.

Example 2:

Input: N = 5, arr[] = {6, 4, 9, 7, 8}
Output: 10
Explanation: There are 10 triangles
possible  with the given elements like
(6,4,9), (6,7,8),...

Your Task: This is a function problem. You only need to complete the function findNumberOfTriangles() that takes arr[] and N as input parameters and returns the count of total possible triangles.

Expected Time Complexity: O(N2).
Expected Space Complexity: O(1)
*/
//code goes here


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





class Solution
{
 public:   int findNumberOfTriangles(int a[], int n)
    {
        // code here
        sort(a,a+n);
        int c=0;
        for(int i=n-1;i>=0;i--)
        {
            int low=0,hi=i-1;
            
            while(low<hi)
            {
                if(a[hi]+a[low]>a[i])
                {
                   // cout<<a[hi]<<' '<<a[low]<<' '<<a[i]<<'\n';
                    c+=(hi-low);
                     hi--;
                     
                }
                else
                {
                    low++;
                }
            }
        }
       
        return c;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends
