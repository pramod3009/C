#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 100
/*............this block is for declarions..................................*/

typedef struct menu
{
   char name[200];
   int price;
   
}element;

int icount =0;
int scount=0;
element *p;

int total=0;
typedef struct customer
{
   char name[200];
   int price;
   int quantity;
   int sum;
}token;
token *c;
/*..................................*/

/*this for the canteen guy to input the items*/
void canteen_guy(int num_items )
{
  p=(element*)malloc(num_items*sizeof(element));
  int i=0;
  for(i=0;i<num_items;i++)
   {
        printf("\nenter\titem name\tprice\n");
        scanf("%s%d",p[i].name,&p[i].price);
        icount+=1;
   }
}
/*.....................................................*/

/*this is for displaying the menu*/
void display_items()
{
   int i=0;
   printf("\nitem name\tprice\n");
   
   for(i=0;i<icount;i++)
      printf(" %d.%s\t\t%d\n",i+1,p[i].name,p[i].price);
}

/*.............................................*/

//customer functions

void insert(int item_number,int quantity)
{   item_number-=1;
    strcpy(c[scount].name,p[item_number].name);
    c[scount].price=p[item_number].price;
    c[scount].quantity=quantity; 
    c[scount].sum=p[item_number].price * quantity;
    scount+=1;
}

token_print()
{
   int i=0;
   
     printf("\nitem name\tquantity price*quantity\tsum\t\n");
      
    for(i=0;i<scount;i++)
     {     c[i].sum=c[i].price*c[i].quantity;
          printf(" %d.%s\t\t %d\t% d*%d\t\t%d\n",i+1,c[i].name,c[i].quantity,c[i].price,c[i].quantity,c[i].sum);
          total+=c[i].sum;
     }
   printf(".........................................\n");
   printf("                                  total= %d",total);
}
void delete(item_number,quantity)
{    int i=0;
     if(!scount)
         return;
     item_number-=1;
     
    if(quantity  > c[item_number].quantity)
       return;
          
     c[item_number].quantity-=quantity;
     c[item_number].sum=c[item_number].price*c[item_number].quantity;
   
      total=0;
      for(i=0;i<scount;i++)
     {     c[i].sum=c[i].price*c[i].quantity;
          printf(" %d.%s\t\t %d\t% d*%d\t\t%d\n",i+1,c[i].name,c[i].quantity,c[i].price,c[i].quantity,c[i].sum);
          total+=c[i].sum;     
     }
     printf(".........................................\n");
   printf("                                  total= %d",total);

     
}
//......................................................
void main()
{
  int num_items=0,choice=0,item_number=0,quantity=0,item_choice,flag=0;
  
/*input for start of the day*/
  printf("Enter number of items you for the whole day??\n");
  scanf("%d",&num_items);
  canteen_guy(num_items);

  //custiomer thing starts
//  c=(token*)malloc(icount*sizeof(token));
  while(1)//infinite customers
  {    
      display_items();
      while(1)//for the present customer;
      {
         printf("\n customer choice\n 1.insertion\n 2.deletion\n 3.exit\n");//for canteen guy
         scanf("%d",&choice); 
        switch(choice)        
         {
            case 1:c=(token*)malloc(icount*sizeof(token));
                   scount=0; 
                   while(1)//asking n items  from customer
                   {    printf("\ndo you want more items 1.yes\n 2.no\n");
                        scanf("%d",&item_choice);
                      switch(item_choice)
                      {  
                        case 1: printf("\nenter item_number and quantity\n");
                               scanf("%d%d",&item_number,&quantity);
                               insert(item_number,quantity);
                               break;
                        case 2:flag=1;
                               break;
                        default:printf("\nfuckyou\n");
                     }
                   if(flag)
                      break;
                  }
                      
           case 4:token_print();
                   
           case 2:while(1)//asking deletion of items  from customer
                   {    printf("\ndo you want to delete items  1.yes 2.no\n");
                        scanf("%d",&item_choice);
                      switch(item_choice)
                      {
                        case 1: printf("\nenter item_number and quantity\n");
                               scanf("%d%d",&item_number,&quantity);
                               delete(item_number,quantity);
                               flag=0;
                                 
                               break;
                        case 2:flag=1;
                               break;
                        default:printf("\nwrong input\n");
                     }
                   if(flag)
                      break;
                  }
                  break;
          case 3:exit(0); 
                                                   
          default:printf("\nvalid choice plis\n");
                  break;
        }
       if(flag)
          break;
      }
    free(c);
   printf("\nnext customer\n");
 }
}
