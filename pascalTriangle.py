#	IMPLEMENT PASCAL TRIANGLE

import os
import time
import math

class PascalTriangle(object):
	def __init__(self):
		print("Pascal Triangle:")
	
	def getUserInput(self):
		height=int(input("Please input the height of Pascal's Triangle: "))
		for row in self.computePascalTriangle(height):
			print " "*(height*2),row
			height-=1
			time.sleep(2)
	
	def computePascalTriangle(self,param_height):
		result=[]
		for count in range(param_height):
			row=[]
			for element in range(count + 1):
				row.append(self.combination(count,element))
			result.append(row)
		return result
	
	def combination(self,n,r):
		return int((math.factorial(n))/( (math.factorial(r))*math.factorial(n-r)))
		
def main():
	pt=PascalTriangle()
	pt.getUserInput()

os.system("clear")
main()
