'''
*
* Problema UVa 537 - Artificial Intelligence?
*
'''

from sys import *

def removeDataField(l):
	s = l
	c = findConcept(s)
	num, s = findNum(s)
	prefix = findPrefix(s)
	unit = findUnit(s)

	if prefix != None:
		newDatafield =  c + "=" + num + prefix + unit
	else:
		newDatafield = c + "=" + num + unit

	##print(newDatafield)

	return l.replace(newDatafield, "")

def isDataField(s):
	return (s.find("=") != -1)

def findConcept(s):
	return s[s.find("=")-1]

def findNum(s):
	pos = s.find("=")
	s = s[pos+1::]
	num = ""
	found = False
	pos = 0
	for i in s:
		if not found and ("0" <= i <= "9" or i == "-"):
			num += i
			found = True
		elif found:
			if ( ("0" <= i <= "9") or i == "."):
				num += i
			else:
				return num, s[pos::]
		pos += 1

def findPrefix(s):
	for l in s:
		if( l == "m" or l == "k" or l == "M" ):
			return l
	return None

def findUnit(s):
	for l in s:
		if( l == "W" or l == "V" or l == "A" ):
			return l
	return None

def createDataField(s):
	c = findConcept(s)
	num, s = findNum(s)
	prefix = findPrefix(s)
	unit = findUnit(s)

	if( prefix != None ):
		if( prefix == "m" ):
			n = float(num)*0.001
		elif( prefix == "k" ):
			n = float(num)*1000.0
		elif( prefix == "M" ):
			n = float(num)*1000000.0
	else:
		n = float(num)

	return DataField(c, n, unit)

class DataField:
	def __init__(self, concept, value, unit):
		self.concept = concept
		self.value = value
		self.unit = unit

def main():
	lines = stdin.readlines()
	lines.pop(0)
	out = ""
	c = 0
	for line in lines:
		c += 1
		line = line.strip().split()
		lst = []
		for l in line:
			temp = l
			while isDataField(temp) :
				lst.append(createDataField(temp))
				temp = removeDataField(temp)

		v1 = lst[0]
		v2 = lst[1]
		print("Problem #%d" % c)
		if (v1.concept == "P" and v2.concept == "U") or (v2.concept == "P" and v1.concept == "U") :
			if v1.concept == "P":
				p, u = v1.value, v2.value
			else:
				p, u = v2.value, v1.value
			print( "I=" + ("%.2f" % float(p/u)) + "A" + "\n")
		elif (v1.concept == "P" and v2.concept == "I") or (v2.concept == "P" and v1.concept == "I") :
			if v1.concept == "P":
				p, i = v1.value, v2.value
			else:
				p, i = v2.value, v1.value
			print("U=" + ("%.2f" % float(p/i)) + "V" + "\n")
		elif (v1.concept == "U" and v2.concept == "I") or (v2.concept == "U" and v1.concept == "I") :
			if v1.concept == "U":
				u, i = v1.value, v2.value
			else:
				i, u = v2.value, v1.value
			print("P=" + ("%.2f" % float(u*i)) + "W" + "\n")
		##print()

main()