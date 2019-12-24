#!python3

class Solution:

    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2: return s
        res = ["" for _ in range(numRows)]
        i, flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1: flag = -flag
            i += flag
        return "".join(res)

if __name__ == "__main__":
    print(Solution().convert("LEETCODEISHIRING", 3) == "LCIRETOESIIGEDHN")
    print(Solution().convert("LEETCODEISHIRING", 4) == "LDREOEIIECIHNTSG")