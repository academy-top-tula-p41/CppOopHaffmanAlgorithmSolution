#include "HuffmanAlgorithm.h"

void HuffmanAlgorithm::EncodeBuild(Node* root, std::string code)
{
	if (!root) return;

	if (!root->Left() && !root->Right())
		symbolCodes[root->Value()] = code;

	EncodeBuild(root->Left(), code + "0");
	EncodeBuild(root->Right(), code + "1");
}

void HuffmanAlgorithm::DecodeBuild(Node* root, std::string codeString, int& position, std::string& text)
{
	if (!root) return;

	if (!root->Left() && !root->Right())
	{
		//std::cout << root->Value();
		text += root->Value();
		return;
	}

	position++;
	if (codeString[position] == '0')
		DecodeBuild(root->Left(), codeString, position, text);
	else
		DecodeBuild(root->Right(), codeString, position, text);
}

std::unordered_map<char, std::string>& HuffmanAlgorithm::SymbolCodes()
{
	return symbolCodes;
}

Node* HuffmanAlgorithm::NodesTreeBuilder(std::string text)
{
	symbolRates.clear();

	for (auto symbol : text)
		symbolRates[symbol]++;

	while (!nodesTree.empty())
		nodesTree.pop();

	for (auto pair : symbolRates)
		nodesTree.push(new Node(pair.first, pair.second));

	while (nodesTree.size() > 1)
	{
		Node* right = nodesTree.top();
		nodesTree.pop();

		Node* left = nodesTree.top();
		nodesTree.pop();

		Node* parent = new Node('\0', left->Rate() + right->Rate(), left, right);
		nodesTree.push(parent);
	}

	return nodesTree.top();
}

void HuffmanAlgorithm::Encode(Node* root)
{
	EncodeBuild(root, "");
}

std::string HuffmanAlgorithm::Decode(Node* root, std::string codeString)
{
	std::string text = "";
	int position{ -1 };
	while (position < (int)codeString.length() - 1)
		DecodeBuild(root, codeString, position, text);
	return text;
}
