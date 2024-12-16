#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N, K;
vl male, female;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> K;
  male = vl(7, 0);
  female = vl(7, 0);

  for (auto i = 0; i < N; ++i) {
    ll S, Y;
    cin >> S >> Y;

    if (S == 0) {
      female[Y] += 1;
    } else {
      male[Y] += 1;
    }
  }

  ll ans = 0;
  {  // 1, 2
    auto x = male[1] + male[2] + female[1] + female[2];
    ans += (x + K - 1) / K;
  }
  {  // 3, 4 m
    auto x = male[3] + male[4];
    ans += (x + K - 1) / K;
  }
  {  // 3, 4 f
    auto x = female[3] + female[4];
    ans += (x + K - 1) / K;
  }
  {  // 5, 6 m
    auto x = male[5] + male[6];
    ans += (x + K - 1) / K;
  }
  {  // 5, 6 f
    auto x = female[5] + female[6];
    ans += (x + K - 1) / K;
  }

  cout << ans;

  return 0;
}