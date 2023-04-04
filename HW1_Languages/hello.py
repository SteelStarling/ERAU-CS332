# command line arguments are in sys.argv 
import sys  
def hello(name): 
 print("Hello " + name) 
 
print("Hello Python!") 
for arg in sys.argv: 
 hello(arg) 
