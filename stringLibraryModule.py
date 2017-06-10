#IMPLEMENT STRING LIBRARY

#	Symbolic constant
ASCII_UPPERCASE='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ASCII_LOWERCASE='abcdefghijklmnopqrstuvwxyz'
DECIMAL_DIGITS='0123456789'

#	capitalize the original string
def capitalize(orig):
	#	Check first character of original string
	if orig[0] not in ASCII_LOWERCASE:
		#	First character not lower case, so just copy original string
		new=orig[:]
	else:
		newchar=chr(ord(orig[0])-32)
		print newchar
		new=str(newchar)+orig[1:]
	return new

#	check if the element is an alphabet
def is_alpha(orig):
	for element in orig:
		if element in ASCII_LOWERCASE:
			alpha_bool=True
		elif element in ASCII_UPPERCASE:
			alpha_bool=True
		else:
			alpha_bool=False
	return alpha_bool

#	check if the element is a digit
def is_digit(orig):
	for element in orig:
		if element in DECIMAL_DIGITS:
			digit_bool=True
		else:
			digit_bool=False
	return digit_bool

#	convert the lowercase alphabet to uppercase
def to_upper(orig):
	newStr=" "
	for i in range(0,len(orig)):
		if orig[i] not in ASCII_UPPERCASE and orig[i]!=' ' and orig[i] not in DECIMAL_DIGITS:
			newChar=chr(ord(orig[i])-32)
			newStr=newStr + str(newChar)
		else:
			newStr=newStr + orig[i]
	return newStr

def to_lower(orig):
	newStr=" "
	for i in range(0,len(orig)):
		if orig[i] not in ASCII_LOWERCASE and orig[i]!=' ' and orig[i] not in DECIMAL_DIGITS:
			newChar=chr(ord(orig[i])+32)
			newStr=newStr + str(newChar)
		else:
			newStr=newStr + orig[i]
	return newStr

def find_chr(orig,c):
	charFound_bool=False
	if len(c)==1:
		for i in range(0,len(orig)):
			if orig[i]==c:
				charFound_bool=True
				return i
			continue;
	else:
		return -1
	
	if charFound_bool==False:
		return -1

def find_str(orig,sub):
	strFound_bool=False
	if len(sub) > len(orig):
		print "length is not correct:"
		return -1
	for i in range(0,len(orig)):
		for j in range(0,len(sub)):
			if sub[j]==orig[i]:
				i+=1
				continue
			else:
				found_int=0
				break;
		if len(sub)==j+1:
			return i-j
	if strFound_bool==False:
		return -1

def replace_chr(orig,orig_chr,repl_chr):
	newStr=" "
	if len(orig_chr)!=1 or len(repl_chr)!=1:
		return " "
	for i in range(0,len(orig)):
		if orig[i]==orig_chr:
			newStr= newStr + repl_chr
		else:
			newStr= newStr + orig[i]
	return newStr

def replace_str(orig,orig_str,repl_str):
	replaced_str=" "
	index_parsed=[]

	for i in range(0,len(orig)):
		if i not in index_parsed:
			replaced_str = replaced_str + orig[i]
		for j in range(0,len(orig_str)):
			if orig_str[j]==orig[i]:
				index_parsed.append(i)
				i+=1
				continue
			else:
				break
		if len(orig_str)==j+1:
			replaced_str = replaced_str[0:i-j]
			for k in range(0,len(repl_str)):
				replaced_str = replaced_str + repl_str[k]
	return replaced_str
