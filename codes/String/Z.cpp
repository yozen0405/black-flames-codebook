vector <int> Z;
void calculate_Z(string &s) {
  Z.clear();
  Z.resize(s.size(), 0);
  int l = 0, r = 0;
  for (int i = 1; i < s.size(); i++) {
    if (i <= r) /// 估算下界
      Z[i] = min(Z[i - l], r - i + 1);
    while (i + Z[i] < s.size() && s[i + Z[i]] == s[Z[i]]) /// 暴力檢查 Z(i) 是否可以變更大
      Z[i]++;
    if (i + Z[i] - 1 > r) { /// 更新 "看到最右邊的區間 [l, r]"
      l = i; r = i + Z[i] - 1;
    }
  }
}
void Z_matching(string &a, string &b) {
  string res = "";
  int i = 0;
  for (char ch : b)
    res[i++] = ch;
  res[i++] = '_';
  for (char ch : a)
    res[i++] = ch;
  calculate_Z(res);
  for (int i = 0; i < Z.size(); i++) {
    if (Z[i] == b.size())
      cout << "found a matching start at " << i - b.size() - 1 << "\n";
  }
}