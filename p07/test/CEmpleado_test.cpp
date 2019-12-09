#include "CEmpleado.hpp"
#include "CHora.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(CEmpleado, Show) {
  auto empleado = CEmpleado{"Alex", "Ciencias", 12};

  EXPECT_NO_THROW(empleado.show());
}

TEST(CEmpleado, Clone) {
  auto cliente1 = new CEmpleado{"Pepe", "Computacion"};
  auto cliente2 = cliente1->Clone();

  EXPECT_EQ(cliente1->GetCategoria(), dynamic_cast<CEmpleado *>(cliente2)->GetCategoria());

  delete cliente1;
  delete cliente2;
}
