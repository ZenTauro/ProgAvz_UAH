#include "CContrato.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(CContrato, DefaultConstructor) {
  auto c = CContrato{939};
  EXPECT_EQ(c.GetNumSerie(), 939);
}

TEST(CContrato, Show) {
  auto c = CContrato{939};
  cout << c;
}
