class Solution:
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        tokens = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F']
        if(':' in IP):
            #IPv6
            bits = IP.split(':')
            if(len(bits) == 8):
                for i in range(len(bits)):
                    x = bits[i]
                    if(len(x)==0):
                        return "Neither"
                    elif(len(x)<=4):
                        for each in x:  
                            if(each in tokens):
                                continue
                            else:
                                return "Neither"
                    else:
                        if(len(x)==1 and x[0]=='0'):
                            continue
                        elif(len(x)>1 and len(x)<5 and x[0]=='0'):
                            for each in x:
                                if(each in tokens):
                                    continue
                                else:
                                    return "Neither"
                        else:
                            return "Neither"
                return "IPv6"
            else:
                return "Neither"
        elif('.' in IP):
            #IPv4
            bits = IP.split('.')
            if(len(bits)==4):
                for i in range(len(bits)):
                    #check for range
                    x = bits[i]
                    try:
                        val = int(x)
                    except ValueError:
                        return "Neither"
                    if( (int(x) < 0 or int(x) > 255) or (len(x) > 1 and x[0] == '0') or(x[0]=='-')):
                        return "Neither"
                return "IPv4"
            else:
                return "Neither"
        else:
            return "Neither"