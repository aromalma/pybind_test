class py_:
  def __init__(self,a):
    self.a=a
    self.n=a.shape[0]
  def heapify( self, n, i):
    maxx = i 
    left_child = 2 * i + 1 
    right_child = 2 * i + 2 
    if left_child  < n and self.a[i] < self.a[left_child]:
      maxx = left_child 
    if right_child  < n and self.a[maxx] < self.a[right_child]:
      maxx= right_child

    if maxx != i:
      self.a[i],self.a[maxx] = self.a[maxx],self.a[i] 
      self.heapify( n, maxx)
  def heapsort(self):

    for i in range(int(self.n/2)-1, -1, -1):
      self.heapify( self.n, i)

    for i in range(self.n-1, 0, -1):
      self.a[i], self.a[0] = self.a[0], self.a[i] 
      # print(self.a)
      self.heapify(i, 0)

