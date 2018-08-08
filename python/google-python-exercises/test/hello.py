#!/usr/bin/python -tt

import sys

#define main
def main():
	if len(sys.argv) >= 2:
		name = sys.argv[1]
	else:
		name = 'World'
	print 'Hello', name

#standard boilerplate
if __name__ == '__main__':
	main()
		
