def fib(n):
	if(n>1):
		return n+fib(n-1)	
	elif(n==1):
		return n+1
	else:
		return 0;
		
for _ in range(10000):
	a= fib(100)