#include "CCliente.hpp"
#include "CEmpleado.hpp"
#include "CRegistroDiario.hpp"
#include "types.hpp"
#include <exception>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

TEST(CRegistroDiario, Constructors1) {
  EXPECT_THROW({ CRegistroDiario{-1}; }, std::invalid_argument);
  EXPECT_THROW({ CRegistroDiario{0}; }, std::invalid_argument);
  EXPECT_NO_THROW({ CRegistroDiario{}; });

  auto reg1 = CRegistroDiario{20};

  EXPECT_EQ(reg1.GetMaxSize(), 20);
  EXPECT_EQ(reg1.Length(), 0);
}

TEST(CRegistroDiario, Constructors2) {
  auto reg2 = CRegistroDiario{};
  EXPECT_EQ(reg2.GetMaxSize(), DEFAULT_REGSIZE);
  EXPECT_EQ(reg2.Length(), 0);
} TEST(CRegistroDiario, Add) {
  auto reg = CRegistroDiario{};
  auto emp = CEmpleado{"Pepe"};
  auto client = CCliente{"Juan"};

  reg.Add(client);
  EXPECT_EQ(reg.Length(), 1);
  reg.Add(emp);
  EXPECT_EQ(reg.Length(), 2);

  EXPECT_EQ(reg[0].ObtenerNombre(), client.ObtenerNombre());
  EXPECT_EQ(reg[1].ObtenerNombre(), emp.ObtenerNombre());
}

TEST(CRegistroDiario, Copy) {
  auto reg = CRegistroDiario{};
  auto reg2 = CRegistroDiario{};
  auto emp1 = CEmpleado{"Pepe"};
  auto client1 = CCliente{"Juan"};
  auto emp2 = CEmpleado{"Alisa"};
  auto client2 = CCliente{"Tati"};

  reg.Add(client1);
  reg.Add(emp1);
  reg.Add(client2);
  reg.Add(emp2);

  reg2 = reg;
  auto reg3 = reg;

  for(uint8_t i=0; i<reg.Length(); i++) {
    EXPECT_EQ(reg[i].ObtenerNombre(), reg2[i].ObtenerNombre());
    EXPECT_EQ(reg[i].ObtenerNombre(), reg3[i].ObtenerNombre());
    EXPECT_NE(&(reg[i]), &(reg2[i]));
    EXPECT_NE(&(reg[i]), &(reg3[i]));
  }
}

TEST(CRegistroDiario, SelfCopy) {
  auto reg = CRegistroDiario{};

  EXPECT_THROW({reg = reg;}, std::invalid_argument);
}

#if defined WITH_VECTORS
#else
TEST(CRegistroDiario, OverflowAdd) {
  auto reg = CRegistroDiario{1};
  auto cli = CCliente{"juan"};
  auto emp = CEmpleado{"Titi"};

  EXPECT_EQ(reg.Length(), 0);
  EXPECT_TRUE(reg.Add(cli));
  EXPECT_EQ(reg.Length(), 1);
  EXPECT_FALSE(reg.Add(cli));
  EXPECT_EQ(reg.Length(), 1);
  EXPECT_FALSE(reg.Add(emp));
  EXPECT_EQ(reg.Length(), 1);
}
#endif

TEST(CRegistroDiario, FindByName) {
  auto reg = CRegistroDiario{};
  auto emp1 = CEmpleado{"Pepe"};
  auto client1 = CCliente{"Juan"};
  auto emp2 = CEmpleado{"Alisa"};
  auto client2 = CCliente{"Tati"};

  reg.Add(client1);
  reg.Add(emp1);
  reg.Add(client2);
  reg.Add(emp2);

  EXPECT_EQ(reg.FindByName("Pepe").ObtenerNombre(), emp1.ObtenerNombre());
  EXPECT_EQ(reg.FindByName("Pepe").ObtenerEdad(), emp1.ObtenerEdad());

  EXPECT_EQ(reg.FindByName("Alisa").ObtenerNombre(), emp2.ObtenerNombre());
  EXPECT_EQ(reg.FindByName("Alisa").ObtenerEdad(), emp2.ObtenerEdad());

  EXPECT_EQ(reg.FindByName("Juan").ObtenerNombre(), client1.ObtenerNombre());
  EXPECT_EQ(reg.FindByName("Juan").ObtenerEdad(), client1.ObtenerEdad());

  EXPECT_EQ(reg.FindByName("Tati").ObtenerNombre(), client2.ObtenerNombre());
  EXPECT_EQ(reg.FindByName("Tati").ObtenerEdad(), client2.ObtenerEdad());

  EXPECT_THROW(reg.FindByName("Felicidad"), invalid_argument);
}
