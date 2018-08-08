#!/usr/bin/Python -tt

import sys

# A. donuts
# Given an int count of a number of donuts, return a string
# of the form 'Number of donuts: <count>', where <count> is the number
# passed in. However, if the count is 10 or more, then use the word 'many'
# instead of the actual count.
# So donuts(5) returns 'Number of donuts: 5'
# and donuts(23) returns 'Number of donuts: many'
def donuts(count):
	if count >= 10:
		value = 'many'
	else:
		value = count
	
	result = 'Number of donuts: ' + str(value)
	return result

# B. both_ends
# Given a string s, return a string made of the first 2
# and the last 2 chars of the original string,
# so 'spring' yields 'spng'. However, if the string length
# is less than 2, return instead the empty string.
def both_ends(s):
	if(len(s) < 2):
		return ''
	
	first = s[:2]
	last = s[-2:]
	
	return first+last

# C. fix_start
# Given a string s, return a string
# where all occurences of its first char have
# been changed to '*', except do not change
# the first char itself.
# e.g. 'babble' yields 'ba**le'
# Assume that the string is length 1 or more.
# Hint: s.replace(stra, strb) returns a version of string s
# where all instances of stra have been replaced by strb.
def fix_start(s):
	result = s[0] + s[1:].replace(s[0], '*')
	
	return result

# D. MixUp
# Given strings a and b, return a single string with a and b separated
# by a space '<a> <b>', except swap the first 2 chars of each string.
# e.g.
#   'mix', pod' -> 'pox mid'
#   'dog', 'dinner' -> 'dig donner'
# Assume a and b are length 2 or more.
def mix_up(a, b):
	newa = b[:2] + a[2:]
	newb = a[:2] + b[2:]
	
	return newa + ' ' + newb

def test(got, expected):
	if got == expected:
		prefix = ' OK '
	else:
		prefix = ' X '
	print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))

def main():
	print 'donuts'
	# Each line calls donuts, compares its result to the expected for that call.
	test(donuts(4), 'Number of donuts: 4')
	test(donuts(9), 'Number of donuts: 9')
	test(donuts(10), 'Number of donuts: many')
	test(donuts(99), 'Number of donuts: many')
	
	print
	print 'both_ends'
	test(both_ends('spring'), 'spng')
	test(both_ends('Hello'), 'Helo')
	test(both_ends('a'), '')
	test(both_ends('xyz'), 'xyyz')

	print	
	print 'fix_start'
	test(fix_start('babble'), 'ba**le')
	test(fix_start('aardvark'), 'a*rdv*rk')
	test(fix_start('google'), 'goo*le')
	test(fix_start('donut'), 'donut')
	
	print
	print 'mix_up'
	test(mix_up('mix', 'pod'), 'pox mid')
	test(mix_up('dog', 'dinner'), 'dig donner')
	test(mix_up('gnash', 'sport'), 'spash gnort')
	test(mix_up('pezzy', 'firm'), 'fizzy perm')

if __name__ == '__main__':
	main() 
