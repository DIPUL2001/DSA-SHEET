class Solution {
public:
   int minDeletions(string s) {
  int ans = 0;
  // count each char
  unordered_map<char, int> char_counts;
  for (const char& c : s) char_counts[c]++;
  // make a set to hold which counts we've seen
  unordered_set<int> seen;
  // for each count
  for (auto[k, v] : char_counts) {
    // if we've seen it, decrement it until we haven't
    while (seen.find(v) != seen.end()) {
      v--;
      ans++;
    }
    // add it
    if (v > 0) seen.insert(v);
  }

  return ans;
}
};