#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

/* 链表节点的定义 */
struct node_t{
	int data;
	struct node_t * pnext;
};

/* 创建链表 */
struct node_t * NodeCreat(void)
{
    int len,i;
    printf("请输入链表的长度：len = ");
    scanf("%d", &len);

    struct node_t * phead=malloc(sizeof(struct node_t));
    phead->pnext = NULL;
    struct node_t * pend = phead;

    for(i = 0; i < len; i++)
    {
        int val;
        printf("请输入第 %d 个元素的值：", i+1);
        scanf("%d",&val);
        struct node_t * pnew = malloc(sizeof(struct node_t));
        pnew->data = val;
        pnew->pnext = NULL;
        pend->pnext = pnew;
        pend = pnew;
    }

    return phead;
}


/* 对链表进行遍历 */
void NodeShow(struct node_t * phead)
{
   struct node_t * p = phead->pnext;

   while(p!=NULL)
   {
       printf("%d    \n", p->data);
       p = p->pnext;
   }
}


/* 向链表中插入元素 */
bool NodeInsert(struct node_t * phead, int val, int pos)
{
	int i=0;
	struct node_t * p = phead;

	while(NULL != p && i < pos-1)
	{
		i++;
		p = p->pnext;
	}

	if(NULL == p)
	{
		printf("插入位置不合法\n");
		return false;
	}

	struct node_t * pnew = malloc(sizeof(struct node_t));
	pnew->data = val;
	struct node_t *temp = p->pnext;
	p->pnext = pnew;
	pnew->pnext = temp;

	return true;
}


/* 在链表中删除节点 */
bool NodeDelete (struct node_t * phead, int pos)
{
    int i=0;
    struct node_t * p = phead;

    while(p->pnext != NULL && i < pos - 1)
	{
        p = p->pnext;
        i++;
    }

    if(p->pnext == NULL)
    {
        printf("删除位置不合法\n");
    	return false;
    }

	struct node_t * temp = p->pnext;
	p->pnext = temp->pnext;

	free(temp);

	return true;
}

int main()
{

	struct node_t * phead= NodeCreat();

	NodeShow(phead);

	return 0;
}
