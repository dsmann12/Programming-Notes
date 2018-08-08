#!/usr/bin/python -tt

# D. Given a list of numbers, return a list where
# all adjacent == elements have been reduced to a single element,
# so [1, 2, 2, 3] returns [1, 2, 3]. You may create a new list or
# modify the passed in list.
def remove_adjacent(nums):
	#loop through list
	#
	print nums
	i = 1
	while(i < len(nums)):
		if(nums[i] == nums[i-1]):
			del nums[i-1]
			i -= 1
		i += 1
	print nums

# E. Given two lists sorted in increasing order, create and return a merged
# list of all the elements in sorted order. You may modify the passed in lists.
# Ideally, the solution should work in "linear" time, making a single
# pass of both lists.
def linear_merge(list1, list2):
	#merge sort basically
	#loop until one list is empty
	#if list1[-1] > list2[-1]
	#elemt = list1.pop(-1)
	#else
	#elem = list2.pop(-1)
	#newlist.append(elem)
	#then place the rest of whichever list isn't empty

	merged = []
	while (len(list1) > 0 and len(list2)):
		if(list1[-1] > list2[-1]):
			elem = list1.pop(-1)
		else:
			elem = list2.pop(-1)
		merged.insert(0, elem)

	if(len(list1) > 0):
		for elem in list1:
			merged.insert(0, elem)
	else:
		for elem in list2:
			merged.insert(0, elem)

	return merged
# Note: the solution above is kind of cute, but unforunately list.pop(0)
# is not constant time with the standard python list implementation, so
# the above is not strictly linear time.
# An alternate approach uses pop(-1) to remove the endmost elements
# from each list, building a solution list which is backwards.
# Then use reversed() to put the result back in the correct order. That
# solution works in linear time, but is more ugly.


def test(got, expected):
	if(got == expected):
		prefix = ' OK '
	else:
		prefix = ' X '
	print '%s got: %s expected %s' % (prefix, repr(got), repr(expected))

def main():
	remove_adjacent([1, 2, 2, 3])
	remove_adjacent([2, 2, 2, 3])
	remove_adjacent([])
	remove_adjacent([1, 2, 2, 3, 4, 4, 2, 5, 4, 5, 5, 1, 3])

	print
	print 'linear_merge'
	print linear_merge(['aa', 'xx', 'zz'], ['bb', 'cc'])
	
if __name__ == '__main__':
	main()
