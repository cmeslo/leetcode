class Solution:
    def maxDifference(self, s: str) -> int:
        count = Counter(s)
        max_odd = max((v for v in count.values() if v % 2), default=0)
        min_even = min((v for v in count.values() if not v % 2), default=len(s))
        return max_odd - min_even

# max((v for v in count.values() if v % 2), default=0)
# max([v for v in count.values() if v % 2], default=0)
# 這兩種寫法哪個比較好?

# 1. 生成器表達式（推薦）
# max((v for v in count.values() if v % 2), default=0)
# > 優點：更節省記憶體：生成器是惰性求值的，不會一次性生成整個列表，特別適合處理大數據。
# > 缺點：如果多次遍歷生成器，需要重新計算（但這裡 max() 只遍歷一次，所以沒影響）。

# 2. 列表推導式
# max([v for v in count.values() if v % 2], default=0)
# > 優點：如果後續還要多次使用這個列表，列表推導式可以避免重複計算。
# > 缺點：佔用更多記憶體，因為會先構建完整的列表，再傳給 max()。
