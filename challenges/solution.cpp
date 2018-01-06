#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct BasicTree {
	struct BasicNode {
		int data;
		BasicNode* left;
		BasicNode* right;

		BasicNode(int data = 0): data(data), left(NULL), right(NULL) {}
	} * root;

	void printDepths() {
		printDepth(root, 0);
	}

	BasicTree(const std::vector<int>& sortedSequence): root(new BasicNode()) {
		buildSubtree(sortedSequence, 0, sortedSequence.size() - 1, root);
	}
	~BasicTree() {
		deleteSubtree(root);
	}

private:
	void buildSubtree(const std::vector<int>& buildSequence, int startIndex, int endIndex, BasicNode* node) {
		int subsequenceLength = endIndex - startIndex;
		int leftMiddle = subsequenceLength/2;

		node->data = buildSequence[startIndex + leftMiddle];
		if(leftMiddle) {
			node->left = new BasicNode();
			buildSubtree(buildSequence, startIndex, startIndex + leftMiddle - 1, node->left);
			node->right = new BasicNode();
			buildSubtree(buildSequence, startIndex + leftMiddle + 1, endIndex, node->right);
		} else if(subsequenceLength % 2) {
			node->right = new BasicNode(buildSequence[startIndex + leftMiddle + 1]);
		}
	}

	void deleteSubtree(BasicNode* subTreeRoot) {
		if(subTreeRoot->left) {
			delete(subTreeRoot->left);
		}
		if(subTreeRoot->right) {
			delete(subTreeRoot->right);
		}

		delete subTreeRoot;
	}

	void printDepth(BasicNode* subtreeRoot, int currDepth) {
		if(subtreeRoot->left) {
			printDepth(subtreeRoot->left, currDepth + 1);
		} else {
			std::cout<< currDepth<< "\n";
		}
		if(subtreeRoot->right) {
			printDepth(subtreeRoot->right, currDepth + 1);
		} else {
			std::cout<< currDepth<< "\n";
		}
	}
};

void readSequence(std::vector<int>& sequence, const char* filename);

int main () {
	std::vector<int> sequence;
	readSequence(sequence, "sortedSequence.txt");

	BasicTree balancedTree(sequence);

	//balancedTree.printDepths();

	return 0;
}

void readSequence(std::vector<int>& sequence, const char* filename) {
	ifstream file;
	file.open(filename);

	if(!file) {
        throw;
	}

	while(true) {
		int nextElement;
		file>> nextElement;
		if(file.eof()) {
			break;
		}
		sequence.push_back(nextElement);
	}
	file.close();
}
