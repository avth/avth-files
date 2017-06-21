# IMPLEMENT THE ENGLISH - SPANISH VOCABULARY USING DATA STRUCTURE "DICTIONARY"
import os
import string
import random
import sys

class Vocabulary(object):
	def __init__(self):
		self.dirContents=" "
		self.dictionary_verbs={}
		self.file_input=" "
		self.count_in_dict=0
		self.word_count_int=0
		self.key=" "
		self.value=" "
		self.correct_answers_list=[]
	
	def welcomeScreen(self):
		print " Welcome to the vocabulary quiz program. Select one of the following word lists:"
	#	display the "txt" files from the directory
	def displayDirectoryContents(self):
		for file in os.listdir("."):
			if file.endswith(".txt"):
				print " \t",file

		self.getFileInput()
	
	#	USER ACTION : user enters the file name
	def getFileInput(self):
		self.file_input=raw_input(" Please make your selection: ");
		self.readFileContents()
	
	#	Read the file contents,strip, split(:) and store in the dictionary
	def readFileContents(self):
		read_file=open(self.file_input,"r")
		for each_line in read_file:
			each_line=each_line.strip()
			self.key,self.value=each_line.split(":")
			self.dictionary_verbs[self.key]=self.value
			self.count_in_dict +=1
	
		for item in self.dictionary_verbs.items():
			print item
		self.getWordCountToQuiz()
	
	# USER ACTION : get user input regarding how many words to be quizzed.
	def getWordCountToQuiz(self):
		print " ",self.count_in_dict, " entries found."
		self.word_count_int=int(input(" How many words would you like to be quizzed on? "))
		self.displayEnglishWords()

	#	USER ACTION	:	get the English words & user enters Spanish equivalent
	def displayEnglishWords(self):
		answer_bool=False
		prev_answer_bool=True
		no_of_correct_answers=0
	
		#	checking if the user entered answers are correct
		for i in range(self.word_count_int):
			count=0
			prev_answer_bool=True
			english_word=random.choice(self.dictionary_verbs.keys())
			print " English word:", english_word
			spanish_word_values=self.dictionary_verbs[english_word].split(",")
			print " Enter ",len(spanish_word_values), " equivalent Spanish word(s)."
			for j in range(len(spanish_word_values)):
				print " Word[",j+1,"]:"
				spanish_word_answer=raw_input(" ")
				if spanish_word_answer in spanish_word_values:
					if prev_answer_bool==False:
						answer_bool=False	
					else:
						answer_bool=True
				else:
					answer_bool=False
					prev_answer_bool=False
			if answer_bool==True:
				print " Correct!"
				no_of_correct_answers+=1
			else:
				print " Incorrect."
				self.correct_answers_list.append(english_word)		
				self.correct_answers_list.extend(":")
				self.correct_answers_list.append(spanish_word_values)

		print "\n ", 3*'-'
		print " ", no_of_correct_answers, "out of ", self.word_count_int, " correct."
		#	Write the correct answers to output file
		correct_answers_file=raw_input(" Enter an output file (or press enter to quit):")
		if correct_answers_file!="":
			write_to_file=open(correct_answers_file,"w+")
			for word in self.correct_answers_list:
				write_to_file.write(str(word))
			write_to_file.close()
		else:
			sys.exit()	

def main():
	vocab=Vocabulary()
	vocab.welcomeScreen()
	vocab.displayDirectoryContents()

os.system('clear')
main()
