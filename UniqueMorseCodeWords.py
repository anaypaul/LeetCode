class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        ll = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        word = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        mydict = {}
        for i in range(len(ll)):
            mydict[word[i]] = ll[i]
        
        s = set()
        for i in range(len(words)):
            x = ""
            for each in words[i]:
                x += mydict[each]
            s.add(x)
        return len(s)
                