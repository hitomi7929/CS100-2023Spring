#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <math.h>
#include <stdexcept>
#include <string>

class Polynomial {
  friend bool operator== (const Polynomial &lhs, const Polynomial &rhs);
  friend bool operator!= (const Polynomial &lhs, const Polynomial &rhs);
  friend Polynomial operator- (const Polynomial &a);
  friend Polynomial operator+ (const Polynomial &lhs, const Polynomial &rhs);
  friend Polynomial operator- (const Polynomial &lhs, const Polynomial &rhs);
  friend Polynomial operator* (const Polynomial &lhs, const Polynomial &rhs);
  friend std::ostream &operator<< (std::ostream &, const Polynomial &);

  // `m_coeffs` stores the coefficients.
  // Note: This is not the unique correct implementation.
  // For example, you may separate the constant term from others,
  // and store the constant term using another variable.
  // std::vector<double> m_coeffs;

public:
  std::vector<double> m_coeffs;
  Polynomial() : m_coeffs({0}) {}

  template <typename InputIterator>
  Polynomial(InputIterator begin, InputIterator end) : m_coeffs(begin, end) { adjust(); }

  explicit Polynomial(const std::vector<double> &vec) : m_coeffs(std::move(vec)) { adjust(); }
  explicit Polynomial(const std::vector<double> &&vec) : m_coeffs(std::move(vec)) { adjust(); }

  Polynomial(const Polynomial& other) : m_coeffs(other.m_coeffs) { adjust(); }
  Polynomial& operator = (const Polynomial& other) {
    m_coeffs = other.m_coeffs;
    adjust();
    return *this;
  }

  Polynomial(Polynomial &&other) noexcept: m_coeffs(std::move(other.m_coeffs)) {
    adjust();
    // other.m_coeffs = {0};
  }
  Polynomial &operator = (Polynomial &&other) noexcept {
    if (this != &other) {
      m_coeffs = other.m_coeffs;
      adjust();
      other.m_coeffs = {0};
    }
    return *this;
  }

  ~Polynomial() = default;

  static auto isZero(double x) {
    static constexpr auto eps = 1e-8;
    return x < eps && -x < eps;
  }

  // Remove trailing zeros, to ensure that the coefficient of the term with
  // the highest order is non-zero.
  // Note that a polynomial should have at least one term, which is the
  // constant. It should not be removed even if it is zero.
  // If m_coeffs is empty, adjust() should also insert a zero into m_coeffs.
  void adjust() {
    // YOUR CODE HERE
    while (!m_coeffs.empty() && isZero(m_coeffs.back())) {
      m_coeffs.pop_back();
    }
    if (m_coeffs.empty()) {
      m_coeffs.push_back(0);
    }
  }

  // Other members ...
  std::size_t deg() const {
    return m_coeffs.size() - 1;
  }

  double operator[] (std::size_t n) {
    if (n >= m_coeffs.size()) {
      throw std::out_of_range{"Polynomial index out of range!"};
    }
    return m_coeffs[n];
  }
  double operator[] (std::size_t n) const {
    if (n >= m_coeffs.size()) {
      throw std::out_of_range{"Polynomial index out of range!"};
    }
    return m_coeffs[n];
  }

  void setCoeff(std::size_t i, double c) {
    if (i < m_coeffs.size()) {
      m_coeffs[i] = c;
      adjust();
    } else if (i >= m_coeffs.size() && !isZero(c)) {
      m_coeffs.resize(i + 1, 0);
      m_coeffs[i] = c;
    }
  }

  double operator() (double x) const {
    double multiplier = x;
    double ans = m_coeffs[0];
    for (std::size_t i = 1; i < m_coeffs.size(); i++) {
      ans += m_coeffs[i] * multiplier;
      multiplier *= x;
    }
    return ans;
  }

   Polynomial &operator-= (const Polynomial &rhs) {
    std::size_t degree_min = m_coeffs.size() - 1 < rhs.deg() ? m_coeffs.size() - 1 : rhs.deg();
    std::size_t degree_max = m_coeffs.size() - 1 > rhs.deg() ? m_coeffs.size() - 1 : rhs.deg();
    for (std::size_t i = 0; i <= degree_min; i++) {
      m_coeffs[i] -= rhs[i];
    }
    if (m_coeffs.size() - 1 < rhs.deg()) {
      m_coeffs.resize(rhs.deg() + 1, 0);
      for (std::size_t i = degree_min + 1; i <= degree_max; i++) {
        m_coeffs[i] -= rhs[i];
      }
    }
    adjust();
    return *this;
  }

  Polynomial &operator+= (const Polynomial &rhs) {
    std::size_t degree_min = m_coeffs.size() - 1 < rhs.deg() ? m_coeffs.size() - 1 : rhs.deg();
    std::size_t degree_max = m_coeffs.size() - 1 > rhs.deg() ? m_coeffs.size() - 1 : rhs.deg();
    for (std::size_t i = 0; i <= degree_min; i++) {
      m_coeffs[i] += rhs[i];
    }
    if (m_coeffs.size() - 1 < rhs.deg()) {
      m_coeffs.resize(rhs.deg() + 1, 0);
      for (std::size_t i = degree_min + 1; i <= degree_max; i++) {
        m_coeffs[i] += rhs[i];
      }
    }
    adjust();
    return *this;
  }

  Polynomial &operator*= (const Polynomial &rhs) {
    Polynomial ans;
    std::size_t degree = m_coeffs.size() + rhs.deg();
    for (std::size_t i = 0; i < degree; i++) {
      double coefficient = 0;
      std::size_t size = i < m_coeffs.size() - 1 ? i : m_coeffs.size() - 1;
      for (std::size_t k = 0; k <= size; k++) {
        if (i - k <= rhs.deg()) {
          coefficient += m_coeffs[k] * rhs[i - k];
        }
      }
      ans.setCoeff(i, coefficient);
    }
    *this = ans;
    adjust();
    return *this;
  }

  Polynomial derivative() const {
    Polynomial ans;
    ans.m_coeffs.resize(m_coeffs.size(), 0);
    for (std::size_t i = 1; i < m_coeffs.size(); i++) {
      ans.m_coeffs[i - 1] = m_coeffs[i] * i;
    }
    ans.adjust();
    return ans;
  }

  Polynomial integral() const {
    Polynomial ans;
    ans.m_coeffs.resize(m_coeffs.size() + 1, 0);
    for (std::size_t i = 0; i < m_coeffs.size(); i++) {
      ans.m_coeffs[i + 1] = m_coeffs[i] / (i + 1);
    }
    ans.adjust();
    return ans;
  }
};

// Add non-member functions if you need.
bool operator== (const Polynomial &lhs, const Polynomial &rhs) {
  if (lhs.deg() == rhs.deg()) {
    for (std::size_t i = 0; i <= lhs.deg(); i++) {
      if (!Polynomial::isZero(lhs[i] - rhs[i])) {
        return false;
      }
    }
    return true;
  }
  return false;
}
bool operator!= (const Polynomial &lhs, const Polynomial &rhs) {
  return !(lhs == rhs);
}

Polynomial operator- (const Polynomial &a) {
  Polynomial ans;
  ans.m_coeffs.resize(a.deg() + 1, 0);
  for (std::size_t i = 0; i <= a.deg(); i++) {
    ans.m_coeffs[i] -= a[i];
  }
  ans.adjust();
  return ans;
}

Polynomial operator+ (const Polynomial &lhs, const Polynomial &rhs) {
  return Polynomial(lhs) += rhs;
}

Polynomial operator- (const Polynomial &lhs, const Polynomial &rhs) {
  return Polynomial(lhs) -= rhs;
}

Polynomial operator* (const Polynomial &lhs, const Polynomial &rhs) {
  return Polynomial(lhs) *= rhs;
}

std::ostream &operator<< (std::ostream &os, const Polynomial &r) {
  std::string blank = " ";
    for (auto i : r.m_coeffs) {
        os << std::to_string(i) << blank;
    }
    return os;
}

#endif // POLYNOMIAL_HPP