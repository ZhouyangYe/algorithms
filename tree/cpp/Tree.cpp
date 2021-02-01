#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Node {
private:
public:
	string id;
	string data;
	vector<Node*> children;
	Node* parent;

	Node(string id, string data) {
		this->id = id;
		this->data = data;
	}

	~Node() {}
};

class Tree {
private:
	Node* root;
public:
	static const string ROOT_ID;
	map<string, Node*> cache;

	Tree() {
		this->root = new Node(ROOT_ID, "hello root");
		this->cache[ROOT_ID] = this->root;
	}

	~Tree() {}

	Node* getRoot() {
		return this->root;
	}

	Node* getNode(string id) {
		return this->cache[id];
	}

	void addNode(string parentId, Node* node) {
		Node* parent = this->getNode(parentId);
		node->parent = parent;

		parent->children.push_back(node);
		cache[node->id] = node;
	}

	void dfs(void (cb)(Node*)) {
		vector<Node*> queue = { this->root };
		int size = queue.size();

		while (size) {
			Node* current = queue[size - 1];
			cb(current);

			queue.pop_back();
			if (current->children.size()) {
				queue.insert(queue.end(), current->children.begin(), current->children.end());
			}
			size = queue.size();
		}
	}

	void bfs(void (cb)(Node*)) {
		vector<Node*> queue = { this->root };
		int size = queue.size();

		while (size) {
			Node* current = queue[0];
			cb(current);

			queue.erase(queue.begin());
			if (current->children.size()) {
				queue.insert(queue.end(), current->children.begin(), current->children.end());
			}
			size = queue.size();
		}
	}
};
const string Tree::ROOT_ID = "root";

Tree* getRandomTree(int size) {
	Tree* tree = new Tree();
	for (int i = 0; i < size; i++) {
		Node* node = new Node(to_string(i), "hello" + to_string(i));
		string index = to_string(rand() % (i + 1));
		string randomId = index == to_string(i) ? Tree::ROOT_ID : index;
		tree->addNode(randomId, node);
	}
	return tree;
}

int main(void) {
	Tree* tree = getRandomTree(10);
	tree->bfs([](Node* node) {
		string parentId;

		if (!node->parent) {
			parentId = "Not exist";
		}
		else {
			parentId = node->parent->id;
		}
		cout << "id: " << node->id << ",data: " << node->data << ", parent: " << parentId << "\n";
	});
	getchar();
}
