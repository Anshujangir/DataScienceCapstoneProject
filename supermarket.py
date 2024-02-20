od={}
while True:
    i=input("Enter item with price : ")
    if not i:
        break
    l1=i.split()
    price=l1[-1]
    item=" ".join(l1[:-1])
    od[item]=od.get(item,0)+int(price)
for k,v in od.items():
    print(k,v)
