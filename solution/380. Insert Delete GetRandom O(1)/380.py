class RandomizedSet:

    def __init__(self):
        self.A = []
        self.pos = {}

    def insert(self, val: int) -> bool:
        if val in self.pos:
            return False
        
        self.A.append(val)
        self.pos[val] = len(self.A) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.pos:
            return False
        
        i = self.pos[val]
        last = self.A[-1]
        self.A[i] = last
        self.pos[last] = i
        self.A.pop()
        del self.pos[val]
        return True

    def getRandom(self) -> int:
        return self.A[random.randint(0, len(self.A) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
