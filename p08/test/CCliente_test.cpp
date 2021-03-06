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

TEST(CCliente, Operator) {
  const int MAX_CLIENTES = 10;
  CCliente *seguros = new CCliente[30]{};
  long total = 0;

  for (uint64_t i=0; i<MAX_CLIENTES; i++)
    total += seguros[i];

  EXPECT_EQ(total, 10);

  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};

  seguros[0].AgregarContrato(contrato1).AgregarContrato(contrato2);

  for (uint64_t i = 0; i < MAX_CLIENTES; i++)
    total += seguros[i];

  EXPECT_EQ(total, 22);

  delete[] seguros;
}
