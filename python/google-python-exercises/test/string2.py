#!/usr/bin/python -tt

import sys

# D. verbing
# Given a string, if its length is at least 3,
# add 'ing' to its end.
# Unless it already ends in 'ing', in which case
# add 'ly' instead.
# If the string length is less than 3, leave it unchanged.
# Return the resulting string.
def verbing(s):
	if len(s) >= 3:
		if s[-3:] == 'ing':
			return s + 'ly'
		else:
			return s + 'ing'
	else:
		return s

# E. not_bad
# Given a string, find the first appearance of the
# substring 'not' and 'bad'. If the 'bad' follows
# the 'not', replace the whole 'not'...'bad' substring
# with 'good'.
# Return the resulting string.
# So 'This dinner is not that bad!' yields:
def not_bad(s):
	notindex = s.find('not')
	badindex = s.find('bad')
	
	if notindex < badindex:
		return s.replace(s[notindex:], 'good')	
	else:
		return s

# F. front_back
# Consider dividing a string into two halves.
# If the length is even, the front and back halves are the same length.
# If the length is odd, we'll say that the extra char goes in the front half.
# e.g. 'abcde', the front half is 'abc', the back half 'de'.
# Given 2 strings, a and b, return a string of the form
#  a-front + b-front + a-back + b-back
def calculate_mid(s):
	mid = len(s) / 2
	
	if(len(s) % 2 != 0):
		mid += 1
	
	return mid

def front(s):
	return s[:calculate_mid(s)]

def back(s):
	return s[calculate_mid(s):]

def front_back(a, b):
	#mod 2 = 0 means even
	return front(a) + front(b) + back(a) + back(b)

def test(got, expected):
	if got == expected:
		prefix = ' OK '
	else:
		prefix = ' X '
	
	return '%s Got: %s Expected: %s' % (prefix, repr(got), repr(expected))

def main():
	print 'verbing'
	print test(verbing('hail'), 'hailing')
	print test(verbing('swimming'), 'swimmingly')
	print test(verbing('do'), 'do')
	
	print
	print 'not_bad'
	print test(not_bad('This movie is not so bad'), 'This movie is good')
	print test(not_bad('This dinner is not that bad'), 'This dinner is good')
	print test(not_bad('This tea is not hot'), 'This tea is not hot')
	print test(not_bad("It's bad yet not"), "It's bad yet not")

	print test(front_back('abcd', 'xy'), 'abxcdy')
	print test(front_back('abcde', 'xyz'), 'abcxydez')
	print test(front_back('Kitten', 'Donut'), 'KitDontenut')

if __name__ == '__main__':
	main()
