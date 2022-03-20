/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
    var result = nums.map((x)=>{
       return nums[x]; 
    });
    return result;
};