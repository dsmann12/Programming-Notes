#!\usr\bin\python -tt

import re

def main():
	f = open('randomtext.txt')

	strToSearch = ''

	for line in f:
		strToSearch += line
	
	print strToSearch

	patFinder1 = re.compile('Aa1B')
	
	findPat1 = re.search(patFinder1, strToSearch)
	
	#print whole result
	print findPat1.group()
	
	#print first element of result
	print findPat1.start()
	
	#print last index of result
	print findPat1.end()
	
	#print range of result in (s, e) form
	print findPat1.span()
	
	#find all
	findPat1 = re.findall(patFinder1, strToSearch)
	
	for i in findPat1:
		print i

	splitFound = patFinder1.split(strToSearch)
	print splitFound

	subFound = patFinder1.sub('Real Text', strToSearch)
	print subFound
	
	#search for pattern and ignore case
	patFinder2 = re.compile('b3b2c', re.IGNORECASE)
	findPat2 = re.search(patFinder2, strToSearch)
	
	#check if pattern found
	if(findPat2):
		print findPat2.group()
	else:
		print 'Nothing found'

	#pull out every character not newline
	patFinder2 = re.compile('.*', re.IGNORECASE)
	findPat2 = re.search(patFinder2, strToSearch)
	
	if(findPat2):
		print findPat2.group()
	else:
		print 'Nothing found'

	#print out every char that is letter
	patFinder2 = re.compile('[a-z]', re.IGNORECASE)
	findPat2 = re.findall(patFinder2, strToSearch)
	
	for i in findPat2:
		print i
	
	#print out successful find in one line
	for i in findPat2:
		print i,
	
	#no need to escape chars in []
	patFinder2 = re.compile('[\\\\#$*?0-9]', re.IGNORECASE)
	findPat2 = re.findall(patFinder2, strToSearch)
	
	for i in findPat2:
		print i
	
	#print out successful find in one line
	for i in findPat2:
		print i,

	patFinder2 = re.compile('\d\D\s\S.\W\w', re.IGNORECASE)
	findPat2 = re.findall(patFinder2, strToSearch)
	
	for i in findPat2:
		print i
	
	#print out successful find in one line
	for i in findPat2:
		print i,


if __name__ == '__main__':
	main()
