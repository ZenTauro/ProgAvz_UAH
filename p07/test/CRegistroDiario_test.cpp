#include "CCliente.hpp"
#include "CEmpleado.hpp"
#include "CRegistroDiario.hpp"
#include "types.hpp"
#include <exception>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

TEST(CRegistroDiario, Constructors) {
  EXPECT_THROW({ CRegistroDiario{-1}; }, std::invalid_argument);
  EXPECT_THROW({ CRegistroDiario{0}; }, std::invalid_argument);
  EXPECT_NO_THROW({ CRegistroDiario{}; });

  auto reg1 = CRegistroDiario{20},
       reg2 = CRegistroDiario{};

  EXPECT_EQ(reg1.GetMaxSize(), 20);
  EXPECT_EQ(reg2.GetMaxSize(), DEFAULT_REGSIZE);
  EXPECT_EQ(reg1.Length(), 0);
  EXPECT_EQ(reg2.Length(), 0);
}

TEST(CRegistroDiario, Add) {
  auto reg = CRegistroDiario{};
  auto emp = CEmpleado{"Pepe"};
  auto client = CCliente{"Juan"};

  reg.Add(client);
  EXPECT_EQ(reg.Length(), 1);
}
