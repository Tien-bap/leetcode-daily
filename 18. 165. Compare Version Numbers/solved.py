class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split('.')
        v2 = version2.split('.')

        i = 0
        j = 0
        lenv1 = len(v1)
        lenv2 = len(v2)
        while i < lenv1 and j < lenv2:
            a = int(v1[i]) - int(v2[i])
            if a < 0 : return -1
            if a > 0 : return 1
            i+=1
            j+=1

        while i < lenv1:
            a = int(v1[i])
            if a > 0 : return 1
            i+=1 

        while j < lenv2:
            a = int(v2[j])
            if a > 0 : return -1
            j+=1

        return 0
