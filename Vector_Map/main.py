import vector_map
a=vector_map.VectorInt()
a.extend([1,3,4,5])
print("vector before inc ",a)
vector_map.inc(a,3)
print("vector after inc ",a)
a=vector_map.Map()
a[1]=3
print("map before inc ",a)
vector_map.inc(a,3) 
print("map after inc ",a)



