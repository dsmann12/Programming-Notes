#!/usr/bin/python --t

import sys

def repeat(s, exclaim):
	result = s*3
	
	if exclaim:
		result = result + '!!!'
	return result

def main():
	if len(sys.argv) >= 2:
		s = sys.argv[1] + ' '
	else:
		s = 'Hello '
	
	print repeat(s, False)
	print repeat(s, True)

if __name__ == '__main__':
	main()
