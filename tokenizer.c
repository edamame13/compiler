#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    OPERATOR,
    PUNCTUATION,
    SEISU_KEYWORD,
    UNKNOWN
} TokenType;

void install()
{
    // 何らかの処理を行う（ここでは何もしない）
}

typedef struct
{
    TokenType type;
    char value[100];
    int internalCode; // アルファベットの内部コード
} Token;

// アルファベットに関連する内部コードを取得する関数
int getInternalCode(char letter)
{
    char internalCodes[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < sizeof(internalCodes) / sizeof(internalCodes[0]); i++)
    {
        if (internalCodes[i] == letter)
        {
            return i + 1; // 内部コードは1から始まると仮定します
        }
    }
    return -1; // 見つからない場合は-1を返す
}

// トークン数を数える関数
int tokenize(const char *input, int kodeTypes[][2])
{
    int i = 0;
    int k = -1;
    while (input[i] != '\0')
    {
        while (isspace(input[i]))
        {
            i++;
        }
        if (isalpha(input[i]))
        {
            int j = 0;
            Token token;
            token.type = 20;
            k++;
            while (isalnum(input[i]))
            {
                token.value[j++] = input[i++];
            }
            token.value[j] = '\0';

            // キーワードの判定
            if (strcmp(token.value, "CON") == 0)
            {
                token.type = 1;
                kodeTypes[k][0] = token.type;
                printf("Token: %s, Type: 1\n", token.value);
            }
            else if (strcmp(token.value, "ELSE") == 0)
            {
                token.type = 2;
                kodeTypes[k][0] = token.type;
                printf("Token: %s, Type: 2\n", token.value);
            }
            else if (strcmp(token.value, "LOOP") == 0)
            {
                token.type = 3;
                kodeTypes[k][0] = token.type;
                printf("Token: %s, Type: 3\n", token.value);
            }
            else if (strcmp(token.value, "IN") == 0)
            {
                token.type = 4;
                kodeTypes[k][0] = token.type;
                printf("Token: %s, Type: 4\n", token.value);
            }
            else if (strcmp(token.value, "OUT") == 0)
            {
                token.type = 5;
                kodeTypes[k][0] = token.type;
                printf("Token: %s, Type: 5\n", token.value);
            }
            else if (strcmp(token.value, "SEISU") == 0)
            {
                token.type = 6;
                kodeTypes[k][0] = token.type;
                printf("Token: %s, Type: 6\n", token.value);
            }
            else
            {

                token.internalCode = getInternalCode(token.value[0]);
                printf("Token: %s, Type: %d-%d\n", token.value, token.type, token.internalCode);
                kodeTypes[k][0] = token.type;
                kodeTypes[k][1] = token.internalCode;
            }
        }
        else if (isdigit(input[i]))
        {

            int j = 0;
            Token token;
            token.type = 200;
            while (isdigit(input[i]))
            {
                token.value[j++] = input[i++];
            }

            token.value[j] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = 200;
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {

            Token token;
            token.type = OPERATOR;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = OPERATOR;
        }
        else if (input[i] == ',')
        {

            Token token;
            token.type = 40;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '(')
        {

            Token token;
            token.type = 30;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == ')')
        {

            Token token;
            token.type = 31;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '<')
        {

            Token token;
            token.type = 62;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            if (input[i] == '-')
            {

                token.type = 50;
                token.value[1] = '-';
                token.value[2] = '\0';
                i++;
            }

            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '>')
        {

            Token token;
            token.type = 65;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '{')
        {

            Token token;
            token.type = 41;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '}')
        {

            Token token;
            token.type = 42;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '%')
        {

            Token token;

            token.type = 55;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else if (input[i] == '!')
        {

            Token token;
            token.type = PUNCTUATION;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            if (input[i] == '=')
            {

                token.type = 66;
                token.value[1] = '=';
                token.value[2] = '\0';
                i++;
            }

            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = token.type;
        }
        else
        {

            Token token;
            token.type = UNKNOWN;
            token.value[0] = input[i++];
            token.value[1] = '\0';
            printf("Token: %s, Type: %d\n", token.value, token.type);
            k++;
            kodeTypes[k][0] = UNKNOWN;
        }
    }

    printf("Alphabet Table:\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d\n", 'a' + i, getInternalCode('a' + i));
    }
    return k + 1;
}

int main()
{
    char input[1000];
    int kodeTypes[1000][2] = {0};
    scanf("%999[^\n]", input);
    printf("TokenType line:\n");
    // 指定された出力を行う部分

    int tokenCount = tokenize(input, kodeTypes);
    printf("\nKode contents (left column only):\n");
    for (int j = 0; j <= tokenCount - 1; j++)
    {
        printf("%d　", kodeTypes[j][0]);
    }

    printf("\nKode contents (both columns):\n");
    for (int j = 0; j <= tokenCount - 1; j++)
    {
        printf("%d-%d　", kodeTypes[j][0], kodeTypes[j][1]);
    }
    return 0;
}