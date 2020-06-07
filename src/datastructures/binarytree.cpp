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


std::shared_ptr<BinaryNode> BinaryTree::search(int value) const {
  if (this->root == nullptr) {
    return nullptr;
  }

  return this->search(this->root, value);
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

void BinaryTree::deleteNode(std::shared_ptr<BinaryNode> node) {
  if(node->getLeftSubtree() == nullptr && node->getRightSubtree() == nullptr) {
	if (node->getParent()->getValue() >= node->getValue()) {
	  node->getParent()->setLeftSubtree(nullptr);
	} else {
	  node->getParent()->setRightSubtree(nullptr);
	}
  } else if (node->getLeftSubtree() && node->getRightSubtree() == nullptr) {
	if (node->getParent()->getLeftSubtree()->getValue() == node->getValue()) {
	  node->getParent()->setLeftSubtree(node->getLeftSubtree());
	} else {
	  node->getParent()->setRightSubtree(node->getLeftSubtree());
	}
  } else if (node->getRightSubtree() && node->getLeftSubtree() == nullptr) {
	if (node->getParent()->getValue() >= node->getValue()) {
	  node->getParent()->setLeftSubtree(node->getRightSubtree());
	} else {
	  node->getParent()->setRightSubtree(node->getRightSubtree());
	}
  } else {
	 auto minimumNode = this->minimum(node->getRightSubtree());

	 if (minimumNode->getRightSubtree()) {
	   deleteNode(minimumNode);
	 }

	 if (node->getParent()->getValue() >= node->getValue()) {
	   node->getParent()->setLeftSubtree(minimumNode);
	 } else {
	   node->getParent()->setRightSubtree(minimumNode);
	 }

	 minimumNode->setLeftSubtree(node->getLeftSubtree());
	 minimumNode->setRightSubtree(node->getRightSubtree());
  }
}

std::shared_ptr<BinaryNode> BinaryTree::minimum() const {
  if (this->root == nullptr) {
    return nullptr;
  } else if (this->root->getLeftSubtree() == nullptr) {
    return this->root;
  } else {
    return this->minimum(this->root);
  }
}

std::shared_ptr<BinaryNode> BinaryTree::minimum(std::shared_ptr<BinaryNode> node) const {
  if (node->getLeftSubtree()) {
	return minimum(node->getLeftSubtree());
  } else {
    return node;
  }
}

std::shared_ptr<BinaryNode> BinaryTree::maximum() const {
  if (this->root == nullptr) {
	return nullptr;
  } else if (this->root->getRightSubtree() == nullptr) {
	return this->root;
  } else {
	return this->maximum(this->root);
  }
}


std::shared_ptr<BinaryNode> BinaryTree::maximum(std::shared_ptr<BinaryNode> node) const {
  if (node->getRightSubtree()) {
	return maximum(node->getRightSubtree());
  } else {
	return node;
  }
}
