#!/usr/bin/python -t

import re

def Find(pat, text):
	match = re.search(pat, text)
	
	if match: 
		print match.group()
	else:
		print 'Not Found'

def main():
	Find('ig', 'called piiig')
	Find('iig', 'called piiig')
	Find('i{2}g', 'called piiig')
	Find('i{3}g', 'called piiig')
	Find('i+g', 'called piiig')
	Find('i?g', 'called piiig')
	Find('igs', 'called piiig')
	Find('\wg', 'called piiig')
	Find('\w*g', 'called piiig')
	Find('.g', 'called piiig	much better: xyzg')
	Find('..g', 'called piiig	much better: xyzg')
	Find('...g', 'called piiig	much better: xyzg')
	Find('x..g', 'called piiig	much better: xyzg')

	#raw string tells python to ignore / formatting

	Find(r'c\.l', 'c.lled piiig')
	Find(r':\w\w\w', 'blah :cat blah blah')
	Find(r':\d\d\d', 'blah :cat :123 blah blah')
	Find(r'\d\s\d\s\d', '1 2 3')
	Find(r'\d\s+\d\s+\d', '1         2           3')
	Find(r':\w+', 'blah blah :kitten blah blah')
	Find(r':\S+', 'blah blah :kitten123&a=123&yatta blah blah')

	Find(r'\w+@\S+', 'blah blah dsmann1212@gmail.com yadda @ ')
	Find(r'[\w.]+@\S+', 'blah blah david.scheuermann@gmail.com yadda @ ')
	Find(r'[\w.]+@[\w.]+', 'blah blah david.scheuermann@gmail.com yadda @ ')

	#using groups
	m = re.search(r'([\w.]+)@([\w.]+)', 'blah blah david.scheuermann@gmail.com yadda @ ')
	print m.group()
	print m.group(1)
	print m.group(2)

	#find all
	mlist = re.findall(r'[\w.]+@[\w.]+', 'blah blah david.scheuermann@gmail.com yadda @ foo@bar.com ')
	print mlist
	
	for m in mlist:
		print m
	
	mlist = re.findall(r'([\w.]+)@([\w.]+)', 'blah blah david.scheuermann@gmail.com yadda @ foo@bar.com ')

	for m in mlist:
		print m

	print mlist

if __name__ == '__main__':
	main()
