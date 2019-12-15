#include "CNodoLista.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(CNodoLista, CopyConstructor) {
  CNodoLista<int> node1 = CNodoLista<int>{1};
  auto node2 = new CNodoLista<int>{2};
  auto node3 = new CNodoLista<int>{2};

  node1.SetSigNodo(node2);
  node2->SetSigNodo(node3);
}
