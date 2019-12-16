#include "CLista.hpp"
#include "CNodoLista.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <string>

TEST(CLista, EstaVacia) {
  auto list = CLista<int>{};
  EXPECT_TRUE(list.EstaVacia());
  list.AgregarObjeto(2);
  EXPECT_FALSE(list.EstaVacia());
}

TEST(CLista, CopyConstructor) {
  auto list1 = CLista<int>{};
  list1.AgregarObjeto(1);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(3);
  list1.AgregarObjeto(4);
  list1.AgregarObjeto(5);
  list1.AgregarObjeto(6);
  list1.AgregarObjeto(7);
  list1.AgregarObjeto(8);

  auto list2 = CLista<int>{list1};

  while (list1.TieneMas()) {
    EXPECT_EQ(list1.GetActual(), list2.GetActual());
  }
}


TEST(CLista, AccessOperator) {
  auto list1 = CLista<int>{};
  list1.AgregarObjeto(1);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(3);
  list1.AgregarObjeto(4);
  list1.AgregarObjeto(5);
  list1.AgregarObjeto(6);
  list1.AgregarObjeto(7);
  list1.AgregarObjeto(8);

  try {
    list1[-1];
  } catch(CIndiceIncorrecto &e) {
    cout << e.what() << "\n";
  }

  EXPECT_THROW(list1[-1], CIndiceIncorrecto);
  EXPECT_THROW(list1[9], CIndiceIncorrecto);
  EXPECT_NO_THROW(list1[0]);
  EXPECT_NO_THROW(list1[7]);

  EXPECT_EQ(list1[0], 1);
  EXPECT_EQ(list1[7], 8);
}
