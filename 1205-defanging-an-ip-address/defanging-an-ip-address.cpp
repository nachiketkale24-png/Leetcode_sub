class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.size();
        string str_ans="";
        for(int i=0;i<n;i++){
            if(address[i]=='.'){
                str_ans+="[.]";
            }
            else{
                str_ans+=address[i];
            }
        }
        return str_ans;
    }
};