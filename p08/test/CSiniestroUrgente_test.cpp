#include "CSiniestro.hpp"
#include "CSiniestroUrgente.hpp"
#include <gtest/gtest.h>

TEST(CSiniestroUrgente, DefaultConstructor) {
  auto c = CSiniestroUrgente{TSituacion::local};
  c.Presupuestar();
  EXPECT_EQ(c.GetPresupuesto(), 25);
}
