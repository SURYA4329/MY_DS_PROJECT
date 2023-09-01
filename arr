#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define m_s 10000

int pre(char o)
{
    switch(o)
    {
        case'+':
            return 1;
        case'-':
            return 1;
        case'*':
            return 2;
        case'/':
            return 2;
        case'^':
            return 3;
        default:
            return -1;
    }
}
int op(char p)
{
    return (p == '+'||p == '-'||p == '*'||p == '/'||p == '^');
}
char* intopost(char* a)
{
    int i,j=0;
    int l = strlen(a);
    char* b = (char*)malloc(sizeof(char)*(l+2));
    char s[m_s];
    int top = -1;
    
    for(i=0;i<l;i++)
    {
        if(a[i] == ' '||a[i] == '\t')
        {
            continue;
        }
        
        if(isalnum(a[i]))
        {
            b[j++] = a[i];
        }
        else if(a[i] == '(')
        {
            s[++top] = a[i];
        }
        else if(a[i] == ')')
        {
            while(top>-1 && s[top]!='(')
            {
                b[j++] = s[top--];
               
            }
             if(top>-1 && s[top]!='(')
                {
                    return "invalid";
                }
                else
                {
                    top--;
                }
        }
        else if(op(a[i]))
        {
            while(top>-1 && pre(s[top])>=pre(a[i]))
            {
                b[j++] = s[top--];
               
            }
             s[++top] = a[i];
        }
    }
    
    while(top>-1)
    {
        if(s[top] == '(')
        {
            return "invalid";
        }
        b[j++] = s[top--];
    }
    b[j] = '\0';
    return b;
}
int main()
{
    char a[m_s];
    printf("Enter the infix expression:");
    gets(a);
    
    char* b = intopost(a);
    printf("postfix expression: %s\n",b);
}
