nums = [int(i) for i in open("ex0", "r").read().split('\n')]

for i in range(5, len(nums)):
	if sum(1 for j in nums[i - 5:i] if nums[i] - j in nums[i - 5:i]) == 0:
		print(nums[i])