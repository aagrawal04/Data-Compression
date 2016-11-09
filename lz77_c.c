#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L_LOOKAHEAD 3
#define L_SEARCH 5
typedef struct {
    short start;
    short length;
    char first_mismatch;
} reference;
int main(){
	char* original = "Hello World Hello"; 
	char *search = NULL, *lookahead = NULL; 
	char *m_search = NULL, *m_lookahead = NULL; 
	short s_search = 1; 
	//char *symbols;
	char *input = original;
	int i;

	reference *symbols;
	symbols=(reference *)malloc(sizeof(reference));
	 while (*(input + s_search) != '\0') {

        search = input;
        lookahead = input + s_search;

        printf("Search: [");
        for (i = 0; i < s_search; i++) {
            printf("%c", *(search + i));
        }
        printf("], lookahead: [");
        for (i = 0; i < L_LOOKAHEAD; i++) {
            if (*(lookahead + i) == '\0') break;
            printf("%c", *(lookahead + i));
        }
        printf("]\n");

        char *match = NULL;
        reference matchref = {0, 0, *lookahead};

        for (i = 0; i < s_search; i++) {

            if (*(search + i) == *lookahead) {

                match = search + i;

                do {
                    m_search = match;
                    m_lookahead = lookahead;

                    if (*m_search != *m_lookahead) {
                        break;
                    }

                    while (*(++m_search) == *(++m_lookahead) && *m_lookahead != '\0') {
                    }

                    if (m_search - match >= matchref.length) {
                        matchref.start = lookahead - match;
                        matchref.length = m_search - match;
                        matchref.first_mismatch = *m_lookahead;
                    }

                } while (++match != lookahead);

            }
        }

        printf("%i,%i,%c\n", matchref.start, matchref.length, matchref.first_mismatch);

        if (matchref.length > 0) {
            if (s_search + matchref.length + 1 <= L_SEARCH) {
                s_search += matchref.length + 1;
            } else {
                input += matchref.length + 1;
            }
        } else {
            if (s_search < L_SEARCH) {
                s_search++;
            } else {
                input++;
            }
        }
    }

    printf("\nOriginal version:  \"%s\"\n", original);
    printf("Original length: %zu\n", strlen(original));
    printf("Compressed version: \"");
    //reference *symbol = NULL;
    return 0;
}