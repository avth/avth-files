#	IMPLEMENTATION OF THE NINETY NINE TRICK

import os

class NinetyNineTrick(object):
	def __init__(self):
		self.numberOne_int=0
		self.numberTwo_int=0
		self.answer_int=0
		self.factor_int=0
		self.tempNum_str=""
		self.factorNum2_int=0
		self.chkPoint_char='y'
		self.divisor,self.quotient_int,self.reminder_int=0,0,0
		self.addHunUnitDigit=0

	def __str(self):
		return "({:10},{:10})".format(self.answer_int,self.finalResult)

	def getInputNumOne(self):
		while self.chkPoint_char=='y':
			self.numberOne_int=int(input("*You* This will be the answer. Select a number 10-49 :"))
			if self.numberOne_int >10 and self.numberOne_int <49:
				self.chkPoint_char='n'
				self.answer_int=self.numberOne_int
				self.factor_int=99-self.numberOne_int
				break
			else:
				print(" Input # between 10 and 49 ")
				continue

		self.chkPoint_char='y'

	def getInputNumTwo(self):
		while self.chkPoint_char=='y':
			self.numberTwo_int=int(input("*Player* Pick any number 50-99:"))
			if self.numberTwo_int >50 and self.numberTwo_int <99:
				self.chkPoint_char='n'
				break
			else:
				print(" Input # between 50 and 99")
				continue
	
	def calculateNinetyNineTrick(self):
		self.factorNum2_int=self.factor_int + self.numberTwo_int
		self.divisor=self.factorNum2_int
		
		while self.divisor >=10:
			self.quotient_int=self.divisor//10
			self.reminder_int=self.divisor%10
			self.divisor=self.quotient_int
			self.tempNum_str=str(self.reminder_int)+self.tempNum_str
		
		self.addHunUnitDigit=int(self.tempNum_str)+ self.divisor
		self.finalResult=self.numberTwo_int-self.addHunUnitDigit

def main():
	nnt=NinetyNineTrick()
	nnt.getInputNumOne()
	nnt.getInputNumTwo()
	nnt.calculateNinetyNineTrick()
	print(" I said the answer was ", nnt.answer_int, " and the calculation result is ",nnt.finalResult)

os.system("clear")
main()
