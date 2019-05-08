from sys import stdin

final=list()
dic={}

def rer(l,acu,i,t):
	global final,diic
	if acu == int(l[0]):
		if dic.get(t)== None:
			dic[t] =1
		return

	if acu > int(l[0]) :
		return 
	while(i < len(l)):
		
		rer(l, acu+int(l[i]) , i+1,t+"+"+l[i])
		i+=1


def main():
	global final,dic
	line=  stdin.readline().split()
	
	while line[0]!='0':
		final = list()
		dic = {}
		rer(line,0,2,'')
		print("Sums of {0}:".format(line[0]))
		if len(dic)> 0:
			for i in dic:
				print(i[1:])
		else:
			print("NONE")

		line=  stdin.readline().split()

main()