#include<stdio.h>

//グラフの節点の数
#define dGraphSize (12)
//横型探索に用いるキューOPENのサイズ
#define dOpenSize (8)

//探索木の節点のデータ構造
typedef struct _NODE
{
	//自分自身の節点の番号
	int node;
	//親の節点の番号
	int parent;
} NODE;

//横型探索に用いるキューのデータ構造
typedef struct _OPEN
{
	//キューの本体
	NODE *array[dOpenSize];
	//キューの先頭
	int head;
	//キューの末尾
	int tail;
	//キューへの格納数
	int ct;
} OPEN;

//探索木に節点childを追加
void TreeSet(NODE *tree, int child, int parent);
//探索木を初期化(treeのnum個の要素のnode,parentを無効な値-1で初期化)
void TreeInit(NODE *tree, int num);
//横型探索に用いるキューに節点nodeを追加する。
void Enqueue(OPEN *queue, NODE *node);
//横型探索に用いるキューから節点を取り出す。
NODE *Dequeue(OPEN *queue);
//キューの初期化
void OPENInit(OPEN *open);
//横型探索
int BFSearch(int *graph, int start, int goal, NODE *tree);

int main(void)
{
	//ループ用変数
	int i;
	NODE t[dGraphSize];
	int graph[dGraphSize * dGraphSize] =
	{
//	0  1  2  3  4  5  6  7  8  9  10 11  
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,// 0 
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,// 1 
	0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,// 2 
	0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,// 3 
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,// 4 
	0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,// 5 
	0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0,// 6 
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,// 7 
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,// 8 
	0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,// 9 
	0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0,//10 
	0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,//11 
	};
	if(BFSearch(graph, 11, 0, t) != -1)
	{
		for(i = 0; i != t[i].parent; i = t[i].parent)printf("%2d ", t[i].node);
		printf("%2d\n", t[i].node);
	}
}

void TreeSet(NODE *tree, int child, int parent)
{
	//子の節点番号を設定する。
	tree[child].node = child;
	//親を設定する。
	tree[child].parent = parent;
}

void TreeInit(NODE *tree, int num);
{
	//ループ用変数
	int i;
	for(i = 0; i < num; i++)
	{
		//無効な節点番号にしておく。
		tree[i].node = -1;
		tree[i].parent = -1;
	}
}

void Enqueue(OPEN *queue, NODE *node)
{
	//キューの容量が足りない場合
	if(queue->ct >= dOpenSize)
	{
		fprintf(stderr, "キューが小さすぎます。\n");
		return;
	}
	//キューにノードを追加
	queue->array[queue->tail] = node;
	//キューの末尾を一つずらす。キューの末尾がすでに配列の末尾であれば、配列の先頭にずらす。
	queue->tail = (queue->tail + 1) % dOpenSize;
	//キューに入っている節点の数をひとつ増やす。
	(queue->ct)++;
}

NODE *Dequeue(OPEN *queue)
{
	NODE *node;
	//キューがからの場合、NULLを返す。
	if(queue->ct <= 0)return NULL;
	//返すノードを取り出す。
	node = queue->array[queue->head];
	//キューの先頭をずらす。キューの先頭がすでに配列の末尾にあれば、配列の先頭にずらす。
	queue->head = (queue->head + 1) % dOpenSize;
	//キューに入っている節点の数をひとつ減らす。
	(queue->ct)--;
	//戦闘に合ったノードのアドレスを返す。
	return node;
}

void OPENInit(OPEN *open)
{
	open->head = 0;
	open->tail = 0;
	open->ct = 0;
}

int BFSearch(int *graph, int start, int goal, NODE *tree)
{
	//キュー
	OPEN queue;
	NODE *current;
	int i;
	int step;

	//treeの全ての要素を初期化する。
	TreeInit(tree, dGraphSize);
	//キューの初期化
	OPENInit(&queue);
	//startの親はstart
	TreeSet(tree, start, start);
	//キューに節点番号startの節点を入れる。
	Enqueue(&queue, tree + start);
}

