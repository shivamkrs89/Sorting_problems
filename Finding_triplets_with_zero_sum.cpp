/*
Find triplets with zero sum

Given an array of integers. Check whether it contains a triplet that sums up to zero. 

Example 1:

Input: N = 5, arr[] = {0, -1, 2, -3, 1}
Output: true
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.

Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: false
Explanation: No triplet with zero sum exists. 


Your Task:
You don't need to read input or print anything. Your task is to complete the boolean function findTriplets() which takes the array arr[] and the size of the array (n) as inputs and returns True if the given array has a triplet with zero sum and False otherwise. 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constrains:
1 <= N <= 104
-106 <= Ai <= 106
*/
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends


/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr,arr+n);
    int i;
    for(i=n-1;i>=0;i--)
    {
        int hi=i-1;int low=0;
        while(low<hi)
        {
            if(arr[low]>0)
            break;
            if(arr[low]+arr[hi]+arr[i]==0)
            {
                return true;
            }
            if(arr[low]+arr[hi]+arr[i]>0)
            {
                hi--;
            }
            else if(arr[low]+arr[hi]+arr[i]<0)
            {
                low++;
            }
        }
        
    }
    return false;
}
