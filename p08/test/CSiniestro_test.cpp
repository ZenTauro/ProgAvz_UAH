#include "CSiniestro.hpp"
#include "CSiniestroNormal.hpp"
#include "CSiniestroUrgente.hpp"
#include <gtest/gtest.h>

TEST(CSiniestro, Initialization) {
  auto base_code = CSiniestroNormal{}.GetCodigo();
  auto sin1 = CSiniestroNormal{};
  auto sin2 = CSiniestroUrgente{TSituacion::internacional};

  EXPECT_EQ(sin1.GetCodigo(), base_code + 1);
  EXPECT_EQ(sin2.GetCodigo(), base_code + 2);
}
