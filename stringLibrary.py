from stringLibraryModule import*
import os

os.system("clear")
print("*"*20)
print(" STRING LIBRARY ")
print("*"*20)

A="the quick brown fox jumps over the lazy dog"
B="4328409283049"
C="AMSA IBM CORP "
D="aMSA"
E="ACAAA bbbbbbbb"

print "The predefined string are:"
print("-"*30)
print "A = ",A
print "B = ",B
print "C = ",C

print "\n"
print "1. Demonstrating Capitalize function for String:",A
print "-"*93
print(capitalize(A))

print "\n"
print "2. Checking if the string :",A," : is alpha or not :"
print "-"*93
print(is_alpha(A))

print "\n"
print "2. Checking if the string :",B," : is alpha or not :"
print "-"*93
print(is_digit(B))

print "\n"
print "3. Checking if the string :",A," : is digit or not :"
print "-"*93
print(is_digit(A))

print "\n"
print "3. Checking if the string :",B," : is digit or not :"
print "-"*93
print(is_digit(B))

print "\n"
print "4. Converting lowercase string to uppercase :"
print "-"*93
print(to_upper(A))

print "\n"
print "4. Converting uppercase string to lowercase :"
print "-"*93
print(to_lower(C))

print "\n"
print "5. Finding a character in string :",A
print "-"*80
print(find_chr(A,'q'))

print "\n"
print "5.1 . Finding a character in string :",C
print "-"*80
print(find_chr(C,'q'))

print "\n"
print "6 . Finding a string in string :",C
print "-"*80
print(find_str(C,'WQYEQUWYI'))

print "\n"
print "6.1 . Finding a string in string :",C
print "-"*80
print(find_str(C,'AMSA'))

print "\n"
print "7. Replacing a char in the string:",C
print "-"*80
print(replace_chr(C,'A','Ed'))

print "\n"
print "7.1 Replacing a char in the string:",C
print "-"*80
print(replace_chr(C,'A','E'))

print "\n"
print "7.2 Replacing a char in the string:",E
print "-"*80
print(replace_chr(E,'C','B'))

print "\n"
print "7.3 Replacing a str in the string:",C
print "-"*80
print(replace_str(C,'CORP','amsa'))

print "\n"
print "7.3 Replacing a str in the string:",A
print "-"*80
print(replace_str(A,'lazy','LAZY'))
