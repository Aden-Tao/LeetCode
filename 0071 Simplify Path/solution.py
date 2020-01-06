#! python3

class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for token in path.split('/'):
            if token in ['', '.']:
                pass
            elif token == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(token)
        return '/' + '/'.join(stack)

if __name__ == "__main__":
    print(Solution().simplifyPath("/a/./b/../../c/"))
    