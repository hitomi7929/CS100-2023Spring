#include "dynarray.hpp"
#include <algorithm>
#include <iostream>

void reverse(Dynarray &a) {
  for (int i = 0, j = a.size() - 1; i < j; ++i, --j)
    std::swap(a.at(i), a.at(j));
}

void print(const Dynarray &a) {
  std::cout << '[';
  if (!a.empty()) {
    for (std::size_t i = 0; i + 1 < a.size(); ++i)
      std::cout << a.at(i) << ", ";
    std::cout << a.at(a.size() - 1);
  }
  std::cout << ']' << std::endl;
}

int main() {
  // int n;
  // std::cin >> n;
  const int array[10] = {19, 64, 10, 96, 67, 6, 17, 86, 7, 29};
  // Dynarray arr;
  // for (int i = 0; i != n; ++i)
    // std::cin >> arr.at(i);
  Dynarray arr(array + 3, array + 7);
  Dynarray arr1{arr};
  // arr.at(3) = 0;
  reverse(arr1);
  print(arr1);
  arr1.at(0) = 1;
  print(arr1);
  print(arr);
  Dynarray copy = arr;
  copy.at(0) = 42;
  std::cout << arr.at(0) << '\n'
            << copy.at(0) << std::endl;
  return 0;
}