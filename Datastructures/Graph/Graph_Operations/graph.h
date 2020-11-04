typedef struct adjacency_list_node_s
{
	struct graph_node_s* graph_node;
	struct adjacency_list_s* next;
} adjacency_list_node;

typedef struct graph_node_s
{
	int node_index;
	struct adjacency_list_s* adjacency_list;
}grpah_node;

typedef struct graph_node_list_s
{
	struct graph_node_s* graph_node;
	struct graph_node_list_s* next;
}graph_node_list;
