#include <stdio.h>
#include <limits.h>


int brute_force_maxGain(int arr[], int n)
{
    int maxSum = 0;
    int sum = 0;
    int i,j,left,right;
    // left and right will show where to dig
    // each subarray will start with `i`
    for (i = 0; i < n; i++)
    {
        sum = 0;    
 
        // do for each subarray ending at `j`
        for (j = i; j < n; j++)
        {
            sum += arr[j];
 
            // updating the maximum sum and determining left and right
            if (sum > maxSum) {
            	left = i;
            	right = j;
                maxSum = sum;
            }
        }
    }
    printf ("\n ************************ Brute Force ************************");
    printf("\n\n Kazilmasi gereken kesintisiz blok butunu: %d-%d",left,right);
    return maxSum;
}


int find_bigger(int x, int y) {
	if(x>y)
	 return x;
	else
	 return y;
}




 // Divide And Conquer
int maximum_sum(int nums[], int low, int high,int number_Of_array)
{
	int i,left,right; // left and right will show where to dig

    // case where array contains 0 or 1 element
    if (high <= low){
            return nums[low];
	}
	
    int mid = (low + high) / 2;
 
    // Find maximum subarray sum for the left subarray including the middle element
    int left_max = 0;
    int sum = 0;
    
    // CALCULATING LEFT SUM 
    for (i = mid; i >= low; i--)
    {
        sum = sum + nums[i];
        if (sum > left_max) {
        	 left_max = sum;
        	 left = i;  
		}
           
    }
 
    // Find maximum subarray sum for the right subarray excluding the middle element  because we will add it on LSS : LEFT SUM SUBARRAY
    int right_max = 0;
    sum = 0;    
    for (i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        if (sum > right_max) {
            right_max = sum;
              right = i;
        }
    }
  
 
    // Recursively find the maximum subarray sum for the left and right subarray, and take maximum
    int left_or_right = find_bigger(maximum_sum(nums, low, mid,number_Of_array),maximum_sum(nums, mid + 1, high,number_Of_array));   
    int cross_sum_subarray = left_max + right_max;

       if(mid*2 == number_Of_array){        //If mid*2 = number_Of_array, it means that recursive operations will be terminated. Now we can write where we need to dig
       
       	printf("\n\n *********************** Divide And Conquer *****************");
       	
       	// LSS : LEFT SUM SUBARRAY
       	// RSS : RIGHT SUM SUBARRAY
       	// CSS : CROSS SUM SUBARRAY
       	//Depending on which of the LSS RSS AND CSS is larger, the place to dig will change, so it will be determined which one is bigger.
       	
       	if (maximum_sum(nums, low, mid,number_Of_array) >= maximum_sum(nums, mid + 1, high,number_Of_array) && maximum_sum(nums, low, mid,number_Of_array) >= cross_sum_subarray)
       			 printf("\n\n Kazilmasi gereken kesintisiz blok butunu: %d-%d",left,mid);
		   
        else if (maximum_sum(nums, mid + 1, high,number_Of_array) >= maximum_sum(nums, low, mid,number_Of_array) && maximum_sum(nums, mid + 1, high,number_Of_array) >= cross_sum_subarray)
         		   	 printf("\n\n Kazilmasi gereken kesintisiz blok butunu: %d-%d",mid+1,right);

        else if (cross_sum_subarray >= maximum_sum(nums, low, mid,number_Of_array) && cross_sum_subarray >= maximum_sum(nums, mid + 1, high,number_Of_array))
      		   	 printf("\n\n Kazilmasi gereken kesintisiz blok butunu: %d-%d",left,right);

      
	   }
     return find_bigger(left_or_right, cross_sum_subarray);

}
 

int main()
{
    // int arr[] = { 8, -30, 36, 2, -6, 52, 8,-1,-11,10,4 }; 
    // int arr[] = { 4 ,3, -116, 29, 213, 1001, -500}; 
   //int arr[] = { -4, 5, 7, -6, 10, -15, 3 };
  int arr[] = { 0,-8,6,92,-12,-98,100,1,0,-3,-2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
     int i;
     printf("\n  ");
     
    for (i=0; i<n; i++) 
       printf(" %d ", arr[i]);
  
  
    printf("\n  ");
    printf("\n En yuksek kazanc: %d",brute_force_maxGain(arr, n));
    printf("\n En yuksek kazanc: %d",maximum_sum(arr,0, n-1,n-1));
    return 0;
}
















 

