//
// Created by Thomas Kunze on 06.06.20.
//

#include <datastructures/binarytree.h>

BinaryTree::BinaryTree(const std::vector<int>& values) {
  for (const auto& value: values) {
	this->insert(value);
  }
}

std::shared_ptr<BinaryNode> BinaryTree::getRoot() const {
  return this->root;
}


void BinaryTree::insert(int value) {
  if (this->root == nullptr) {
	this->root = std::make_shared<BinaryNode>(value);
  } else {
	this->insert(this->root, value);
  }
}

std::shared_ptr<BinaryNode> BinaryTree::search(int value) const {
  if (this->root == nullptr) {
    return nullptr;
  }

  return this->search(this->root, value);
}

void BinaryTree::insert(std::shared_ptr<BinaryNode> node, int value) {
	if(value <= node->getValue()) {
	  const auto subnode = node->getLeftSubtree();
	  if (subnode == nullptr) {
	    auto newNode = std::make_shared<BinaryNode>(value);
	    newNode->setParent(node);
	    node->setLeftSubtree(newNode);
	  } else {
	    this->insert(subnode, value);
	  }
	} else {
	  const auto subnode = node->getRightSubtree();

	  if (subnode == nullptr) {
		auto newNode = std::make_shared<BinaryNode>(value);
		newNode->setParent(node);
		node->setRightSubtree(newNode);
	  } else{
	    this->insert(subnode, value);
	  }
	}
}


std::shared_ptr<BinaryNode> BinaryTree::search(std::shared_ptr<BinaryNode> node, int value) const {
  if(node == nullptr) {
    return nullptr;
  } else if (node->getValue() == value) {
    return node;
  } else {
    if (value < node->getValue()) {
      return this->search(node->getLeftSubtree(), value);
    } else {
      return this->search(node->getRightSubtree(), value);
    }
  }
}
