class Solution(object):
    def countSeniors(self, details):
        return sum([1 for d in details if d[11:13]>'60'])
        