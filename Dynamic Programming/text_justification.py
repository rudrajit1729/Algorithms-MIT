# Text Justification - DP Approach
# Author - rudrajit1729

def justification(words, page_width = 51):
	DP = {0:0}

	def total(line):
		temp = ''
		for word in line[:-1]:
			temp += word + " "
		temp += line[-1]
		return len(temp)

	def badness(line):
		total_length = total(line)
		if total_length > page_width:
			return float("inf")
		else:
			return (page_width - total_length) ** 3

	def pretty(words):
		n = len(words)
		for i in range(1, n+1):
			temp = []
			for k in range(0, i):
				cost = DP[k] + badness(words[k:i])
				temp.append(cost)
			DP[i] = min(temp)

		return DP

	return pretty(words)

def experiment(text, page_width):
	words = text.split()
	DP = justification(words, page_width)
	min = float("inf")
	for i in DP.keys():
		if min > DP[i]:
			min = DP[i]
			if i != 0:
				print(words[i-1], end = " ")
		else:
			min = DP[i]
			print("\n", words[i-1], end = " ")

if __name__ == '__main__' :
	chap = 'One of the most significant changes in Python 3 is that print is turned into a func-\
	tion. In Python 2.6, it is also possible to use print as a function if you include the\
	statement from __future__ import print_function in each module where used.\
	The print() function works almost exactly the same as the print statement described\
	in the previous section.'
	
	text = "I wanted to smell that burnt midnight again, I wanted to feel that wind. It was a secret wanting, like a song I couldn\'t stop humming, or loving someone I could never have."

	example = 'blah blah blah blah reallylongword'

	experiment(text, 51)
	#experiment(example, 14)
	print()
	

