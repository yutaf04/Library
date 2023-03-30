/* ABC275-B) 多倍長整数 外部ライブラリ cpp_int */
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

int main(){
    mp::cpp_int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    std::cout << (a * b * c - d * e * f) % 998244353 << std::endl;
}
