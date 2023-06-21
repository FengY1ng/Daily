names=['Bob','Tom','Jerry','Alice','Mike','John','Jack','Mary','Marry',''];
newNames=[name.upper() for name in names if len(name)>3];
print(newNames);

multiples=[i for i in range(30) if i%3==0];
print(multiples);