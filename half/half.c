// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    float bill = bill_amount;
    float tax = tax_percent / 100;
    int tip = tip_percent /100;

    printf("You will owe $%.2f each!\n", half(bill, tax, tip));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // Tax percent
    float bill_after_tax = bill * tax + bill;
    float bill_after_tip = bill_after_tax * tip + bill_after_tax;

    float split = bill_after_tip / 2;
    return split;
}
