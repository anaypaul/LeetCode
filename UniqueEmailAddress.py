class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        s = set()
        for i in range(len(emails)):
            print(emails[i])
            x = emails[i]
            print(x)
            if('+' in x):
                index = x.find('+')
                local = x[:index].replace(".","")
                index = x.find('@')
                domain = x[index:]
                email_ = local + domain
                s.add(email_)
            else:
                index = x.find('@')
                local = x[:index].replace(".","")
                domain = x[index:]
                email_ = local + domain
                s.add(email_)
        return len(s)
            