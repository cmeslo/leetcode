class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # 計算每個任務的頻率並找到出現最多的任務的出現次數
        c = Counter(tasks)
        mx = max(c.values())
        
        # 計算出現最多次數的任務有幾個
        mx_cnt = sum(1 for cnt in c.values() if cnt == mx)
        
        # 根據公式計算最少的時間間隔
        interval = (mx - 1) * (n + 1) + mx_cnt
        
        # 最終的結果至少需要是任務列表的長度
        return max(interval, len(tasks))
    
