nums = list()
while True:
	num = raw_input('Enter a number: ')
	if num == "done": break
	else:
		num = int(num)
		nums.append(num)
		
target = input('Enter the target number: ')
#nums = [2, 7, 11, 15]
#target = 17
flag = False

for i in range(len(nums)):
	for j in range(i+1,len(nums)):
		if nums[i]+nums[j] == target:
			flag = True
			print [i,j]
			
if flag == False:
	print "No such target exist."