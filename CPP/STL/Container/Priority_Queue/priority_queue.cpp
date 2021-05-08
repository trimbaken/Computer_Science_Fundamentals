#include<iostream>
#include<queue>

using namespace std;

void showpq(priority_queue<int> gq)
{
	priority_queue<int> g = gq;
	cout<<"\n elemets of priority queue are: \n";
	while (!g.empty()) {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

void show_min_pq(priority_queue<int, vector<int>, greater<int>> gq)
{
	priority_queue<int, vector<int>, greater<int>> g = gq;
	cout<<"\n elemets of priority queue are: \n";
	while (!g.empty()) {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

typedef struct node_s
{
	int key;
	string value;
}node_t;

auto compare = [](int l, int r){
	return l>r;
};

void showpq(priority_queue<int, vector<int>, decltype(compare)>gq)
{
	priority_queue<int, vector<int>, decltype(compare)>g = gq;
	cout<<"\n elemets of priority queue are: \n";
	while (!g.empty()) {
		cout << ' ' << g.top()<<"\n";
		g.pop();
	}
	cout << '\n';
}


auto compare_node = [](node_t l, node_t r){
	return l.key >r.key;
};

void showpq(priority_queue<node_t, vector<node_t>, decltype(compare_node)>gq)
{
	priority_queue<node_t, vector<node_t>, decltype(compare_node)>g = gq;
	cout<<"\n elemets of priority queue are: \n";
	node_t temp_node;
	while (!g.empty()) {
		temp_node = g.top();
		cout << ' ' << temp_node.key <<' '<<temp_node.value<<"\n";
		g.pop();
	}
	cout << '\n';
}

bool int_compare(int a, int b)
{
	return a<b;
}
int main(void)
{
	priority_queue<int> int_priority_queue;

	int_priority_queue.push(30);
	int_priority_queue.push(15);
	int_priority_queue.push(40);
	int_priority_queue.push(6);

	cout<<"\n int_priority_queue size "<<int_priority_queue.size() ;
	cout<<"\n gretest element "<< int_priority_queue.top();

	showpq(int_priority_queue);

	priority_queue<int , vector<int>, greater<int>>min_priority_queue;

	min_priority_queue.push(30);
	min_priority_queue.push(15);
	min_priority_queue.push(40);
	min_priority_queue.push(6);

	cout<<"\n min element "<<min_priority_queue.top();
	show_min_pq(min_priority_queue);

	priority_queue<int, vector<int>, decltype(compare)>int_custom_p_queue(compare);

	int_custom_p_queue.push(30);
	int_custom_p_queue.push(15);
	int_custom_p_queue.push(40);
	int_custom_p_queue.push(6);

	showpq(int_custom_p_queue);

	priority_queue<node_t, vector<node_t>, decltype(compare_node)>node_custom_p_queue(compare_node);
	node_t node_1;
	node_1.key = 30;
	node_1.value = "abc";
	node_t node_2;
	node_2.key = 15;
	node_2.value = "bcd";
	node_t node_3;
	node_3.key = 40;
	node_3.value = "abc";
	node_t node_4;
	node_4.key = 6;
	node_4.value = "abcd";

	node_custom_p_queue.push(node_1);
	node_custom_p_queue.push(node_2);
	node_custom_p_queue.push(node_3);
	node_custom_p_queue.push(node_4);

	node_t top_node = node_custom_p_queue.top(); // get top element

	cout<<"\n top node "<<top_node.key<<" "<<top_node.value;
	showpq(node_custom_p_queue);
	node_custom_p_queue.pop(); // remove top element
	showpq(node_custom_p_queue);

	cout<<"\n program to implement priority queue functionalities\n";
	return 0;
}
