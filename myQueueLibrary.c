typedef struct node * ptrToNode;
typedef elementType int;
typedef ptrToNode queue;

struct node
{
  elementType element;
  ptrToNode next;
};

int isEmpty(queue q);
queue createQueue(void);
void disposeQueue(queue q);
void makeEmpty(queue q);
void enQueue(elementType x, queue q);
ElementType front(queue q);
void deQueue(queue q);

int isEmpty(queue q){
  return q->next==NULL;
}

queue createQueue(void)
{
  ptrToNode p=malloc(sizeof(struct node));
  if(tmp_ptr==NULL)
  {
    printf("\nError : ran out of memory\n");
    return NULL;
  }
  else
    makeEmpty(tmp_ptr);
    tmp_ptr->next=NULL;
    return tmp_ptr;
}

void disposeQueue(queue q)
{
  if(!isEmpty(q))
    makeEmpty(q);
    free(q);
}

void makeEmpty(queue q)
{
  while(!isEmpty(q))
  {
    deQueue(q);
  }
}

void enQueue(ElementType x, queue q)
{
  if(q!=NULL)
  {
    ptrToNode tmp_ptr=malloc(sizeof(struct node));
    if(tmp_ptr==NULL)
    {
      printf("\nError : ran out of memory\n");
    }
    else
      tmp_ptr->element=x;
      tmp_ptr->next=q->next;
      q->next=tmp_ptr;
  }
  else
    printf("\ninvalid queue called\n");
}

ElementType front(queue q)
{
  if(q!=NULL)
  {
    if(!isEmpty(q))
      return (q->next)->element;
    else
    printf("Empty Queue")
      return NULL;
  }
  else
    printf("\ninvalid queue called\n");
    return NULL;
}

void deQueue(queue q)
{
  if(q!=NULL)
  {
    if(!isEmpty(q))
    {
      ptrToNode tmp_ptr;
      tmp_ptr=q->next;
      q->next=tmp_ptr->next;
      free(tmp_ptr);
    }
    else{
      printf("Empty Queue");
    }

  }
  else
    printf("\ninvalid queue called\n");
}

int main(char argc, char * argv){
return 0;
}
