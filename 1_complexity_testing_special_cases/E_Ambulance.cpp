#include <bits/stdc++.h>

int main() {
  int k1, m, k2, p2, n2;
  std::cin >> k1 >> m >> k2 >> p2 >> n2;
  int vp = 0, vn = 0, p1 = -1, n1 = -1;
  for (int i = 1; i <= 1000; i++) {
    int inp = m * i;
    int tp = ((k2 - 1) / inp);
    tp++;
    int tk = k2 - (tp - 1) * inp;
    int tn = ((tk - 1) / i);
    tn++;
    if (tp == p2 && tn == n2) {
      tp = ((k1 - 1) / inp);
      tp++;
      tk = k1 - (tp - 1) * inp;
      tn = ((tk - 1) / i);
      tn++;
      if (n1 == -1) {
        n1 = tn;
        vn = 1;
      }
      if (p1 == -1) {
        p1 = tp;
        vp = 1;
      }
      if ((vp > 0) && (tp != p1)) {
        vp++;
      }
      if ((vn > 0) && (tn != n1)) {
        vn++;
      }
    }
  }
  if (vp == 0) {
    std::cout << "-1 ";
  }
  if (vp > 1) {
    std::cout << "0 ";
  }
  if (vp == 1) {
    std::cout << p1 << " ";
  }
  if (vn == 0) {
    std::cout << "-1";
  }
  if (vn > 1) {
    std::cout << 0;
  }
  if (vn == 1) {
    std::cout << n1;
  }
  return 0;
}