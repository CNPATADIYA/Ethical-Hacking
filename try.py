from time import time
i = 0
cs = False
prompt = "Web cache poisoning is an advanced technique whereby an attacker exploits the behavior of a web server and cache so that a harmful HTTP response is served to other users. Fundamentally, web cache poisoning involves two phases. First, the attacker must work out how to elicit a response from the back-end server that inadvertently contains some kind of dangerous payload. Once successful, they need to make sure that their response is cached and subsequently served to the intended victims. A poisoned web cache can potentially be a devastating means of distributing numerous different attacks, exploiting vulnerabilities such as XSS, JavaScript injection, open redirection, and so on."


def counter():
	i = 0 
	print (prompt)
	input(">> Press ENTER to begin << ")
	begin_time = time()
	inp = input("\n")
	end_time = time()
	final_time = (end_time - begin_time) / 60
	return final_time, inp


def wpm(time, line):
	words = line.split()
	word_length = len(words)
	words_per_m = word_length / time
	return words_per_m


def wordcheck(inp):
	prompts = prompt.split()
	inputs = inp.split()
	errorcount = 0
	
	idx = 0
	for inp in inputs:
		if inp != prompts[idx]:
			errorcount += 1
			if inp == prompts[idx + 1]:
				idx += 2
			elif inp != prompts[idx - 1]:
				idx += 1
		else:
			idx += 1

	words_left = len(prompts) - len(inputs)
	correct = float(len(prompts)) - float(errorcount)
	percentage = (((float(correct) / float(len(prompts))) - float(words_left) / float(len(prompts))) * 100)

	
	return percentage

tm, line = counter()
tm = round(tm, 2)
words_per_minute = wpm(tm, line)
words_per_minute = round(words_per_minute, 2)
print("You total time was: %r minutes"% tm)
print("with an average of: %r words per minute"% words_per_minute)
percentage = wordcheck(line)
percentager = round(percentage, 2)
print("with an accuracy of: %r %% accuracy" % percentager)