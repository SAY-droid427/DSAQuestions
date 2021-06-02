class Solution {
public:
    string freqAlphabets(string s) {
      string m="";
      for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] == '#') {
          char t = (s[i-2] - '0')*10 + s[i-1] + 48;
          m += t;
          i=i-2;
        }
        else {
          char t = s[i] + 48;
          m += t;
        }  
      }
      reverse(m.begin(),m.end());
      return m;    
    }
};