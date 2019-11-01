#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>


enum
{
    NOROOTS,
    INFROOTS,
    ERROR,
    ONEROOT,
    TWOROOTS
};


const int MAXCOEFF = 3;
const int MAXWRONG = 7;
const double EPS = 1e-12;

/**
* Square equation solver function
* \param [in] text[] Welcome text.
* \return Massive with entered numbers
* \note Finish the program if user input wrong data too many times
*/
double* Input(const char text[]);

/**
* Double massive filling in function
* \param [in] MasSize Size of massive.
* \param [in] num Number to fill.
* \param [out] mas[] Massive.
* \note Filling in massive with double number that user want
*/
void Fill_In(double mas[], int MasSize, double num);

/**
* Square equation solver function
* \param [in] coefs[] coefficients.
* \param [out] *x1_ptr Pointer to first root.
* \param [out] *x2_ptr Pointer to second root.
* \return Number of roots
* \note Returns INFROOTS if equation has infinity amount of roots,
* NOROOTS if equation hasn't any roots,
* ONEROOT if equation has one root,
* TWOROOTS if equation has two roots.
*/
int SolveSquare(double coefs[], double* x1_ptr, double* x2_ptr);

/**
* Linear equation solver function
* \param [in] b First coefficient.
* \param [in] c First coefficient.
* \param [out] *x1_ptr Pointer to root.
* \return Number of roots
* \note Returns INFROOTS if equation has infinity amount of roots,
* NOROOTS if equation hasn't any roots,
* ONEROOT if equation has one root.
*/
int SolveLinear(double b, double c, double* x1_ptr);

/**
* Two double numbers comparing function
* \param [in] n1 First number.
* \param [in] n2 Second number.
* \return True or False
* \note Returns 1 if numbers are equal,
* 0 if numbers are not equal.
*/
int IsEqual(double n1, double n2);



int main()
{
    printf("This program solves square equations\n");

    double* coefs = Input("Input coefficients a, b, c.\n");

    double x1 = NAN, x2 = NAN;

    int nRoots = SolveSquare(coefs, &x1, &x2);

    switch(nRoots)
    {
        case NOROOTS: printf("No roots\n");
                break;
        case ONEROOT: printf("x = %lg\n", x1);
                break;
        case TWOROOTS: printf("x1 = %lg\nx2 = %lg\n", x1, x2);
                break;
        case INFROOTS: printf("Infinite number of roots\n");
                break;
        case ERROR: printf("ERROR_1\n");
                break;
        default: printf("ERROR\n");
                break;
    }

    free(coefs);

    return 0;
}


double* Input(const char text[])
{
    double* data = (double*)calloc(MAXCOEFF, sizeof(data[0]));
    Fill_In(data, MAXCOEFF, NAN);
    printf("%s", text);

    int wrong = 0;

    for(int i = 0; i < MAXCOEFF; i++)
    {
        printf("\r[%d/%d]: ", i+1, MAXCOEFF);

        if (scanf("%lg", &data[i]) != 1)
        {
            scanf("%*[^\n]");
            i--;
            wrong++;
        }

        assert(wrong < MAXWRONG);
    }

    return data;
}

void Fill_In(double mas[], int MasSize, double num)
{
    for(int i = 0; i < MasSize; i++)
    {
        mas[i] = num;
    }
}

int SolveSquare(double coefs[], double* x1_ptr, double* x2_ptr)
{

    double a = coefs[0];
    double b = coefs[1];
    double c = coefs[2];

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1_ptr != NULL);
    assert(x2_ptr != NULL);
    assert(x1_ptr != x2_ptr);

    if(IsEqual(a, 0))
        return (SolveLinear(b, c, x1_ptr));
    else if(IsEqual(c, 0))
    {
        if(IsEqual(b, 0))
        {
            *x1_ptr = 0;
            *x2_ptr = NAN;
            return ONEROOT;
        }
        else
        {
            *x1_ptr = 0;
            return (SolveLinear(a, b, x2_ptr) + 1);
        }
    }

    else
    {
        double d = b*b - 4*a*c;
        if (d < 0) return (NOROOTS);

        else if (IsEqual(d, 0))
        {
            *x1_ptr = -b/(2*a);
            *x2_ptr = NAN;
            return (ONEROOT);
        }
        else if (d > 0)
        {
            double sqrt_d = sqrt(d);
            *x1_ptr = (-b + sqrt_d)/(2*a);
            *x2_ptr = (-b - sqrt_d)/(2*a);
            return (TWOROOTS);
        }
    }
    return(ERROR);

}


int SolveLinear(double b, double c, double* x1_ptr)
{
    if (IsEqual(b, 0))
    {
        if (IsEqual(c, 0))
            return(INFROOTS);
        else
            return(NOROOTS);
    }
    else if(IsEqual(c, 0))
    {
        *x1_ptr = 0;
        return (ONEROOT);
    }
    else
    {
        *x1_ptr = -c/b;
        return (ONEROOT);
    }
}


int IsEqual(double n1, double n2)
{
    return (abs(n1 - n2) < EPS);
}
