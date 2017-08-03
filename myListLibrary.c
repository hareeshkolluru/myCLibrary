typedef struct node * ptrToNode;
typedef ptrToNode list;
typedef ptrToNode position;

struct node
{
  elementType element;
  ptrToNode next;
};

list makeEmpty(list L);
int isEmpty(list L);
int isLast(position p, list L);
position find(elementType x, list L);
position findPrevious(elementType x, list L);
void delete(elementType x, list L);
void insert(elementType x, list L, position p);
void deleteList(list L);
position header(list L);
position first(list L);
position findkth(list L, int k);

//return 1 if list L is empty
int isEmpty(list L)
{
  return L->next==NULL;
}

//return 1 if position p is the last position in list L
//parameter L is unused here
int isLast(position p, list L)
{
  return p->next==NULL;
}

//return position of first occurence x in L; NULL if not found
position find(elementType x, list L)
{
  position p;
  if(L!=NULL)
  {
    p=L->next;
    while(p->element!=x && p!=NULL)
    {
      p=p->next;
    }
    return p;
  }
  else
  {
    printf("\nfatal error: cannot access NULL pointer");
  }
}

//returns the position of previous node of first occurence of x in L;NULL if not found
position findPrevious(elementType x, list L)
{
  position p;
  if(L!=NULL)
  {
    p=L;
    while(p->next->element!=x && p!=NULL)
    {
      p=p->next;
    }
    return p;
  }
  else
  {
    printf("\nfatal error: cannot access NULL pointer");
  }
}

//delete the first occurence of x in L
void delete(elementType x, list L)
{
  position p;
  if(L!=NULL)
  {
    p=findPrevious(x,L);
    if(p!=NULL)
    {
      position tmp_ptr=p->next;
      p->next=tmp_ptr->next;
      free(tmp_ptr);
      printf("\nelement succesfully deleted");
    }
    else
    {
      printf("\nelement not found");
    }
  }
  else
  {
    printf("\nfatal error: cannot access NULL pointer");
  }
}

//insert x in L after position p;
void insert(elementType x, list L, position p)
{
    position tmp_ptr=malloc(sizeof(struct node));
    if(tmp_ptr!=NULL)
    {
      tmp_ptr->next=p->next;
      tmp_ptr->element=p->element;
      p->next=tmp_ptr;
    }
    else
    {
      printf("\nfatal error: out of space");
    }
}

//keeps header, just deletes every other element
void deleteList(list L)
{
  position p,tmp_ptr;
  if(L!=NULL)
  {
    p=L->next;
    while(p!=NULL)
    {
        tmp_ptr=p->next;
        free(p);
        p=tmp_ptr;
    }
    L->next=NULL;
  }
  else
  {
    printf("\nfatal error: cannot access NULL pointer");
  }
}

//same as deleteList??
list makeEmpty(list L)
{
  deleteList(L);
  return L;
}

//return header position;
position header(list L)
{
  return L;
}

//return first position;
position first(list L)
{
  if(L!=NULL)
  {
    return L->next;
  }
  else
  {
    printf("\nfatal error: cannot access NULL pointer");
  }
}

//find kth node, not counting header, in the list L and return its element
position findkth(list L, int k)
{
  if(L!=NULL)
  {
    position tmp_ptr=L;
    while(k>0)
    {
      tmp_ptr=tmp_ptr->next;
      k--;
    }
    return tmp_ptr;
  }
  else
  {
    printf("\nfatal error: cannot access NULL pointer");
  }
}


int main(char argc, char * argv)
{
return 0;
}
