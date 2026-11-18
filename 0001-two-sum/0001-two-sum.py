class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap={}
        for i in range(len(nums)):
            x=target-nums[i]
            if(x in hashmap):
                return [hashmap[x],i]
            hashmap[nums[i]]=i
        return []

        