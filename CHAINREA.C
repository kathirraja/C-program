#include<stdio.h>
#include<conio.h>
int a[8][8],i,j,k=1;
int ca[8][8];
void print(int,int);
void initial();
void split(int r, int c);
void copy();

void main()
{ int r,c;
  clrscr();
  initial();
  copy();
  while(k<20)
  {  clrscr();
     print(r,c);
     switch(k%2)
     {
       case 0:
	  ST1:
	  printf("\nplayer 1 \n");
	  printf("enter row & col(r,c) : ");
	  scanf("%d,%d",&r,&c);
	  r--;  c--;
	  if(0<=r && r<=7 && 0<=c && c<=7)
	  {
	    a[r][c]+=1;
	    split(r,c);
	    k++;
	  }
	  else
	    goto ST1;
	  break;
       case 1:
	  ST2:
	  printf("\nplayer 2 \n");
	  printf("enter row & col(r,c) : ");
	  scanf("%d,%d",&r,&c);
	  r--; c--;
	  if(0<=r && r<=7&& 0<=c && c<=7)
	  {
	    a[r][c]+=1;
	    split(r,c);
	    k++;
	  }
	  else
	    goto ST2;
	  break;
     }
    }
   getch();
}
void initial()
{ for(i=0;  i<8;  i++)
    {
      for(j=0;  j<8;  j++)
	   a[i][j]=0;
     }
}
void copy()
{ for(i=0;  i<8;  i++)
    {
      for(j=0;  j<8;  j++)
	  ca[i][j]=a[i][j];
     }

}
void print(int r,int c)
{  clrscr();
   printf("|___|____________________________________________________________\n");
   printf("|___|   1\t2\t3\t4\t5\t6\t7\t8\n");
   printf("|___|____________________________________________________________\n| 1 |");
  for(i=0;  i<8;  i++)
       { for(j=0;  j<8;  j++)

	  { if(a[i][j]==0)
	      printf("\t0");
  /*	    else if((a[i][j]!=ca[i][j]) && (k%2==0))
	      printf("\t%dX",a[i][j]);
	    else if(a[i][j]!=ca[i][j] && k%2==1 )
	      printf("\t%dY",a[i][j]);          */
	     else
		 printf("\t%d",a[i][j]);
  /*	    if(r==i && c==j && k==0)
	       printf("\t%d",a[i][j]);
	    else if(r==i && c==j && k==1)
	    {   textcolor(1);
		printf("\t");
		cprintf("%d",a[i][j]);   }
	    else
	       printf("\t%d",a[i][j]);         */
	  }
	 printf(" ||");
	 if(i+2!=9)
	  printf("\n| %d |",i+2);
       }   delay(500);
}
void split(int r,int c)
{ int flag=1;
  goto IN;
  nosound();
  OUT:
  while(flag==1)
  { for(r=0; r<8; r++)
    {for(c=0; c<8; c++)
     { IN:
     sound(r+10);
       flag=0;
       if( (a[r][c]>=2) &&((r==0 && c==0 )||(r==0 && c==7)||(r==7 && c==0)||(r==7 && c==7)) )
       { copy();
	 a[r][c]=a[r][c]-2;
	 if(r==0 && c==0 )
	 {
	  a[r][c+1]+=1;
	  a[r+1][c]+=1;
	  print(r,c);
	 }
	 else if(r==0 && c==7)
	 {
	  a[r][c-1]+=1;
	  a[r+1][c]+=1;
	  print(r,c);
	 }
	 else if(r==7 && c==0)
	 {
	  a[r-1][c]+=1;
	  a[r][c+1]+=1;
	  print(r,c);
	 }
	 else if(r==7 && c==7)
	 {
	  a[r][c-1]+=1;
	  a[r-1][c]+=1;
	  print(r,c);
	 }
	    flag=1;
       }
       else if(  (a[r][c]>=3) && ((0<c && c<7  && r==0)||(0<r && r<7 && c==0)||(0<r && r<7 && c==7)||(0<c && c<7 && r==7))  )
       { copy();
	 a[r][c]=a[r][c]-3;
	 if(0<c && c<7 && r==0)
	 {
	  a[r][c-1]+=1;
	  a[r][c+1]+=1;
	  a[r+1][c]+=1;
	  print(r,c);
	 }
	 if(0<r && r<7 && c==0)
	 {
	  a[r-1][c]+=1;
	  a[r+1][c]+=1;
	  a[r][c+1]+=1;
	  print(r,c);
	 }
	 if(0<r && r<7 && c==7)
	 {
	  a[r-1][c]+=1;
	  a[r+1][c]+=1;
	  a[r][c-1]+=1;
	  print(r,c);
	 }
	 if(0<c && c<7 && r==7)
	 {
	  a[r][c-1]+=1;
	  a[r][c+1]+=1;
	  a[r-1][c]+=1;
	  print(r,c);
	 }
	 flag=1;
       }
       if((0<r && r<7) && (0<c && c<7) && (a[r][c]>=4))
	{ copy();
	  a[r][c]=a[r][c]-4;
	  a[r-1][c]+=1;
	  a[r][c-1]+=1;
	  a[r][c+1]+=1;
	  a[r+1][c]+=1;
	  flag=1;
	  print(r,c);
	}
      if(flag==1)
	goto OUT;
     }
    }
  }
  nosound();
}