#include <cstdint>
#include <iostream>

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}
int main()
{
   double da = 1.0;
   double db = 3.0;
   std::cout << max(da, db) << '\n';

   std::int32_t ia = 1;
   std::int32_t ib = 3;
   std::cout << max(ia, ib) << '\n';

   char ca = 'a';
   char cb = 'b';
   std::cout << max(ca, cb) << '\n';

    return 0;
}
