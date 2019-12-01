#include "CCliente.hpp"
#include "CHora.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(CCliente, DefaultConstructor) {
  auto cliente = CCliente{};

  EXPECT_EQ(cliente.ObtenerEdad(), 0);
  EXPECT_EQ(cliente.ObtenerNombre(), string{""});
  EXPECT_EQ(cliente.GetDNI(), string{""});
  EXPECT_EQ(cliente.ObtenerNacio(), CHora{});
}

TEST(CCliente, Arg1Constructor) {
  auto cliente = CCliente{"Pepe"};

  EXPECT_EQ(cliente.ObtenerEdad(), 0);
  EXPECT_EQ(cliente.ObtenerNombre(), string{"Pepe"});
  EXPECT_EQ(cliente.GetDNI(), string{""});
  EXPECT_EQ(cliente.ObtenerNacio(), CHora{});
}

TEST(CCliente, Arg2Constructor) {
  auto cliente = CCliente{"Pepe", 43};

  EXPECT_EQ(cliente.ObtenerEdad(), 43);
  EXPECT_EQ(cliente.ObtenerNombre(), string{"Pepe"});
  EXPECT_EQ(cliente.GetDNI(), string{""});
  EXPECT_EQ(cliente.ObtenerNacio(), CHora{});
}

TEST(CCliente, Arg3Constructor) {
  auto cliente = CCliente{"Pepe", 43, CHora{11}};

  EXPECT_EQ(cliente.ObtenerEdad(), 43);
  EXPECT_EQ(cliente.ObtenerNombre(), string{"Pepe"});
  EXPECT_EQ(cliente.GetDNI(), string{""});
  EXPECT_EQ(cliente.ObtenerNacio(), CHora{11});
}

TEST(CCliente, Arg4Constructor) {
  auto cliente = CCliente{"Pepe", 43, CHora{11}, "2341529M"};

  EXPECT_EQ(cliente.ObtenerEdad(), 43);
  EXPECT_EQ(cliente.ObtenerNombre(), string{"Pepe"});
  EXPECT_EQ(cliente.GetDNI(), string{"2341529M"});
  EXPECT_EQ(cliente.ObtenerNacio(), CHora{11});
}
