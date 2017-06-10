#	IMPLEMENT ANCIENT EGYPTIAN MULTIPLICATION

import os
import math
import time

class AncientEgyptianMultiplication(object):
	def __init__(self):
		self.number_str=" "
		self.numberA_str=" "
		self.numberB_str=" "
		self.numberA_int=0
		self.numberB_int=0
		self.finalProduct_int=0
	
	def __str__(self):
		return "({:10})".format(finalProduct_int)
	
	def getUserInput(self):
		self.number_str=raw_input("Please input the 2 numbers separated by a space:")
		self.numberA_str,self.numberB_str=self.number_str.split(' ')
		self.numberA_int=int(self.numberA_str)
		self.numberB_int=int(self.numberB_str)
		print(" A = ",self.numberA_int, "B = ", self.numberB_int)
		if self.numberB_int % 2!=0:
			print(" B was odd, we add A to make the product:",self.numberA_int)
			self.finalProduct_int +=self.numberA_int
	
	def ancEgyMul(self):
		while abs(self.numberB_int)//2 !=0:
			time.sleep(.5)
			self.numberA_int=self.numberA_int * 2
			if self.numberB_int < 0:
				self.numberB_int=-(abs(self.numberB_int)//2)
			else:
				self.numberB_int=self.numberB_int//2
			print(" A = ",self.numberA_int," and B = ",self.numberB_int)
			if abs(self.numberB_int)%2 ==0:
				continue;
			else:
				self.finalProduct_int+=self.numberA_int
				print(" B was odd, we add A to make the product:",self.finalProduct_int)

		if self.numberB_int < 0 and self.numberA_int < 0:
			self.finalProduct_int=abs(self.finalProduct_int)
			print(" Product is positive")
			return
		elif self.numberB_int < 0:
			self.finalProduct_int=-(self.finalProduct_int)
			print(" Product is negative")
			return
		elif self.numberA_int < 0:
			print(" Product is negative")
			return
		else:
			print(" Product is positive")
			return

def main(userChoice):
	while userChoice.lower()=='y':
		aem=AncientEgyptianMultiplication()
		aem.getUserInput()
		aem.ancEgyMul()
		print("The product of the two numbers is:",aem.finalProduct_int)
		userChoice=raw_input("Do you want to continue?(y/n) ")
		if userChoice.lower()=='y':
			continue
		elif userChoice.lower()=='n':
			break
		else:
			print(" Bad input, quitting")
			break;

os.system("clear")
userChoice='y'
main(userChoice)
