
#include <stdio.h>

#define MAX 100

struct Term {
    int coeff;
    int exp;
};

struct Term p[3 * MAX];
int n1, n2;

// Function to read first polynomial
void readFirstPolynomial() {
    int i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter coefficient and exponent in descending order:\n");

    for (i = 0; i < n1; i++) {
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
}

// Function to read second polynomial
void readSecondPolynomial() {
    int j;

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter coefficient and exponent in descending order:\n");

    for (j = 0; j < n2; j++) {
        scanf("%d%d", &p[n1 + j].coeff, &p[n1 + j].exp);
    }
}

// Function to add two polynomials
int addPolynomial() {
    int i = 0, j = n1, k = n1 + n2;

    while (i < n1 && j < n1 + n2) {

        if (p[i].exp == p[j].exp) {
            p[k].coeff = p[i].coeff + p[j].coeff;
            p[k].exp = p[i].exp;

            if (p[k].coeff != 0)
                k++;

            i++;
            j++;
        }

        else if (p[i].exp > p[j].exp) {
            p[k] = p[i];
            k++;
            i++;
        }

        else {
            p[k] = p[j];
            k++;
            j++;
        }
    }

    // Copy remaining terms of first polynomial
    while (i < n1) {
        p[k] = p[i];
        k++;
        i++;
    }

    // Copy remaining terms of second polynomial
    while (j < n1 + n2) {
        p[k] = p[j];
        k++;
        j++;
    }

    return k;
}

// Function to display resultant polynomial
void displayPolynomial(int k) {
    int i, c;

    printf("\nResultant Polynomial:\n");

    for (i = n1 + n2; i < k; i++) {

        if (i > n1 + n2 && p[i].coeff > 0)
            printf(" + ");

        else if (p[i].coeff < 0)
            printf(" - ");

        c = p[i].coeff;

        if (c < 0)
            c = -c;

        printf("%dx^%d", c, p[i].exp);
    }

    printf("\n");
}

int main() {
    int k;

    readFirstPolynomial();

    readSecondPolynomial();

    k = addPolynomial();

    displayPolynomial(k);

    return 0;
}
