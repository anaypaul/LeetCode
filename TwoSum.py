def twoSum(arr, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mydict = {}
        for i in range(len(arr)):
                mydict[arr[i]] = i

        #print(mydict)
        index = []
        for i in range(len(arr)):
            if mydict.get(target-arr[i]) != None:
                if(i != mydict.get(target-arr[i])):
                    index.append(i)
                    index.append(mydict.get(target-arr[i]))
                    break

        return index
