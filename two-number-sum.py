"""
Given an array, find a pair of numbers from the array that add to a specific sum

Optimal Complexity:
    Time: O(n)
    Space: O(n)

    or

    Time: O(nlog(n))
    Space: O(1)
"""

class TwoNumberSum(object):
    def nSqrTimeOneSpace(self, array, expectedSum):
        for i in range(len(array)):
            for j in range(i + 1, len(array)):
                if array[i] + array[j] == expectedSum:
                    return (array[i], array[j])
        return ()

    def nTimeNSpace(self, array, expectedSum):
        memo = set()
        for element in array:
            if expectedSum - element in memo:
                return (element, expectedSum - element)
            else:
                memo.add(element)
        else:
            return ()

    def nLogNTimeOneSpace(self, array, expectedSum):
        array.sort()
        st, en = 0, len(array) - 1
        while st < en:
            intermediateSum = array[st] + array[en]
            if intermediateSum == expectedSum:
                return (array[st], array[en])
            elif intermediateSum < expectedSum:
                st += 1
            else:
                en -= 1
        return ()

# Demo
twoNumberSum = TwoNumberSum()
print(twoNumberSum.nSqrTimeOneSpace([1, 2, 3, 4, 5, 6, 7, 8, 9], 17))
print(twoNumberSum.nTimeNSpace([1, 2, 3, 4, 5, 6, 7, 8, 9], 17))
print(twoNumberSum.nLogNTimeOneSpace([1, 2, 3, 4, 5, 6, 7, 8, 9], 17))
