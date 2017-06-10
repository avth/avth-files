#	IMPLEMENT THE 196 ALGORITHM

import os
import time

class Palindrome(object):
	def __init__(self):
		self.first_int=0
		self.second_int=0
		self.number_str=""
		self.number_rev_str=""
		self.palinCount_int=0
		self.iterCount=0
		self.numberJ_int=0
		self.addNumRevNum=0
		self.nonLychrelCount_int=0
		self.lychrelCount_int=0
		self.nonLychrel_bool=False
		self.numIsPalin_bool=False
		self.palin_list=[]
		self.nonLychrel_list=[]
		self.lychrel_list=[]

	
	def getUserInput(self):
		self.first_int=int(input("Give me the first integer:"))
		self.second_int=int(input("Give me the second integer:"))
	
	def checkPalindrom(self,param_addNumRevNum):
		j_tmp=str(param_addNumRevNum)
		j_tmp_rev=j_tmp[::-1]
		if j_tmp==j_tmp_rev:
			self.numIsPalin_bool=True;
		else:
			self.numIsPalin_bool=False;
		return self.numIsPalin_bool
	
	
	def checkNaturalPalindrome(self):
		for i in range(self.first_int,self.second_int+1):
			self.iterCount=0
			self.nonLychrel_bool=False
			self.numberJ_int=i
			self.number_str=str(i)
			self.number_rev_str=self.number_str[::-1]
			self.checkPalindrom(i)
			if self.numIsPalin_bool==True:
				self.palin_list.append(i)
				self.palinCount_int+=1
			else:
				while self.iterCount <= 60 and self.nonLychrel_bool==False:
					self.addNumRevNum=self.numberJ_int + int(self.number_rev_str)
					self.checkPalindrom(self.addNumRevNum)
					if self.numIsPalin_bool==True:
						self.nonLychrelCount_int +=1
						self.nonLychrel_bool=True
						self.nonLychrel_list.append(i)
						break
					self.iterCount+=1
					self.numberJ_int=self.addNumRevNum
					self.number_rev_str=str(self.numberJ_int)[::-1]
					self.addNumRevNum=0
					if self.iterCount==60 and self.nonLychrel_bool==False:
						self.lychrelCount_int+=1
						self.lychrel_list.append(i)
	
	def __str__(self):
		return "({:10})".format(self.palinCount_int)	

def main():
	palin=Palindrome()
	palin.getUserInput()
	palin.checkNaturalPalindrome()
	print('*'*35)
	print(" In the range",palin.first_int," to", palin.second_int)
	print("Palindrome Number Count :",palin.palinCount_int)
	print("Non-Lychrel Number Count :",palin.nonLychrelCount_int)
	print("Lychrel Count :",palin.lychrelCount_int)
	print("\n")
	print("Natural Palidrom List :",palin.palin_list)
	print("\n")
	print("Non Lychrel List:",palin.nonLychrel_list)
	print("\n")
	print("Lychrel List:",palin.lychrel_list)
	print("\n")

os.system('clear')
main()
