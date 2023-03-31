arr=[1,5,8,9,10,17,17,20,24,30]
def fn(n):
  if n==0:
    return 0
  mm=0
  for i in range(1,n+1):
    mm=max(mm,arr[i-1]+fn(n-i))
  return mm
print(fn(10))