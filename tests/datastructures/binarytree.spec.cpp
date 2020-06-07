//
// Created by Thomas Kunze on 07.06.20.
//

#include <iostream>
#include <catch2/catch.hpp>
#include <datastructures/binarytree.h>

SCENARIO("Binary Search Tree", "[bst]") {
  GIVEN("Initialize a tree") {
    WHEN ("giving no value") {
      THEN ("the root node is empty") {
        const auto tree = BinaryTree();
        REQUIRE(tree.getRoot() == nullptr);
      }
    }

    WHEN("giving an list of values") {
      THEN("the nodes are inserted in given order") {
        const std::vector<int> expected = {1,3,2,4};
        const auto tree = BinaryTree(expected);

		REQUIRE(tree.getRoot()->getValue() == expected[0]);
		REQUIRE(tree.getRoot()->getLeftSubtree() == nullptr);
		REQUIRE(tree.getRoot()->getRightSubtree()->getValue() == expected[1]);
		REQUIRE(tree.getRoot()->getRightSubtree()->getLeftSubtree()->getValue() == expected[2]);
		REQUIRE(tree.getRoot()->getRightSubtree()->getRightSubtree()->getValue() == expected[3]);
	  }
    }
  }

  GIVEN("Inserting a value into the tree") {
    WHEN("the tree is empty") {
      THEN ("returns the root node with the inserted value") {
        const auto expected = 10;
        auto tree = BinaryTree();

        tree.insert(expected);

        REQUIRE(tree.getRoot()->getValue() == expected);
      }
    }
  }
}