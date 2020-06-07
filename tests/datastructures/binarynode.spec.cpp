//
// Created by Thomas Kunze on 07.06.20.
//

#include <catch2/catch.hpp>
#include <datastructures/binarynode.h>

SCENARIO("Binary Search Tree Node") {
  GIVEN("Initializing a node") {
	WHEN("creating a node with value") {
	  THEN("the node returns its value") {
	    const auto expected = 10;
	    const auto node = BinaryNode(expected);

	    REQUIRE(node.getValue() == expected);
	  }
	}
  }
}

