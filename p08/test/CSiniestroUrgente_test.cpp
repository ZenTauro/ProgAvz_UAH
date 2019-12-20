#include "CSiniestro.hpp"
#include "CSiniestroUrgente.hpp"
#include <gtest/gtest.h>

TEST(CSiniestroUrgente, DefaultConstructor) {
  auto c = CSiniestroUrgente{TSituacion::local};
  EXPECT_EQ(c.Presupuestar(), 0);
}
