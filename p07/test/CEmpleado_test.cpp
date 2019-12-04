#include "CEmpleado.hpp"
#include "CHora.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(CEmpleado, Show) {
  auto empleado = CEmpleado{"Alex", "Ciencias", 12};

  EXPECT_NO_THROW(empleado.show());
}
