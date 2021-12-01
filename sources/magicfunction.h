#pragma once
#include <iostream>
#include <tuple>

namespace impl {
  using TypeTpl = std::tuple<bool, int, std::string_view>;

  template<typename Arg>
  void magicImpl(TypeTpl& tpl, Arg arg) {
    if constexpr (std::is_same_v<Arg, bool>)
      std::get<0>(tpl) = arg;
    else if constexpr  (std::is_same_v<Arg, int>)
      std::get<1>(tpl) = arg;
    else if constexpr  (std::is_same_v<Arg, std::string_view>)
      std::get<2>(tpl) = arg;
  }

  template<typename Arg, typename... Tail>
  void magicImpl(TypeTpl& tpl, Arg arg, Tail ...tail) {
    if constexpr (std::is_same_v<Arg, bool>)
      std::get<0>(tpl) = arg;
    else if constexpr  (std::is_same_v<Arg, int>)
      std::get<1>(tpl) = arg;
    else if constexpr  (std::is_same_v<Arg, std::string_view>)
      std::get<2>(tpl) = arg;
    magicImpl(tpl, tail...);
  }
} // namespace impl

void do_something(bool a, int b, std::string_view c) {
  std::cout << "boolVar = " << a
            << ", intVar = " << b
            << ", strviewVar = " << c << std::endl;
}

template<typename... Args, typename F = std::enable_if_t<sizeof...(Args) == 3>>
void magicFunction(Args ...args) {
  std::tuple<bool, int, std::string_view> res;
  impl::magicImpl(res, args...);
  auto& [boolVar, intVar, strviewVar] = res;
  do_something(boolVar, intVar, strviewVar);

}
