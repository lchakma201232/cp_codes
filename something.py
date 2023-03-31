class Test:
    x,y,z=0,0,0
    def __init__(self,x,y,z):
        self.x=x;
        self.y=y
        self.z=z
        
    def func(self):
        print(self.x)
        
class P(Test):
    def __init__(self,x,y,z,w):
       super().__init__(x,y,z)
       self.w=w
        
    def func(self):
        print(self.x,self.y,self.z)