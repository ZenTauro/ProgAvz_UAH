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
