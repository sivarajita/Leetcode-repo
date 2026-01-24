class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a=[]
        c=0
        for i in nums:
            c^=i
        return c
     