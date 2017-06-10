# CAESAR CYPHER CODE
import os
import sys

class CaeserCipher(object):
	def __init__(self):
		self.alphabet=[]
		self.encodedList=[]

	def generateAlphabetList(self):
		for i in range(26):
			i+=97
			self.alphabet.append(chr(i))
	
	def getInputStrings(self,menuCh_chr):
		if menuCh_chr=='e':
			userInpEnc_str=raw_input(" Give me a string to encode :")
			userInpEncRot_num=int(input(" Give me a rotation :"))
			self.encodeString(userInpEnc_str,userInpEncRot_num)
		elif menuCh_chr=='d':
			userInpDec_str=raw_input(" Give me a string to decode :")
			userInpDec_word=raw_input(" Give me a word in the string :")
			self.decodeString(userInpDec_str,userInpDec_word)
	
	def decodeString(self,userInpDec_str,userInpDec_word):
		decoding_bool=False

		for strInList in self.encodedList:
			words = strInList[0].split()
			if userInpDec_word in words:
				print " The rotatation was:",strInList[2]
				print " The decoded string is:",strInList[0]
				decoding_bool=True
				break

		if decoding_bool==False:
			print " Couldn't find a decoding"

	def encodeString(self,userInpEnc_str,userInpEncRot_num):
		encodedString=" "
		for i in range(len(userInpEnc_str)):
			if userInpEnc_str[i] in self.alphabet:
				calculateIndex_int =(self.alphabet.index(userInpEnc_str[i])) + userInpEncRot_num 
				if calculateIndex_int > 25:
					calculateIndex_int=(calculateIndex_int-len(self.alphabet))
				encodedString = encodedString + self.alphabet[calculateIndex_int]
			else:
				encodedString = encodedString + userInpEnc_str[i]

		strList=[userInpEnc_str,encodedString,userInpEncRot_num]
		self.encodedList.append(strList)
		print " Encoded string is: ",encodedString
	
	def printAlphabet(self):
		print self.alphabet

def main(menuChoice):
	ccCode=CaeserCipher()
	ccCode.generateAlphabetList()

	while menuChoice=='y':
		menuCh_chr=raw_input(" q for quit, d for decode, e for encode: ")
		if menuCh_chr=='q':
			#print ccCode.encodedList
			sys.exit()
		elif menuCh_chr=='e' or menuCh_chr=='d':
			ccCode.getInputStrings(menuCh_chr)
		else:
			print "Bad command, try again"
	

os.system('clear')
menuChoice='y'
main(menuChoice)
