#include "Node.h"

Node::Node(char value, size_t rate)
	: Node(value, rate, nullptr, nullptr) {}

Node::Node(char value, size_t rate, Node* left, Node* right)
	: value{ value }, rate{ rate }, left{ left }, right{ right } {}

const char& Node::Value() { return value; }

const size_t& Node::Rate() { return rate; }

Node*& Node::Left() { return left; }

Node*& Node::Right() { return right; }

bool NodeComparer::operator()(Node* left, Node* right)
{
	return left->rate > right->rate;
}
