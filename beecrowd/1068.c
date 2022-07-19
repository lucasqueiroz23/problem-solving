#include <stdio.h>
#include <stdlib.h>

typedef struct parenthesisPositions
{
    int openingPosition;
    int closingPosition;
    
} parenthesisPositions;

typedef struct parenthesisInformation
{
    int numberOfClosingParenthesis;
    int numberOfOpeningParenthesis;
    parenthesisPositions *positions;
    
} parenthesisInformation;

typedef struct expressionPointers
{
    int pointerForOpeningParenthesis;
    int pointerForClosingParenthesis;

}pointers;

void initializeParenthesisInfo(parenthesisInformation *pInfo, int SIZE_OF_EXPRESSION)
{
    pInfo->numberOfClosingParenthesis = 0;
    pInfo->numberOfOpeningParenthesis = 0;
    pInfo->positions = malloc(SIZE_OF_EXPRESSION*sizeof(parenthesisPositions));

}

int getStringSize(char *string)
{
    int i = 0;
    while(string[i] != '\0')
        i++;

    int stringSize = i;
    
    return stringSize;
}

void getParenthesisPositions(parenthesisInformation *parenthesisInfo, pointers *pointers, int SIZE_OF_EXPRESSION, char *expression)
{
    for(int i = 0; i< SIZE_OF_EXPRESSION; i++)
        {
            parenthesisInfo->positions[i].openingPosition = -1;
            parenthesisInfo->positions[i].closingPosition = -1;
            
            if(expression[i] == '('){
                
                parenthesisInfo->numberOfOpeningParenthesis++;
                parenthesisInfo->positions[pointers->pointerForOpeningParenthesis].openingPosition = i;
                pointers->pointerForOpeningParenthesis++;
            }
            
            if(expression[i] == ')'){
                
                parenthesisInfo->numberOfClosingParenthesis++;
                parenthesisInfo->positions[pointers->pointerForClosingParenthesis].closingPosition = i;
                pointers->pointerForClosingParenthesis++;
                
            }
        }

}

int getBiggestBetweenTwoIntegers(int firstInteger, int secondInteger)
{
    int biggest = -1;

    if(firstInteger>biggest)
        biggest = firstInteger;
    if(secondInteger>biggest)
        biggest = secondInteger;

    return biggest;

}

int checksIfParenthesisClosesBeforeOpens(parenthesisInformation *parenthesisInfo, int lastParenthesisPosition)
{
    for(int i = 0; i<=lastParenthesisPosition;i++)
        if(parenthesisInfo->positions[i].closingPosition < parenthesisInfo->positions[i].openingPosition)
            return 1;

    return 0;
}

void initializeExpressionPointers(pointers *pointers)
{
    pointers->pointerForClosingParenthesis = 0;
    pointers->pointerForOpeningParenthesis = 0;
}

int main()
{
    
    char mathematicalExpression[1001];
    
    while(scanf("%s",mathematicalExpression)!=EOF)
    {
        parenthesisInformation *parenthesisInfo = malloc(sizeof(parenthesisInformation));

        int SIZE_OF_EXPRESSION = getStringSize(mathematicalExpression);
        initializeParenthesisInfo(parenthesisInfo,SIZE_OF_EXPRESSION);
        
        pointers *pointers = malloc(sizeof(pointers));
        initializeExpressionPointers(pointers);


        getParenthesisPositions(parenthesisInfo,pointers,SIZE_OF_EXPRESSION,mathematicalExpression);
        
        int lastParenthesisPosition = getBiggestBetweenTwoIntegers(pointers->pointerForClosingParenthesis,pointers->pointerForOpeningParenthesis);
        
        int bool_parenthesisClosesBeforeOpens = checksIfParenthesisClosesBeforeOpens(parenthesisInfo,lastParenthesisPosition);
        
        if(parenthesisInfo->numberOfClosingParenthesis != parenthesisInfo->numberOfOpeningParenthesis || bool_parenthesisClosesBeforeOpens == 1)
            printf("incorrect\n");
        else 
            printf("correct\n");
        
        free(parenthesisInfo->positions);
        free(parenthesisInfo);
        free(pointers);

    }
    
    
    return 0;
}
