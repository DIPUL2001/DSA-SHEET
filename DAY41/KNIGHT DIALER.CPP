class Solution {
public:
   vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
int knightDialer(int N) {
  vector<int> d1(10, 1), d2(10);
  for (; --N > 0; swap(d1, d2))
    for (auto i = 0; i < 10; ++i) 
        d2[i] = accumulate(begin(ms[i]), end(ms[i]), 0, [&](int s, int i) {return (s + d1[i]) % 1000000007;});
  return accumulate(begin(d1), end(d1), 0, [](int s, int n) {return (s + n) % 1000000007;});
}
};