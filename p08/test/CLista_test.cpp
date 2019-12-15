#include "CLista.hpp"
#include "CNodoLista.hpp"
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
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);
  list1.AgregarObjeto(2);

  auto list2 = CLista<int>{list1};
}
