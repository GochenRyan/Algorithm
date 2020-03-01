# 参考资料：
# https://www.ibm.com/developerworks/cn/linux/l-cn-python-optim/index.html
class Solution:
    def reverseVowels(self, s: str) -> str:
        lStr = list(s)
        i = 0
        j = len(s) - 1
        dVowel = dict.fromkeys(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'], True) 
        while(i < j):
            while(not dVowel.get(lStr[i], False) and i < j):
                i += 1
            while(not dVowel.get(lStr[j], False) and i < j):
                j -= 1
            if i < j:
                lStr[i], lStr[j] = lStr[j], lStr[i]
                i += 1
                j -= 1
        return ''.join(lStr)