nums = [2, 5, 5, 11]
target = 7

buff_dict = dict()

for i in range(len(nums)):
	if nums[i] in buff_dict:
		print (buff_dict[nums[i]],i) 
	else:
		buff_dict[target-nums[i]] = i

