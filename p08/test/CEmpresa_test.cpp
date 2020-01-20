#include "CCliente.hpp"
#include "CEmpresa.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(CEmpresa, DefaultConstructor) {
  auto empresa1 = CEmpresa<CCliente>{};
}

TEST(CEmpresa, CopyConstructor) {
  auto empresa1 = CEmpresa<CCliente>{};
  auto empresa2 = CEmpresa<CCliente>{empresa1};
}

TEST(CEmpresa, Add) {
  auto empresa1 = CEmpresa<CCliente>{};

  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};
  auto cli = CCliente{"JuanPepe", contrato1};
  cli.AgregarContrato(contrato2);

  empresa1.AgregarElemento(cli);
  EXPECT_EQ(empresa1[0], cli);
}

TEST(CEmpresa, OperatorEq) {
  auto empresa1 = CEmpresa<CCliente>{};

  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};
  auto cli = CCliente{"JuanPepe", contrato1};
  cli.AgregarContrato(contrato2);

  empresa1.AgregarElemento(cli);
  auto empresa2 = empresa1;
  EXPECT_EQ(empresa1[0], empresa2[0]);
}

TEST(CEmpresa, InOfRange) {
  auto empresa1 = CEmpresa<CCliente>{};

  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};
  auto cli = CCliente{"JuanPepe", contrato1};
  cli.AgregarContrato(contrato2);

  empresa1.AgregarElemento(cli);
  EXPECT_NO_THROW(empresa1[0]);
}

TEST(CEmpresa, OutOfRange) {
  auto empresa1 = CEmpresa<CCliente>{};

  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};
  auto cli = CCliente{"JuanPepe", contrato1};
  cli.AgregarContrato(contrato2);

  empresa1.AgregarElemento(cli);
  EXPECT_THROW(empresa1[1], std::out_of_range);
}

TEST(CEmpresa, CopyAdd) {
  auto empresa1 = CEmpresa<CCliente>{};

  auto contrato1 = CContrato{666};
  auto contrato2 = CContrato{666};
  auto cli = CCliente{"JuanPepe", contrato1};
  cli.AgregarContrato(contrato2);

  empresa1.AgregarElemento(cli);
  auto empresa2 = CEmpresa<CCliente>{empresa1};
  EXPECT_EQ(empresa1[0], empresa2[0]);
}

TEST(CEmpresa, Deserial) {
  auto empresa = CEmpresa<CCliente>{};
  cempresa::from_file(empresa, "clientes.txt");

  uint32 i = 0;
  try {
    while(1) {
      cout << empresa[i] << "\n";
      i++;
    }
  } catch (std::out_of_range &e) {
    cout << endl;
  }
}
