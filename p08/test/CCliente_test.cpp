#include "CCliente.hpp"
#include "CContrato.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(CCliente, DefaultConstructor) {
  auto contrato = CContrato{666};
  auto cli = CCliente{}, cli2 = CCliente{"JuanPepe", contrato};

  ASSERT_EQ(cli.GetNombre(), "Sin Nombre");
  ASSERT_EQ(cli2.GetNombre(), "JuanPepe");
}

TEST(CCliente, AgregarContrato) {
  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};
  auto cli = CCliente{"JuanPepe", contrato1};
  cli.AgregarContrato(contrato2);
}
