#include <iostream>
#include <string.h>
#define TSIZE 128
using namespace std;

int parsingTable[100][TSIZE];

char terminalSet[TSIZE];

char nonterminalSet[26];

struct Production {
    char str[100];
    int len;
} productions[20];

int numberOfProductions;
char firstSet[26][TSIZE];
char followSet[26][TSIZE];

char firstRHS[100][TSIZE];

int isNonterminal(char c) {
    return c >= 'A' && c <= 'Z';
}

void readGrammarFromFile() {
    FILE* filePointer;
    filePointer = fopen("TestCase.txt", "r");
    char buffer[255];
    int i, j;
    while (fgets(buffer, sizeof(buffer), filePointer)) {
        printf("%s", buffer);
        j = 0;
        nonterminalSet[buffer[0] - 'A'] = 1;
        for (i = 0; i < strlen(buffer) - 1; ++i) {
            if (buffer[i] == '|') {
                ++numberOfProductions;
                productions[numberOfProductions - 1].str[j] = '\0';
                productions[numberOfProductions - 1].len = j;
                productions[numberOfProductions].str[0] = productions[numberOfProductions - 1].str[0];
                productions[numberOfProductions].str[1] = productions[numberOfProductions - 1].str[1];
                productions[numberOfProductions].str[2] = productions[numberOfProductions - 1].str[2];
                j = 3;
            } else {
                productions[numberOfProductions].str[j] = buffer[i];
                ++j;
                if (!isNonterminal(buffer[i]) && buffer[i] != '-' && buffer[i] != '>') {
                    terminalSet[buffer[i]] = 1;
                }
            }
        }
        productions[numberOfProductions].len = j;
        ++numberOfProductions;
    }
}

void addToFirstSet_A_to_FollowSet_B(char A, char B) {
    int i;
    for (i = 0; i < TSIZE; ++i) {
        if (i != '^')
            followSet[B - 'A'][i] = followSet[B - 'A'][i] || firstSet[A - 'A'][i];
    }
}

void addToFollowSet_A_to_FollowSet_B(char A, char B) {
    int i;
    for (i = 0; i < TSIZE; ++i) {
        if (i != '^')
            followSet[B - 'A'][i] = followSet[B - 'A'][i] || followSet[A - 'A'][i];
    }
}

void computeFollowSet() {
    int t = 0;
    int i, j, k, x;
    while (t++ < numberOfProductions) {
        for (k = 0; k < 26; ++k) {
            if (!nonterminalSet[k])    continue;
            char nonterminal = k + 'A';
            for (i = 0; i < numberOfProductions; ++i) {
                for (j = 3; j < productions[i].len; ++j) {
                    if (nonterminal == productions[i].str[j]) {
                        for (x = j + 1; x < productions[i].len; ++x) {
                            char sc = productions[i].str[x];
                            if (isNonterminal(sc)) {
                                addToFirstSet_A_to_FollowSet_B(sc, nonterminal);
                                if (firstSet[sc - 'A']['^'])
                                    continue;
                            } else {
                                followSet[nonterminal - 'A'][sc] = 1;
                            }
                            break;
                        }
                        if (x == productions[i].len)
                            addToFollowSet_A_to_FollowSet_B(productions[i].str[0], nonterminal);
                    }
                }
            }
        }
    }
}

void addToFirstSet_A_to_FirstSet_B(char A, char B) {
    int i;
    for (i = 0; i < TSIZE; ++i) {
        if (i != '^') {
            firstSet[B - 'A'][i] = firstSet[A - 'A'][i] || firstSet[B - 'A'][i];
        }
    }
}

void computeFirstSet() {
    int i, j;
    int t = 0;
    while (t < numberOfProductions) {
        for (i = 0; i < numberOfProductions; ++i) {
            for (j = 3; j < productions[i].len; ++j) {
                char sc = productions[i].str[j];
                if (isNonterminal(sc)) {
                    addToFirstSet_A_to_FirstSet_B(sc, productions[i].str[0]);
                    if (firstSet[sc - 'A']['^'])
                        continue;
                } else {
                    firstSet[productions[i].str[0] - 'A'][sc] = 1;
                }
                break;
            }
            if (j == productions[i].len)
                firstSet[productions[i].str[0] - 'A']['^'] = 1;
        }
        ++t;
    }
}

void addToFirstSet_A_to_FirstRHS_B(char A, int B) {
    int i;
    for (i = 0; i < TSIZE; ++i) {
        if (i != '^')
            firstRHS[B][i] = firstSet[A - 'A'][i] || firstRHS[B][i];
    }
}

void computeFirstRHS() {
    int i, j;
    int t = 0;
    while (t < numberOfProductions) {
        for (i = 0; i < numberOfProductions; ++i) {
            for (j = 3; j < productions[i].len; ++j) {
                char sc = productions[i].str[j];
                if (isNonterminal(sc)) {
                    addToFirstSet_A_to_FirstRHS_B(sc, i);
                    if (firstSet[sc - 'A']['^'])
                        continue;
                } else {
                    firstRHS[i][sc] = 1;
                }
                break;
            }
            if (j == productions[i].len)
                firstRHS[i]['^'] = 1;
        }
        ++t;
    }
}

int main() {
    printf("The input is :\n");
    readGrammarFromFile();
    followSet[productions[0].str[0] - 'A']['$'] = 1;
    computeFirstSet();
    computeFollowSet();
    computeFirstRHS();
    int i, j, k;

    cout<<endl<<endl;
    for (i = 0; i < numberOfProductions; ++i) {
        if (i == 0 || (productions[i - 1].str[0] != productions[i].str[0])) {
            char c = productions[i].str[0];
            printf("FIRST OF %c: ", c);
            for (j = 0; j < TSIZE; ++j) {
                if (firstSet[c - 'A'][j]) {
                    printf("%c ", j);
                }
            }
            cout<<endl;
        }
    }

    cout<<endl;
    for (i = 0; i < numberOfProductions; ++i) {
        if (i == 0 || (productions[i - 1].str[0] != productions[i].str[0])) {
            char c = productions[i].str[0];
            printf("FOLLOW OF %c: ", c);
            for (j = 0; j < TSIZE; ++j) {
                if (followSet[c - 'A'][j]) {
                    printf("%c ", j);
                }
            }
            cout<<endl;
        }
    }

    cout<<endl;
    for (i = 0; i < numberOfProductions; ++i) {
        printf("FIRST OF %s: ", productions[i].str);
        for (j = 0; j < TSIZE; ++j) {
            if (firstRHS[i][j]) {
                printf("%c ", j);
            }
        }
        cout<<endl;
    }

    terminalSet['$'] = 1;
    terminalSet['^'] = 0;

    cout<<endl;
    printf("\n\t LL(1) PARSING TABLE \n\n");
    printf("%-10s", "");
    for (i = 0; i < TSIZE; ++i) {
        if (terminalSet[i])    printf("%-10c", i);
    }
    cout<<endl;
    int p = 0;
    for (i = 0; i < numberOfProductions; ++i) {
        if (i != 0 && (productions[i].str[0] != productions[i - 1].str[0]))
            p = p + 1;
        for (j = 0; j < TSIZE; ++j) {
            if (firstRHS[i][j] && j != '^') {
                parsingTable[p][j] = i + 1;
            } else if (firstRHS[i]['^']) {
                for (k = 0; k < TSIZE; ++k) {
                    if (followSet[productions[i].str[0] - 'A'][k]) {
                        parsingTable[p][k] = i + 1;
                    }
                }
            }
        }
    }
    k = 0;
    for (i = 0; i < numberOfProductions; ++i) {
        if (i == 0 || (productions[i - 1].str[0] != productions[i].str[0])) {
            printf("%-10c", productions[i].str[0]);
            for (j = 0; j < TSIZE; ++j) {
                if (parsingTable[k][j]) {
                    printf("%-10s", productions[parsingTable[k][j] - 1].str);
                } else if (terminalSet[j]) {
                    printf("%-10s", "");
                }
            }
            ++k;
            cout<<endl;
        }
    }
}
