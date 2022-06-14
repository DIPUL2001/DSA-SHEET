//QUESTION FROM TRIE;
vector<vector<string> > Anagrams(vector<string>& string_list) 
   {
       unordered_map<string,vector<string>> m;
       for(int i=0;i<string_list.size();i++)
       {
           string temp = string_list[i];
           sort(temp.begin(), temp.end());
           m[temp].push_back(string_list[i]);
       }
       
       vector<vector<string>> v;
       for(auto x : m)
       {
           v.push_back(x.second);
       }
       return v;
   }