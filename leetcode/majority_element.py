class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count_nums = {}
        biggest = 0
        biggest_count = 0
        for number in nums:
            if number not in count_nums:
                count_nums[number] = 1
                if count_nums[number] > biggest_count:
                    biggest = number
                    biggest_count = count_nums[number]
                continue
            count_nums[number] += 1
            if count_nums[number] > biggest_count:
                biggest = number
                biggest_count = count_nums[number]
        
        return biggest
            
        
