#pragma once
class Node
{
	char value;
	size_t rate;

	Node* left;
	Node* right;
public:
	Node(char value, size_t rate);
	Node(char value, size_t rate, Node* left, Node* right);

	const char& Value();
	const size_t& Rate();

	Node*& Left();
	Node*& Right();

	friend class NodeComparer;
};

class NodeComparer
{
public:
	bool operator()(Node* left, Node* right);
};

