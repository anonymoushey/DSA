
import time
import timeout_decorator

@timeout_decorator.timeout(5, timeout_exception=StopIteration)
def mytest():
	try:
    		print("Start")
    		for i in range(1,10):
        		time.sleep(1)
        		print("{} seconds have passed".format(i))
    	except :
    		return 1;
def a(k):
	if k==1:
		print 10
	else : 
		print 90
a(mytest())