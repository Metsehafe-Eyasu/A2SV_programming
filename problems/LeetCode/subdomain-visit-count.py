from collections import defaultdict
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        subDomain = defaultdict(int)
        for string in cpdomains:
            value, group = list(map(str, string.split()))
            groupList = group.split('.')
            groupList.reverse()
            length = len(groupList)
            for i in range(1, length + 1):
                dom = groupList[:i]
                dom.reverse()
                dom = '.'.join(dom)
                subDomain[dom] += int(value)
        answer = [str(value) + ' ' + key for key, value in subDomain.items()]
        return answer