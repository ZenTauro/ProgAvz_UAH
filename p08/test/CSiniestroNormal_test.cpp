#include "CSiniestro.hpp"
#include "CSiniestroNormal.hpp"
#include <gtest/gtest.h>

TEST(CSiniestroNormal, DefaultConstructor) {
  CSiniestroNormal s{"Rotura de tambor"};

  s.Presupuestar();
  EXPECT_EQ(s.GetPresupuesto(), 0.5);
}
