import re
import csv 
reg = re.compile("\"|,| ")
sum_text=0
stop_words={}
stop_file = open("/mnt/7274E81574E7D9BD/Windows.old/Stop_words.txt", "r")
content = stop_file.read()
content = re.split(reg, content)
sum_title=0
for word in content :
    if word :
        stop_words[word] = True
stop_words["knock"]=True

fp=open("knock.txt","r")
pattern = re.compile("[^a-zA-Z]")

count=0
outputfile="data_final.txt"
fp_out=open(outputfile,"w+")
ans="@relation DataAnalytics"+"\n"+"\n"
fp_out.write(ans)
unique_words=[]
final_words={}
for line in fp.readlines():
	words=re.split(pattern,line)
	# words=line.split(" ")
	for word in words:
		word=word.lower()
		if word in stop_words:
			continue;
		elif word in unique_words:
			continue;
		elif len(word)>1:
			final_words[word]=count
			unique_words.append(word)
			ans="@attribute"+" "+word+" {"+word+"}"+"\n"
			fp_out.write(ans)
			count=count+1

fp.close()
finaldata=[]
# outputfile="data_final.csv"
# fp_out=open(outputfile,"w+")
# unique_words=" ".join(unique_words)

print(unique_words)
print(final_words)
finaldata.append(unique_words)
# fp_out.write(unique_words)
count1=0
fp=open("knock.txt","r")
ans="\n"+"@data"+"\n"
fp_out.write(ans)
for line in fp.readlines():
	x=[str(0)]*len(unique_words)
	words=re.split(pattern,line)
	count1=count1+1
	# ans=str(count1)+","
	ans=""
	for word in words:
		word=word.lower()
		if word in stop_words:
			continue
		if len(word)>1:
			# print(word," ",final_words[word])
			x[int(final_words[word])]=word

	final_wording = sorted(final_words.items(), key=lambda kv: kv[1])
	# print(final_words)
	for i in final_wording :
		if x[int(i[1])]==i[0]:
			ans=ans+i[0]+","
		else:
			ans=ans+"?"+","

	# x=" ".join(x)
	if(len(ans)>0):
		# ans=ans[0:-1]
		ans=ans+"\n"
		fp_out.write(ans)
	# finaldata.append(x)

# with open(outputfile,"wb") as f:
# 	writer= csv.writer(f)
# 	writer.writerows(finaldata)








	