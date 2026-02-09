class Solution {
public:
    int strStr(string haystack, string needle) {
        int j;
        for (int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                for(j = 1; j < needle.size(); j++){

                    if(haystack[i + j] == needle[j]){
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(j == needle.size()) return i;
            }
        }
        return -1;
        
    }
};