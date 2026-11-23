#include<stdio.h>
#include<ctype.h>


#define TOTAL_Q     5
#define MARKS_EACH  2
#define TOTAL_MARKS (TOTAL_Q * MARKS_EACH)

struct Question {
    char question[200];
    char options[4][100];
    char answer;
};

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void showQuestion(struct Question q, int number) {
    printf("\nQuestion %d: %s\n", number, q.question);
    for (int j = 0; j < 4; j++) {
        printf("%c. %s\n", 'A' + j, q.options[j]);
    }
}

char getAnswer(void) {
    char ans;
    while (1) {
        printf("Enter your answer (A/B/C/D): ");
        if (scanf(" %c", &ans) != 1) {
            return -1;
        }
        clearBuffer();                      
        ans = toupper((unsigned char)ans);
        if (ans >= 'A' && ans <= 'D') {
            return ans;
        }
        printf("Invalid choice! Try again.\n");
    }
}
void showReport(const char *name, int score) {
    float percentage = ((float)score / TOTAL_MARKS) * 100;

    printf("\n================================\n");
    printf("          SCORE REPORT\n");
    printf("================================\n");
    printf("Participant: %s\n", name);
    printf("Total Marks: %d\n", TOTAL_MARKS);
    printf("Obtained Marks: %d\n", score);
    printf("Percentage: %.2f%%\n", percentage);

    if (percentage >= 80) {
        printf("Performance: Excellent\n");
    } else if (percentage >= 60) {
        printf("Performance: Good\n");
    } else if (percentage >= 40) {
        printf("Performance: Average\n");
    } else {
        printf("Performance: Needs Improvement\n");
    }

    printf("================================\n");
    printf("       THANK YOU FOR PLAYING!\n");
    printf("================================\n");
}

int main(void) {
    struct Question q[TOTAL_Q] = {
        {
            "C is which type of language?",
            {"Markup language", "Query language", "Procedural programming language", "Scripting-only language"},
            'C'
        },
        {
            "Who is known as the father of C language?",
            {"Dennis Ritchie", "James Gosling", "Bjarne Stroustrup", "Charles Babbage"},
            'A'
        },
        {
            "Which symbol ends a C statement?",
            {".", ":", ",", ";"},
            'D'
        },
        {
            "Which function is used to display output in C?",
            {"scanf()", "printf()", "main()", "getchar()"},
            'B'
        },
        {
            "Which data type stores whole numbers?",
            {"float", "char", "int", "double"},
            'C'
        }
    };

    char name[50];
    char ans;
    int score = 0;

    printf("================================\n");
    printf("   QUIZ AND SCORE MANAGEMENT\n");
    printf("================================\n");

    printf("Enter your name: ");
    if (scanf(" %49[^\n]", name) != 1) {
        return 1;
    }
    clearBuffer();

    printf("\nWelcome, %s!\n", name);
    printf("Each correct answer carries %d marks.\n", MARKS_EACH);
    printf("There is no negative marking.\n");

    for (int i = 0; i < TOTAL_Q; i++) {
        showQuestion(q[i], i + 1);
        ans = getAnswer();

        if (ans == -1) {
            printf("\nInput ended. Quiz stopped.\n");
            break;
        }

        if (ans == q[i].answer) {
            printf("Correct answer!\n");
            score += MARKS_EACH;
        } else {
            printf("Wrong answer! Correct answer is %c.\n", q[i].answer);
        }
    }

    showReport(name, score);
    return 0;
}

