#include<stdio.h>
#include<stdlib.h>

#define MAX_CAPACITY 3003
#define MAX_SIZE 30003
int cache_id =0;

typedef struct link_list_s{
	int key;
	int val;
	struct link_list_s* next;
	struct link_list_s* prev;
} link_list_t;

link_list_t link_list_memory_pool[MAX_SIZE];
int link_list_memory_pool_index =-1;
typedef struct node_s{
	int cache_id;
	link_list_t* link_list_node;
}node_t;

typedef struct {
	int cache_id;
	int capacity;
	int current_capacity;
	link_list_t* list_start;
	link_list_t* list_end;
	node_t node_list_mapping[MAX_CAPACITY];
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
	LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache ));
	cache_id++;
	obj->cache_id = cache_id;
	obj->capacity = capacity;
	obj->current_capacity = 0;
	obj->list_start = NULL;
	obj->list_end = NULL;

	return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
	int ret = -1;
	node_t* current_node = NULL;
	link_list_t* current_list_node = NULL;
	link_list_t* new_list_node = NULL;
	current_node = &obj->node_list_mapping[key];
	if(current_node->cache_id != obj->cache_id)
	{
		return -1;
	}
	ret = current_node->link_list_node->val;
	current_list_node = current_node->link_list_node;
//	printf("\n lRUCacheGet ret %d \n", ret);
	if(current_list_node != obj->list_start)
	{
		if(current_list_node->next != NULL)
		{
			current_list_node->next->prev = current_list_node->prev;
		}
		if(current_list_node->prev != NULL)
		{
			current_list_node->prev->next = current_list_node->next;
		}
		if(current_list_node == obj->list_end)
		{
			obj->list_end = current_list_node->prev;
		}
		current_list_node->next = NULL;
		current_list_node->prev = NULL;
		if(obj->list_start != NULL)
		{
			current_list_node->next = obj->list_start->next;
		}
		obj->list_start = current_list_node;
		if(obj->list_end == NULL)
		{
			obj->list_end = current_list_node;
		}
	}

//	printf("\n lRUCacheGet ret %d \n", ret);
	return ret;

}

link_list_t* create_new_list_node(int key, int value)
{
	link_list_memory_pool_index++;
	link_list_memory_pool[link_list_memory_pool_index].key = key;
	link_list_memory_pool[link_list_memory_pool_index].val = value;
	link_list_memory_pool[link_list_memory_pool_index].next = NULL;
	link_list_memory_pool[link_list_memory_pool_index].next = NULL;

	return &link_list_memory_pool[link_list_memory_pool_index];
}

void lRUCachePut(LRUCache* obj, int key, int value) {
	int current_cache_id = 0;
	node_t* current_node = NULL;
	link_list_t* new_list_node = NULL;
	link_list_t* current_list_node = NULL;
	if(obj == NULL)
	{
		return;
	}
	printf("\n Put key %d value %d\n", key, value);
	current_cache_id = obj->cache_id;
	current_node = &obj->node_list_mapping[key];

	if(current_node->cache_id != current_cache_id)
	{
		printf("\n Node not present key %d value %d\n", key, value);
		new_list_node = create_new_list_node(key, value);
		current_node->cache_id = current_cache_id;
		current_node->link_list_node = new_list_node;
		if(obj->list_start == NULL)
		{
			obj->list_start = new_list_node;
			obj->list_end = new_list_node;
			obj->current_capacity++;
		}
		else if(obj->current_capacity < obj->capacity)
		{
			new_list_node->next = obj->list_start;
			if(obj->list_start->next != NULL)
			{
				obj->list_start->next->prev = new_list_node;
			}
			obj->list_start = new_list_node;
			obj->current_capacity++;
		}
		else if(obj->current_capacity == obj->capacity)
		{
			printf("\nCapacity is full %d\n", obj->current_capacity);
			if(obj->list_end != NULL)
			{
				printf("\n Remove last element\n");
				obj->node_list_mapping[obj->list_end->key].cache_id = -1;
				obj->list_end = obj->list_end->prev;
				if(obj->list_end == NULL)
				{
					obj->list_start = NULL;
				}
				else
				{
					obj->list_end->next = NULL;
				}
			}
			else
			{
				new_list_node->next = obj->list_start;
				if(obj->list_start->next != NULL)
				{
					obj->list_start->next->prev = new_list_node;
				}
				obj->list_start = new_list_node;
			}
		}
		else
		{
			printf("\nError Case\n");
		}
	}
	else
	{
		printf("\n Node is present key %d value %d\n", key, value);
		current_list_node = current_node->link_list_node;
		if(current_list_node != obj->list_start)
		{
			if(current_list_node->next != NULL)
			{
				current_list_node->next->prev = current_list_node->prev;
			}
			if(current_list_node->prev != NULL)
			{
				current_list_node->prev->next = current_list_node->next;
			}
			if(current_list_node == obj->list_end)
			{
				obj->list_end = current_list_node->prev;
			}
			current_list_node->next = NULL;
			current_list_node->prev = NULL;
			if(obj->list_start != NULL)
			{
				current_list_node->next = obj->list_start->next;
			}
			obj->list_start = current_list_node;
			if(obj->list_end == NULL)
			{
				obj->list_end = current_list_node;
			}
		}
	}
}

void lRUCacheFree(LRUCache* obj) {
	if(obj != NULL)
	{
		free(obj);
	}
	return;
}


int main(void)
{
	LRUCache* new_obj = lRUCacheCreate(2);

	lRUCachePut(new_obj, 1,1);
	lRUCachePut(new_obj, 2,2);
	printf("\n Get 1 %d\n", lRUCacheGet(new_obj, 1));
	lRUCachePut(new_obj, 3,3);
	printf("\n Get 2 %d\n", lRUCacheGet(new_obj, 2));
	lRUCachePut(new_obj, 4,4);
	printf("\n Get 1 %d\n", lRUCacheGet(new_obj, 1));
	printf("\n Get 3 %d\n", lRUCacheGet(new_obj, 3));
	printf("\n Get 4 %d\n", lRUCacheGet(new_obj, 4));
	printf("\n Program to implement LRU Cache\n");
	return 0;
}
