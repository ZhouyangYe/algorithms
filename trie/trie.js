function TrieNode () {
	this.children = new Array(26);
}

function Trie() {
	this.root = new TrieNode();
	
	this.insert = function(word) {
		let current = this.root;
		for (let i = 0; i < word.length; i++) {
			if (!current.children[word.charCodeAt(i)]) {
				current.children[word.charCodeAt(i)] = new TrieNode();
			}
			current = current.children[word.charCodeAt(i)];
		}
	}
	
	this.find = function(word) {
		let current = this.root;
		for (let i = 0; i < word.length; i++) {
			if (current.children[word.charCodeAt(i)]) {
				current = current.children[word.charCodeAt(i)];
			} else {
				break;
			}
			
			if (i == word.length - 1) {
				return true;
			}
		}
			
		return false;
	}
}

const keys = ["the", "a", "there", "answer", "any", "by", "bye", "their"];

const trie = new Trie();
keys.forEach((str) => {
	trie.insert(str);
});

console.log(trie.find('thei'));
console.log(trie.find('any'));