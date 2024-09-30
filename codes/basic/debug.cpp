void debug() { cout << endl; }
template <typename T, typename ...U>
void debug(T i, U ...j) { cout << i << ' ', debug(j...); }
#define test(x...) debug("[" + string(x) + "]", x)