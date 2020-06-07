//
// Created by Thomas Kunze on 07.06.20.
//
#pragma once

#include <memory>

class BinaryNode {
  int value;
  std::shared_ptr<BinaryNode> parent = nullptr;
  std::shared_ptr<BinaryNode> left = nullptr;
  std::shared_ptr<BinaryNode> right = nullptr;

public:
  explicit BinaryNode(int value);
  int getValue() const;
  std::shared_ptr<BinaryNode> getParent() const;
  std::shared_ptr<BinaryNode> getLeftSubtree() const;
  std::shared_ptr<BinaryNode> getRightSubtree() const;
  void setParent(std::shared_ptr<BinaryNode> node);
  void setLeftSubtree(std::shared_ptr<BinaryNode> node);
  void setRightSubtree(std::shared_ptr<BinaryNode> node);
};
