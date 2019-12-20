#include "CContrato.hpp"
#include "CSiniestroNormal.hpp"
#include "CSiniestroUrgente.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(CContrato, DefaultConstructor) {
  auto c = CContrato{939};
  EXPECT_EQ(c.GetNumSerie(), 939);
}

TEST(CContrato, CopyConstructor) {
  auto c = CContrato{939};
  auto d = CContrato{c};

  auto sin_nom = CSiniestroNormal();
  auto sin_total = CSiniestroUrgente(TSituacion::local);

  c.AgregarSiniestro(sin_nom);
  c.AgregarSiniestro(sin_total);

  EXPECT_EQ(c.GetPoliza(), d.GetPoliza());
  EXPECT_EQ(c.GetFechaFin(), d.GetFechaFin());
  EXPECT_EQ(c.GetNumSerie(), d.GetNumSerie());
  EXPECT_EQ(c.GetValorCom(), d.GetValorCom());
  EXPECT_EQ(c.GetDescripcion(), d.GetDescripcion());

}

TEST(CContrato, Show) {
  auto c = CContrato{939};
  cout << c;
}

TEST(CContrato, AgregarSiniestro) {
  auto c = CContrato{939};
  auto sin_nom = CSiniestroNormal();
  auto sin_total = CSiniestroUrgente(TSituacion::local);

  c.AgregarSiniestro(sin_nom);
  c.AgregarSiniestro(sin_total);
}
