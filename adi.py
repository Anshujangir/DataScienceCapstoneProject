arr =[26,57,37]
name =['adi','ram','aashu']
pos = int(input("roll number : "))
temp=0
for i in (0,2):
    if (arr[i]==pos):
        temp = i
        break
for j in (0,2):
     if (j==temp):
        print(name[j])
