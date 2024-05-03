class Solution(object):
    def compareVersion(self, version1, version2):
        l1=version1.split('.')
        l2=version2.split('.')
        v1=len(l1);
        v2=len(l2);
        l=0
        r=0
        
        while(l<v1 and r<v2):
            print(int(l1[l]))
            print(int(l2[r]))
            if(int(l1[l])>int(l2[r])):
                return 1;
            elif(int(l1[l])<int(l2[r])):
                return -1;
            else:
                l+=1; 
                r+=1;
        while l<v1:
            if(int(l1[l])!=0):
                return 1;
            l+=1
        while r<v2:
            if(int(l2[r])!=0):
                return -1;
            r+=1
        # if v1>v2:
        #     return 1;
        # if v1<v2:
        #     return -1;
        
        return 0;