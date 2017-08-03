typedef struct node * ptrToNode;
typedef int elementType;
typedef ptrToNode stack;

struct node
{
  elementType element;
  ptrToNode next;
};

int isEmpty(stack s);
Stack createStack(void);
void disposeStack(stack s);
void makeEmpty(stack s);
void push(elementType x, stack s);
ElementType top(stack s);
void pop(stack s);

int isEmpty(stack s)
{
  return s->next==NULL;
}

Stack createStack(void)
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

void disposeStack(stack s)
{
  if(!isEmpty(s))
    {
      makeEmpty(s);
    }
    free(s);
}

void makeEmpty(stack s)
{
  while(!isEmpty(s))
  {
    pop(s);
  }
}

void push(ElementType x, Stack s)
{
  if(s!=NULL)
  {
    PtrToNode tmp_ptr=malloc(sizeof(struct node));
    if(PtrToNode==NULL)
    {
      printf("\nError : ran out of memory\n");
    }
    else
    {
      tmp_ptr->element=x;
      tmp_ptr->next=s->next;
      s->next=tmp_ptr;
    }
  }
  else
    printf("\ninvalid stack called\n");
}

ElementType top(stack s)
{
  if(s!=NULL)
  {
    if(!isEmpty(s))
      return (s->next)->element;
    else
    printf("Empty Stack")
      return NULL;
  }
  else
  {
    printf("\ninvalid stack called\n");
    return NULL;
  }
}

void pop(stack s)
{
  if(s!=NULL)
  {
    if(!isEmpty(s))
    {
      ptrToNode tmp_ptr;
      tmp_ptr=s->next;
      s->next=tmp_ptr->next;
      free(tmp_ptr);
    }
    else
    {
      printf("Empty Stack");
    }

  }
  else
    printf("\ninvalid stack called\n");
}

int main(char argc, char * argv)
{
return 0;
}
