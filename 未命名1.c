#include<stdio.h>
#include<string.h>
#define ll long long
char s[10000];
char a[1000];
int top=0;
void push(char t)
{	top++;
	s[top]=t;
	
}
char pop()
{
	char o=s[top];
	top--;
	return o;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		int h=strlen(a);
		int i,j;
		int f=0;
		for(i=0;i<h;i++)
		{
			if(a[i]=='<')
			push(a[i]);
			else if(a[i]=='(')
			{
				if(s[top]!='<')
				push(a[i]);
				else 
				{
					f=1;
					break;
				}
			}
			else if(a[i]=='[')
			{
				if(s[top]!='('&&s[top]!='<')
				push(a[i]);
				else 
				{
					f=1;
					break;
				}
			}else if(a[i]=='{')
			{
				if(s[top]!='<'&&s[top]!='('&&s[top]!='[')
				push(a[i]);
				else 
				{
					f=1;
					break;
				}
			}
		
			else if(a[i]=='>')
			{
				if(s[top]!='<')
				{
					f=1;
					break;
				}
				else pop();
			}
			else if(a[i]==']')
			{
				if(s[top]!='[')
				{
					f=1;
					break;
				}
				else pop();
			}
			else if(a[i]=='}')
			{
				if(s[top]!='{')
				{
					f=1;
					break;
				}
				else pop();
			}
			else if(a[i]==')')
			{
				if(s[top]!='(')
				{
					f=1;
					break;
				}
				else pop();
			}
			
		}
		if(f==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
