class Node {
	constructor(value){
		this.value = value;
		this.next = null;
	}
}

class LinkedList {
	constructor() {
		this.head = null;
		this.size = 0;
	}
	isEmpty() {
		return this.size!=0?true:false;
	}
	printList() {
		let current_node = this.head;
		let str = "";
		while(current_node != null) {
			str += current_node.value + " ";
			current_node = current_node.next;
		}
		console.log("Linked List Elements: ", str);
		return;
	}
	addNode(value) {
		let node = new Node(value);
		if(this.head == null) {
			this.head = node;
		}
		else {
			let current_node = this.head;
			while(current_node.next != null) {
				current_node = current_node.next;
			}
			current_node.next = node;
		}
		this.size += 1;
		return;
	}
	searchNode(value) {
		let current_node = this.head;
		while(current_node != null) {
			if(current_node.value == value) {
				return true;
			}
			current_node = current_node.next;
		}
		return false;
	}
	deleteNode(value) {
		let current_node = this.head;
		let previous_node = this.head;
		while(current_node != null) {
			if(current_node.value == value) {
				if(current_node == this.head) {
					this.head = current_node.next;
				}
				else  {
					previous_node.next = current_node.next;
				}
				this.size--;
				return value;
			}
			previous_node = current_node;
			current_node = current_node.next;
		}
		return -1;
	}
}

let linked_list = new LinkedList();

console.log("Is linked list empty :", linked_list.isEmpty());

linked_list.addNode(10);
linked_list.addNode(11);
linked_list.addNode(12);
linked_list.addNode(13);

linked_list.printList();

console.log("Is node 11 present :", linked_list.searchNode(11));
console.log("Is node 21 present :", linked_list.searchNode(21));

console.log("Is node 11 deleted ? ",linked_list.deleteNode(11));
console.log("Is node 21 deleted ? ",linked_list.deleteNode(21));

linked_list.printList();

console.log("Is node 11 present :", linked_list.searchNode(11));
console.log("Is node 21 present :", linked_list.searchNode(21));
