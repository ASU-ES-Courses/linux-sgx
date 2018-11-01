#!/usr/bin/env python

import string

all=string.maketrans('','')
nodigs=all.translate(all, string.digits)

start	= []
end	= []
dur	= []

with open("Victim/file_out") as f:
	lines = f.readlines()
	for line in lines:

		addr = line.split(",")
		if len(addr) < 2:
			continue

		s = addr[0].translate(all,nodigs)
		e = addr[1].translate(all,nodigs)
		if len(s) < 19:
			for i in range(19-len(s)):
				s = str(s) + "0"
		if len(e) < 19:
			for i in range(19-len(e)):
				e = str(e) + "0"
			#print(str(s) + "," + str(e))
		start.append(s)
		end.append(e)


for i in range(len(start)):
	dur.append(int(end[i]) - int(start[i]))

avg = 10
total = 0
for i in range(10,20):
	total += dur[i]

average = total/avg

print("AVG: " + str(average))


#attack_start = input("attack start time:")
#attack_end   = input("attack end time:")
attack_start = 1540872469164615265
attack_end = 1540872472464697180


index = []
for i in range(len(start)):
	if(int(attack_start) < int(start[i])):
		if(int(attack_end) > int(end[i])):
			index.append(i)

longest = []
for i in index:
	longer = int(dur[i])/int(average)
	longest.append(longer)
#	print("Iteration " + str(i) + ",  " + str(longer) + " times longer than average")


print("affected iterations:	" + str(len(longest)))

five_count = 0
twenty_count = 0
fifty_count = 0
hundred_count = 0
thundred_count = 0
fhundred_count = 0
thousand_count = 0
above_count = 0
for i in longest:
	if i < 5:
		five_count += 1
	elif i < 20:
		twenty_count += 1
	elif i < 50:
		fifty_count += 1
	elif i < 100:
		hundred_count += 1
	elif i < 200:
		thundred_count += 1
	elif i < 500:
		fhundred_count += 1
	elif i < 1000:
		thousand_count += 1
	else:
		above_count += 1

print("less than 5x:		" + str(five_count))
print("5x	--> 20x:	" + str(twenty_count))
print("20x	--> 50x:	" + str(fifty_count))
print("50x	--> 100x:	" + str(hundred_count))
print("100x	--> 200x:	" + str(thundred_count))
print("200x	--> 500x:	" + str(fhundred_count))
print("500x	--> 1000x:	" + str(thousand_count))
print("greater than 1000x:	" + str(above_count))














		
	





	









