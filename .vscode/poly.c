#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
    float coef;
    int exp;
} Term;

void readPolynomial(Term poly[]);
void printPolynomial(Term poly[]);
void addPolynomials(Term poly1[], Term poly2[], Term result[]);

int main() {
    Term poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS];

    printf("Enter the first polynomial:\n");
    readPolynomial(poly1);

    printf("Enter the second polynomial:\n");
    readPolynomial(poly2);

    addPolynomials(poly1, poly2, result);

    printf("Result:\n");
    printPolynomial(result);

    return 0;
}

void readPolynomial(Term poly[]) {
    int i, num_terms;

    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    for (i = 0; i < num_terms; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%f %d", &poly[i].coef, &poly[i].exp);
    }
    poly[i].exp = -1; // sentinel
}

void printPolynomial(Term poly[]) {
    int i;

    for (i = 0; poly[i].exp != -1; i++) {
        printf("%.2fx^%d ", poly[i].coef, poly[i].exp);
        if (poly[i + 1].exp != -1 && poly[i + 1].coef > 0) {
            printf("+ ");
        }
    }
    printf("\n");
}

void addPolynomials(Term poly1[], Term poly2[], Term result[]) {
    int i = 0, j = 0, k = 0;

    while (poly1[i].exp != -1 && poly2[j].exp != -1) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k].coef = poly1[i].coef;
            result[k].exp = poly1[i].exp;
            i++;
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k].coef = poly2[j].coef;
            result[k].exp = poly2[j].exp;
            j++;
        } else {
            result[k].coef = poly1[i].coef + poly2[j].coef;
            result[k].exp = poly1[i].exp;
            i++;
            j++;
        }
        k++;
    }

    // add remaining terms of poly1
    while (poly1[i].exp != -1) {
        result[k].coef = poly1[i].coef;
        result[k].exp = poly1[i].exp;
        i++;
        k++;
    }

    // add remaining terms of poly2
    while (poly2[j].exp != -1) {
        result[k].coef = poly2[j].coef;
        result[k].exp = poly2[j].exp;
        j++;
        k++;
    }

    result[k].exp = -1; // sentinel
}
