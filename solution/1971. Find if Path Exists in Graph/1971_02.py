class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        father = [0] * n
        for i in range(n):
            father[i] = i
        
        def find_father(x):
            if x != father[x]:
                father[x] = find_father(father[x])
            return father[x]
        
        def merge(a, b):
            a, b = find_father(a), find_father(b)
            if a < b:
                father[b] = a
            else:
                father[a] = b
        
        for e in edges:
            merge(e[0], e[1])
            
        return find_father(source) == find_father(destination)
