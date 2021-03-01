#include<stdio.h>
#define MAX_WORDS 50001
#define MAX_WORD_LEN 10

typedef struct queue_s
{
	char* word;
	int len;
}queue_node;


int is_endWord(char* endWord, char* newWord)
{
	int i =0;
	while(endWord[i] != '\0')
	{
		if(endWord[i] != newWord[i])
			return 0;
		i++;
	}
	return 1;
}

int is_adjacent(char* current_word, char* new_word)
{
	int i =0;
	int diff =0;
	while(current_word[i] != '\0')
	{
		if(current_word[i] != new_word[i])
			diff++;
		if(diff ==2)
			return 0;
		i++;
	}
	if(diff ==1)
		return 1;
	return 0;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
	int ret =0;
	int i =0;
	int count =0;
	int visited[MAX_WORDS] = {0};
	int queue_index =0;
	int current_word_index =0;
	int end_word_present =0;
	char* current_word;
	int end_word_index =0;
	queue_node queue[MAX_WORDS];

	printf("\n beginWord [%s], endWord [%s], wordListSize [%d]\n", beginWord, endWord, wordListSize);
	printf("\nList of words\n");
	for(i =0; i<wordListSize; i++)
	{
		printf("%s ", wordList[i]);
		if(is_endWord(endWord, wordList[i]) == 1)
		{
			end_word_present = 1;
			end_word_index = i;
		}
	}
	if(end_word_present == 0)
	{
		return 0;
	}
//	wordList[wordListSize] = beginWord;
	queue[queue_index].word = beginWord;
	queue[queue_index].len = 1;
	i =0;
	count =0;
	while(count < wordListSize && count <= queue_index)
	{
		current_word = queue[count].word;
		printf("\n current word %s ", current_word);
		for(i=0; i<wordListSize; i++)
		{
			if( visited[i] == 0 && is_adjacent(current_word, wordList[i]) == 1)
			{
				printf(" adjacent word %s", wordList[i]);
				if(end_word_index == i)
				{
					return queue[count].len+1;
				}
				queue_index++;
				queue[queue_index].word = wordList[i];
				queue[queue_index].len = queue[count].len + 1;
				visited[i] =1;
			}
		}
		count++;
	}
	return ret;
}

int main(void)
{
	char* wordList [MAX_WORD_LEN] ={"hot","dot","dog","lot","log","cog"};
//	char* wordList [MAX_WORD_LEN] ={"hot","dog"};

	printf("\nNumber of words in the shortest transformation sequence %d\n", ladderLength("hit", "cog", wordList, 6));
	printf("\n Program to implement word ladder problem\n");
	return 0;
}
