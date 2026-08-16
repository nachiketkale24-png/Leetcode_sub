class Solution {
public:
    int romanToInt(string s) {
        int map[26] = {0};
        map['I' - 'A'] = 1;
        map['V' - 'A'] = 5;
        map['X' - 'A'] = 10;
        map['L' - 'A'] = 50;
        map['C' - 'A'] = 100;
        map['D' - 'A'] = 500;
        map['M' - 'A'] = 1000;
        int result = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int currentVal = map[s[i]-'A'];
            if(i<n-1 && currentVal<map[s[i+1]-'A']){
                result-=currentVal;
            }
            else{
                result+=currentVal;
            }
        }
        return result;
    }
};