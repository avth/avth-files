#	IMPLEMENT THE NUMBER THEORY PERSISTENCE

import os
import sys

class NumberTheoryPersistence(object):
	def __init__(self):
		self.original_number=0

	def getUserInput(self):
		self.original_number=int(input("Please give me an integer (negative integer to quit : "))
		if self.original_number < 0:
			sys.exit()

	def __str__(self):
		return "({:10})".format(self.original_number)

class AdditivePersistence(NumberTheoryPersistence):
	def __init__(self):
		self.quo_int=0
		self.rem_int=0
		self.additiveRoot=0
		self.additivePersistence=0
		self.actual_number=0
	
	def calculateAdditivePersistence(self,actual_param):
		print("\n Additive Loop :")
		self.actual_number=actual_param
		while actual_param >=0 and not actual_param <=9:
			while actual_param >=10:
				self.quo_int=actual_param//10
				self.rem_int=actual_param%10
				self.additiveRoot+=self.rem_int
				actual_param=self.quo_int

			self.additiveRoot+=self.quo_int
			print(" sum : {:2}".format(self.additiveRoot))
			self.additivePersistence+=1
			actual_param=self.additiveRoot
			self.additiveRoot=0

		self.additiveRoot=actual_param
	
	def __str__(self):
		return (self.additivePersistence,self.additiveRoot)

class MultiplicativePersistence(NumberTheoryPersistence):
	def __init__(self):
		self.multiplicativeRoot=1
		self.multiplicativePersistence=0
		self.actual_number=0
		self.quo_int=0
		self.rem_int=0
	
	def calculateMultiplicativePersistence(self,actual_param):
		print(" Multiplicative Loop:")
		self.actual_number=actual_param
		while actual_param >=0 and not actual_param <=9:	
			while actual_param >=10:
				self.quo_int=actual_param//10
				self.rem_int=actual_param%10
				self.multiplicativeRoot=self.multiplicativeRoot * self.rem_int
				actual_param=self.quo_int

			self.multiplicativeRoot*=self.quo_int
			print(" product : {:2}".format(self.multiplicativeRoot))
			self.multiplicativePersistence +=1
			actual_param=self.multiplicativeRoot
			self.multiplicativeRoot=1

		self.multiplicativeRoot=actual_param
	
	def __str__(self):
		return (self.multiplicativePersistence,multiplicativeRoot)

userChoice='y'
def main():
	while userChoice=='y':
		ntp=NumberTheoryPersistence()
		ntp.getUserInput()

		ap=AdditivePersistence()
		ap.calculateAdditivePersistence(ntp.original_number)
		print("\n")
		mp=MultiplicativePersistence()
		mp.calculateMultiplicativePersistence(ntp.original_number)
		print("\n")
		print(" For the integer:{:2} ".format(ntp.original_number))
		print(" Additive Persistence :{:2}, Additive Root :{:2}".format(ap.additivePersistence,ap.additiveRoot))
		print(" Multiplicative Persistence :{:2}, Multiplicative Root :{:2}".format(mp.multiplicativePersistence,mp.multiplicativeRoot))

os.system("clear")
main()
