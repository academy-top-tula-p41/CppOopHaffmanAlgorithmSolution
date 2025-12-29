#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

#include "Node.h"


class HuffmanAlgorithm
{
	std::unordered_map<char, int> symbolRates;
	std::unordered_map<char, std::string> symbolCodes;
	std::priority_queue<Node*, std::vector<Node*>, NodeComparer> nodesTree;

	void EncodeBuild(Node* root, std::string code);
	void DecodeBuild(Node* root, std::string codeString, int& position, std::string& text);
public:

	std::unordered_map<char, std::string>& SymbolCodes();

	Node* NodesTreeBuilder(std::string text);
	void Encode(Node* root);
	std::string Decode(Node* root, std::string codeString);
};

