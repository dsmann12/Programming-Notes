#!/usr/bin/python -tt

# A. match_ends
# Given a list of strings, return the count of the number of
# strings where the string length is 2 or more and the first
# and last chars of the string are the same.
# Note: python does not have a ++ operator, but += works.
def match_ends(words):
	#list of strings
	#check each string's length
	#if length >= 2
	#check if first and last chars of string are same
	count = 0
	for word in words:
		if( (len(word) >= 2) and (word[0] == word[-1]) ):
			count +=1
	return count

# B. front_x
# Given a list of strings, return a list with the strings
# in sorted order, except group all the strings that begin with 'x' first.
# e.g. ['mix', 'xyz', 'apple', 'xanadu', 'aardvark'] yields
# ['xanadu', 'xyz', 'aardvark', 'apple', 'mix']
# Hint: this can be done by making 2 lists and sorting each of them
# before combining them.
def front_x(words):
	#loop through list
	#if element starts with x remove it from other list and place it in other list
	xlist = [word for word in words if word[0] == 'x']
	words = [word for word in words if word[0] != 'x']
	xlist.sort()
	words.sort()

	return xlist + words

# C. sort_last
# Given a list of non-empty tuples, return a list sorted in increasing
# order by the last element in each tuple.
# e.g. [(1, 7), (1, 3), (3, 4, 5), (2, 2)] yields
# [(2, 2), (1, 3), (3, 4, 5), (1, 7)]
# Hint: use a custom key= function to extract the last element form each tuple.
def sort_last(tuples):
	return sorted(tuples, key=lambda x: x[-1])

def test(got, expected):
	if got == expected:
		prefix = ' OK '
	else:
		prefix = ' X '
	print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))

def main():
	print 'match_ends'
	test(match_ends(['aba', 'xyz', 'aa', 'x', 'bbb']), 3)

	print
	print 'front_x'
	test(front_x(['bbb', 'ccc', 'axx', 'xzz', 'xaa']), 
		['xaa', 'xzz', 'axx', 'bbb', 'ccc'])
	test(front_x(['mix', 'xyz', 'apple', 'xanadu', 'aardvark']),
		['xanadu', 'xyz', 'aardvark', 'apple', 'mix'])

	print
	print 'sort_last'
	test(sort_last([(1, 3), (3, 2), (2, 1)]),
		[(2, 1), (3, 2), (1, 3)])
	test(sort_last([(2, 3), (1, 2), (3, 1)]),
		[(3, 1), (1, 2), (2, 3)])

if __name__ == '__main__':
	main()
