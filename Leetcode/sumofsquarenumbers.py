# “双指针” + 剪枝
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c < 0:
            return False
        i = 0
        j = int(c ** 0.5)
        while(i <= j):
            if i ** 2 == c - j ** 2:
                return True
            elif i ** 2 < c - j ** 2:
                i += 1
            else:
                j -= 1
        return False

# ------------------------------

# 费马平方和定理
# 一个非负整数 cc 能够表示为两个整数的平方和，当且仅当 cc 的所有形如 4k+34k+3 的质因子的幂次均为偶数。
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c <= 2:
            return True
        
        while c % 2 == 0:
            c /= 2

        n1 = 3
        while n1 * n1 < c:
            count = 0
            while c % n1 == 0:
                c /= n1
                count += 1
            if (n1 % 4 == 3) and (count % 2):
                return False
            n1 += 2
        
        return c % 4 != 3