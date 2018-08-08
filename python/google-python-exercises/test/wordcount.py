#!/usr/bin/python -tt

"""Wordcount exercise
Google's Python class

The main() below is already defined and complete. It calls print_words()
and print_top() functions which you write.

1. For the --count flag, implement a print_words(filename) function that counts
how often each word appears in the text and prints:
word1 count1
word2 count2
...

Print the above list in order sorted by word (python will sort punctuation to
come before letters -- that's fine). Store all the words as lowercase,
so 'The' and 'the' count as the same word.

2. For the --topcount flag, implement a print_top(filename) which is similar
to print_words() but which prints just the top 20 most common words sorted
so the most common word is first, then the next most common, and so on.

Use str.split() (no arguments) to split on all whitespace.

Workflow: don't build the whole program at once. Get it to an intermediate
milestone and print your data structure and sys.exit(0).
When that's working, try for the next milestone.

Optional: define a helper function to avoid code duplication inside
print_words() and print_top().
"""

"""
check usage. Should have flag argument and filename argument
flag can be --count or --topcount
if --count run print_words()
if --topcount run print_top()
"""
import sys
#counts how often each word appears in text
def create_dict(filename):
	words = {}
	f = open(filename, 'r')
	for line in f:
		w = line.split()
		#iterate through each string in line
		#check if word is in dict
		for word in w:
			word = word.lower()
			if word in words:
				words[word] += 1 
			else:
				words[word] = 1		
	f.close()
	return words
	

def print_words(filename):
	#create empty dict
	#word.tolower will be key, value will be count
	#open file for reading
	#read a line
	#split line on whitespace
	#for every word in list
	#first check if word is in dict
	#if so update count
	#if not, store in dict and set count to 1
	words = create_dict(filename)

	for key in sorted(words.keys()):
		print key, words[key]
	return

def print_top(filename):
	words = create_dict(filename)	
	wlist = sorted(words, key=lambda x: words[x], reverse=True)
	wlist = wlist[:20]
	for word in wlist:
		print word, words[word]

def main():
	if(len(sys.argv) < 3):
		print 'Usage: %s <flag> <filename>' % sys.argv[0]
		sys.exit(1)
	
	filename = sys.argv[2]
	if(sys.argv[1] == '--count'):
		print_words(filename)
	elif(sys.argv[1] == '--topcount'):
		print_top(filename)
	else:
		print 'Unknown argument!'
		sys.exit(1)

if __name__ == '__main__':
	main()
