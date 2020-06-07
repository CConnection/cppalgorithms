//
// Created by Thomas Kunze on 07.06.20.
//

#include <datastructures/binarynode.h>

#include <utility>

BinaryNode::BinaryNode(int value) : value{value} {}

int BinaryNode::getValue() const {
  return this->value;
}
std::shared_ptr<BinaryNode> BinaryNode::getParent() const {
  return this->parent;
}
std::shared_ptr<BinaryNode> BinaryNode::getLeftSubtree() const {
  return this->left;
}
std::shared_ptr<BinaryNode> BinaryNode::getRightSubtree() const {
  return this->right;
}
void BinaryNode::setParent(std::shared_ptr<BinaryNode> node) {
  this->parent = std::move(node);
}
void BinaryNode::setLeftSubtree(std::shared_ptr<BinaryNode> node) {
  this->left = std::move(node);

}
void BinaryNode::setRightSubtree(std::shared_ptr<BinaryNode> node) {
  this->right = std::move(node);
}
