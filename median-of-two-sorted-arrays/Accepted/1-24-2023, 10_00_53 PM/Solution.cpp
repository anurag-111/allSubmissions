// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
   
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        double median=0.0;
        int low = 0;
        int high = x;
        
        while(low<=high){
            
            int partitionX = (low+high)/2;
            int partitionY = (x+y+1)/2 -partitionX; 
            
            int maxLeftX = (partitionX == 0)?INT32_MIN:nums1[partitionX-1];
            int minRightX = (partitionX == x)?INT32_MAX:nums1[partitionX];
            
            int maxLeftY = (partitionY == 0)?INT32_MIN:nums2[partitionY-1];
            int minRightY = (partitionY == y)?INT32_MAX:nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                // we have found the right partition. Calculate the median and return;
                
                if((x+y)%2==0){ //both arrays have even number of elements in total
                   return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
                }else{
                    //odd number of elements in total;
                    return (double)max(maxLeftX,maxLeftY);
                }
            }else if(maxLeftX>minRightY){
                    //too far right on first array, move towards left.
                    high = partitionX-1;
            }else{
                    //too far left on first array, move towards right.
                    low = partitionX+1;
            }
        
        }    
        return median;
    }
        
};