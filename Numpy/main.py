import time
import numpy as np
import random

from  cpp_sort import cpp_
from py_sort import py_
random.seed(1)
l=[x for x in range(99999)]
random.shuffle(l)
# print(l)
a1=np.array(l,dtype=np.int32)
a2=np.array(l,dtype=np.int32)
print("after shuffling : ",a1)
t=time.time()
CPP=cpp_(a1)
CPP.heapsort()
print('time required by cpp in sec: ',time.time()-t)
print('sorted:',a1,", size:",CPP.array_size)
t=time.time()
PY=py_(a2)
PY.heapsort()
print('time required by py in sec: ',time.time()-t)
print('sorted:',a2,", size:",PY.n)
