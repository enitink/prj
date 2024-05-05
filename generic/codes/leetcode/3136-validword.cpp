class Solution {
public:
    bool isValid(string word) {
        int wlen = word.length();
        if (wlen < 3)
            return false;
        char vow[5] = {'a', 'e', 'i', 'o', 'u'};
        bool vowpresent = false;
        bool conpresent = false;
        for(int i=0; i<wlen; ++i)
        {
            bool num = (((word[i] - '0') >= 0) && ((word[i] - '0') <= 9));
            int wint = (word[i] | 32);
            int diff = wint - 'a';
            bool validchar = ( (diff >=0) && (diff <= 26) );
            bool validvowel = (((word[i] | 32) == 'a') || ((word[i] | 32) == 'e') || ((word[i] | 32) == 'i') || ((word[i] | 32) == 'o') || ((word[i] | 32) == 'u'));
            
            std::cout << word[i] << " : " << num << validchar << validvowel;
            if ( num || validchar || validvowel)
            {
                vowpresent |= validvowel;
                conpresent |= ((validvowel) ? 0 : validchar);
            }
            else 
                return false;
        }
        return (conpresent && vowpresent);
    }
};