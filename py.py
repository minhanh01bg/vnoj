ans = 1
for i in range(4, 30):
    ans *= i
with open("input.txt",'w') as f:
    f.write(str(ans))
    
# print(len(str(ans)))
