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
		const std::vector<int> expected = {1, 3, 2, 4};
		const auto tree = BinaryTree(expected);

		REQUIRE(tree.getRoot()->getValue() == expected[0]);
		REQUIRE(tree.getRoot()->getLeftSubtree() == nullptr);
		REQUIRE(tree.getRoot()->getRightSubtree()->getValue() == expected[1]);
		REQUIRE(tree.getRoot()->getRightSubtree()->getLeftSubtree()->getValue() == expected[2]);
		REQUIRE(tree.getRoot()->getRightSubtree()->getRightSubtree()->getValue() == expected[3]);
	  }
	}
  }

  GIVEN("Searching a node with value") {
	WHEN("tree is empty") {
	  THEN("returns nullptr") {
		const auto tree = BinaryTree();
		const auto node = tree.search(5);

		REQUIRE(node == nullptr);
	  }
	}WHEN("tree is not empty") {
	  WHEN("value is root") {
		THEN("returns node with value") {
		  const auto expected = 1;
		  const std::vector<int> values = {expected, 2, 3, 4};
		  const auto tree = BinaryTree(values);

		  const auto node = tree.search(expected);

		  REQUIRE(node->getValue() == expected);
		}
	  } WHEN("value is left subtree node") {
		THEN("returns node with value") {
		  const auto expected = 1;
		  const std::vector<int> values = {2, expected, 3, 4};
		  const auto tree = BinaryTree(values);

		  const auto node = tree.search(expected);

		  REQUIRE(node->getValue() == expected);
		}
	  } WHEN("value is right subtree node") {
		THEN("returns node with value") {
		  const auto expected = 3;
		  const std::vector<int> values = {2, 1, 3, 4};
		  const auto tree = BinaryTree(values);

		  const auto node = tree.search(expected);

		  REQUIRE(node->getValue() == expected);
		}
	  } WHEN("value is not in tree") {
		THEN("returns node with value") {
		  const std::vector<int> values = {2, 1, 3, 4};
		  const auto tree = BinaryTree(values);

		  const auto node = tree.search(5);

		  REQUIRE(node == nullptr);
		}
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

	WHEN("root is not empty and has no children") {
	  WHEN("inserted value is smaller than root value") {
		THEN("inserts the node as left subtree") {
		  const auto expected = 2;
		  const std::vector<int> root = {5};
		  auto tree = BinaryTree(root);

		  tree.insert(expected);

		  REQUIRE(tree.getRoot()->getLeftSubtree()->getValue() == expected);
		}
	  } WHEN("inserted value is equal to root value") {
		THEN("inserts the node as left subtree") {
		  const auto expected = 5;
		  const std::vector<int> root = {5};
		  auto tree = BinaryTree(root);

		  tree.insert(expected);

		  REQUIRE(tree.getRoot()->getLeftSubtree()->getValue() == expected);
		}
	  }

	  WHEN("inserted value is greater than root value") {
		THEN("inserts the node as right subtree") {
		  const auto expected = 10;
		  const std::vector<int> root = {5};
		  auto tree = BinaryTree(root);

		  tree.insert(expected);

		  REQUIRE(tree.getRoot()->getRightSubtree()->getValue() == expected);
		}
	  }
	}
  }

  GIVEN("Deleting a node from tree") {
	WHEN("node has no children") {
	  WHEN("node is a left subtree") {
		THEN("parent has no child anymore") {
		  const std::vector<int> values = {2, 1};
		  auto tree = BinaryTree(values);
		  auto node = tree.getRoot()->getLeftSubtree();

		  tree.deleteNode(node);

		  REQUIRE(tree.getRoot()->getLeftSubtree() == nullptr);
		}
	  }

	  WHEN("node is a right subtree") {
		THEN("parent has no child anymore") {
		  const std::vector<int> values = {1, 2};
		  auto tree = BinaryTree(values);
		  auto node = tree.getRoot()->getRightSubtree();

		  tree.deleteNode(node);

		  REQUIRE(tree.getRoot()->getRightSubtree() == nullptr);
		}
	  }
	}

	WHEN("node has one child") {
	  WHEN("node is a left subtree") {
		THEN("parent has child as left subtree") {
		  const auto expected = 0;
		  const std::vector<int> values = {2, 1, expected};
		  auto tree = BinaryTree(values);
		  auto node = tree.getRoot()->getLeftSubtree();

		  tree.deleteNode(node);

		  REQUIRE(tree.getRoot()->getLeftSubtree()->getValue() == expected);
		}
	  }

	  WHEN("node is a right subtree") {
		THEN("parent has child as right subtree") {
		  const auto expected = 2;
		  const std::vector<int> values = {0, 1, expected};
		  auto tree = BinaryTree(values);
		  auto node = tree.getRoot()->getRightSubtree();

		  tree.deleteNode(node);

		  REQUIRE(tree.getRoot()->getRightSubtree()->getValue() == expected);
		}
	  }
	}

	WHEN("node has two children") {
	  WHEN("node is a left subtree") {
		WHEN("minimum of right subtree has no right child") {
		  THEN("replace node with minimum of right subtree") {
			const auto expected = 0;
			const std::vector<int> values = {3, -1, -2, 2, expected};
			auto tree = BinaryTree(values);
			auto node = tree.getRoot()->getLeftSubtree();

			tree.deleteNode(node);

			REQUIRE(tree.getRoot()->getLeftSubtree()->getValue() == expected);
		  }
		} WHEN("minimum of right subtree has a right child") {
		  THEN(
			  "replace node with minimum of right subtree and replace minimum right subtree with right child of minimum") {
			const auto expected = 0;
			const std::vector<int> values = {3, -1, -2, 2, expected, 1};
			auto tree = BinaryTree(values);
			auto node = tree.getRoot()->getLeftSubtree();

			tree.deleteNode(node);
			REQUIRE(tree.getRoot()->getValue() == 3);
			REQUIRE(tree.getRoot()->getLeftSubtree()->getValue() == expected);
			REQUIRE(tree.getRoot()->getLeftSubtree()->getLeftSubtree()->getValue() == -2);
			REQUIRE(tree.getRoot()->getLeftSubtree()->getRightSubtree()->getValue() == 2);
			REQUIRE(tree.getRoot()->getLeftSubtree()->getRightSubtree()->getLeftSubtree()->getValue() == 1);
			REQUIRE(tree.getRoot()->getLeftSubtree()->getRightSubtree()->getLeftSubtree()->getLeftSubtree() == nullptr);
			REQUIRE(
				tree.getRoot()->getLeftSubtree()->getRightSubtree()->getLeftSubtree()->getRightSubtree() == nullptr);
		  }
		}
	  }

	  WHEN("node is a right subtree") {
		THEN("parent has child as right subtree") {
		  const auto expected = 2;
		  const std::vector<int> values = {0, 1, expected};
		  auto tree = BinaryTree(values);
		  auto node = tree.getRoot()->getRightSubtree();

		  tree.deleteNode(node);

		  REQUIRE(tree.getRoot()->getRightSubtree()->getValue() == expected);
		}
	  }
	}
  }

  GIVEN("Minimum") {
	WHEN("Tree is empty") {
	  THEN("has no minimum") {
		const auto tree = BinaryTree();
		const auto node = tree.minimum();

		REQUIRE(node == nullptr);
	  }
	}

	WHEN("tree has only root") {
	  THEN("return root as minimum") {
		const auto expected = 0;
		const std::vector<int> values = {expected};
		const auto tree = BinaryTree(values);
		const auto node = tree.minimum();

		REQUIRE(node->getValue() == expected);
	  }
	}

	WHEN("tree has more than one right subtree") {
	  THEN("return leftmost value") {
		const auto expected = 0;
		const std::vector<int> values = {3, 2, 1, expected};
		const auto tree = BinaryTree(values);
		const auto node = tree.minimum();

		REQUIRE(node->getValue() == expected);
	  }
	}
  }

  GIVEN("Maximum") {
	WHEN("Tree is empty") {
	  THEN("has no maximum") {
		const auto tree = BinaryTree();
		const auto node = tree.maximum();

		REQUIRE(node == nullptr);
	  }
	}

	WHEN("tree has only root") {
	  THEN("return root as maximum") {
		const auto expected = 0;
		const std::vector<int> values = {expected};
		const auto tree = BinaryTree(values);
		const auto node = tree.maximum();

		REQUIRE(node->getValue() == expected);
	  }
	}

	WHEN("tree has more than one right subtree") {
	  THEN("return rightmost value") {
		const auto expected = 20;
		const std::vector<int> values = {1, 2, 3, expected};
		const auto tree = BinaryTree(values);
		const auto node = tree.maximum();

		REQUIRE(node->getValue() == expected);
	  }
	}
  }
}