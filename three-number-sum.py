"""
Given an array, find triplets of numbers from the array that add to a specific sum

Optimal Complexity:
    Time: O(n^2)
    Space: O(n)
"""

class ThreeNumberSum(object):
    def nCubeTimeOneSpace(self, array, expectedSum):
        ans = set()
        for i in range(len(array)):
            for j in range(i + 1, len(array)):
                for k in range(j + 1, len(array)):
                    if array[i] + array[j] + array[k] == expectedSum:
                        ans.add(tuple(sorted([array[i], array[j], array[k]])))
        return sorted(map(lambda x: list(x), ans))               

    def nSqrTimeNSpace(self, array, targetSum):
        reduced_array = []
        for i in array:
            reduced_array.append(targetSum - i)
        ans = set()
        for i in range(len(reduced_array)):
            intermediateSum = reduced_array[i]
            memo = set()
            for j in array:
                if intermediateSum - j == j or intermediateSum - j == array[i] or array[i] == j:
                    continue
                if intermediateSum - j in memo:
                    ans.add(tuple(sorted([array[i], j, intermediateSum - j])))
                else:
                    memo.add(j)
        return sorted(map(lambda x: list(x), ans))
    
    def nSrqTimeNSpaceWith2Pointer(self, array, targetSum):
        array.sort()
        ans = []
        for i in range(len(array)):
            st, en = i+1, len(array) - 1
            while st < en:
                intermediateSum = array[i] + array[st] + array[en]
                if intermediateSum == targetSum:
                    ans.append([array[i], array[st], array[en]])
                    st += 1
                    en -= 1
                    # only st += 1 or en -= 1 would work, but this will require an 
                    # additional iteration (as all numbers are distinct)
                elif intermediateSum < targetSum:
                    st += 1
                else:
                    en -= 1
        return ans


# Demo
threeNumberSum = ThreeNumberSum()
print(threeNumberSum.nCubeTimeOneSpace([1, 2, 3, 4, 5, 6, 7, 8, 9, 15], 18))
print(threeNumberSum.nSqrTimeNSpace([1, 2, 3, 4, 5, 6, 7, 8, 9, 15], 18))
print(threeNumberSum.nSrqTimeNSpaceWith2Pointer([1, 2, 3, 4, 5, 6, 7, 8, 9, 15], 18))
