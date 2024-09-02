class Solution:
    def largestPalindrome(self, n: int, k: int) -> str:
        lar = (10**n) - 1
        sm = 10**(n-1)
        div = int(lar / k)
        st = 0
        lar = k * div

        while (div >= st):
            i = div + st
            if k * i >= sm:
                num_str = str(k*i)
                if num_str == num_str[::-1]:
                    return num_str

        return "0"

solution = Solution()
result = solution.largestPalindrome(9, 5)
print(result)