//
// Created by Thomas Kunze on 06.06.20.
//
#pragma once

#include <memory>
#include <vector>

#include <datastructures/binarynode.h>

class BinaryTree {
  std::shared_ptr<BinaryNode> root = nullptr;
  void insert(std::shared_ptr<BinaryNode> node, int value);
  std::shared_ptr<BinaryNode> search(std::shared_ptr<BinaryNode> node, int value) const;
  std::shared_ptr<BinaryNode> minimum(std::shared_ptr<BinaryNode> node) const;
  std::shared_ptr<BinaryNode> maximum(std::shared_ptr<BinaryNode> node) const;
  void inorder(std::vector<int>& numbers, std::shared_ptr<BinaryNode> node);

public:
  BinaryTree()= default;;
  explicit BinaryTree(const std::vector<int>& values);
  std::shared_ptr<BinaryNode> getRoot() const;
  void insert(int value);
  std::shared_ptr<BinaryNode> search(int value) const;
  void deleteNode(std::shared_ptr<BinaryNode> node);
  std::shared_ptr<BinaryNode> minimum() const;
  std::shared_ptr<BinaryNode> maximum() const;
  std::vector<int> inorder();
};


