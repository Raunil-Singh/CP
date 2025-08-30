def solve(): 
 n, s = (input()).split()
 n = int(n)

 v = [ i for i in range(1, n+1) ][::-1]
 curr = s[0]
 count = 0
 counts = [] 
 s = s + '1' 
 for c in s:
     if c == curr:
         count+=1
     else: 
         if curr == '>':
             count *= -1 
         counts.append(count)
         curr = c
         count = 1
 pos = 0
 for num in counts :
     if num > 0:
         v[pos: pos+num+1] = v[pos:pos+num+1][::-1]
     pos+= abs(num)
 print(*v) 
 
 v = [ i for i in range(1, n+1) ]
 curr = s[0]
 count = 0
 counts = [] 
 s = s + '1' 
 for c in s:
     if c == curr:
         count+=1
     else: 
         if curr == '<':
             count *= -1 
         counts.append(count)
         curr = c
         count = 1
 pos = 0
 for num in counts :
     if num > 0:
         v[pos: pos+num+1] = v[pos:pos+num+1][::-1]
     pos+= abs(num)
 print(*v) 



t = int(input()) 
for _ in range(t): 
 solve()