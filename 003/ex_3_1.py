class Solution(object):
    def lengthOfLongestSubstring(self, s):
		length = len(s)
		MaxLen = 0
		SubLen = 0
		window = dict()
		i = 0
		j = 0
		
		if length < 2: return length
		
		while j < length :
			if s[j] in window and window[s[j]] >= i:
				SubLen = j - i
				if SubLen > MaxLen:
					MaxLen = SubLen
				#New window	 
				i = window[s[j]] + 1
				window[s[j]] = j				
			else:
				window[s[j]] = j
				
			j = j + 1
					
		SubLen = j - i
		if SubLen > MaxLen:
			MaxLen = SubLen
		
		return MaxLen

#Test Main
lst = ["abcabcbb", "bbbbb", "pwwkew", "abccba", "au", "aab", "dvdf", "abcabcbb", "abba"]	
num = len(lst)
for i in range(num):
	result = Solution()
	sublen = result.lengthOfLongestSubstring(lst[i])
	print sublen