/*Pay per hour = hourPay
work hour = hourWork
if 40 < hourWork < 60 then hourPay*1.5
but if hourWork > 60 then hourPay*2
*Dependents*
*/

#include <iostream>
using namespace std;

class GrossPay
{
private:
    double hourPay;
    double hourWork;

public:
    double total;
    void setHourPay(double HP)
    {
        hourPay = HP;
    }
    void setHourWork(double HW)
    {
        hourWork = HW;
    }
    void lessThan40()
    {
        total = hourWork * hourPay;
        cout << "Gross Pay = " << hourPay << "*" << hourWork << " = $" << total << '\n';
    }
    void between40and60()
    {
        total = (40 * hourPay) + ((hourWork - 40) * (hourPay * 1.5));
        cout << "Gross Pay = (40*" << hourPay << ") + ((" << hourWork << "-40) * (" << hourPay << "*1.5)) = $" << total << '\n';
    }
    void moreThan60()
    {
        total = (40 * hourPay) + (20 * (hourPay * 1.5)) + ((hourWork - 60) * (hourPay * 2));
        cout << "Gross Pay = (40*" << hourPay << ") + (20 * (" << hourPay << "*1.5))" << " + ((" << hourWork << "-60) * (" << hourPay << "*2)) = $" << total << '\n';
    }
    double getTotal() const
    {
        return total;
    }
};

class TaxableIncome : public GrossPay
{
private:
    double ND0, taxTotal; // Number of Dependents (ND)

public:
    void setNoD(int num)
    {
        ND0 = num;
    }

    void calculateTax(double grossPayTotal)
    {
        if (ND0 == 1)
        {
            taxTotal = grossPayTotal * (1 - 0.04);
            cout << "Taxable income = " << grossPayTotal << "* (1 - 0.04) = $" << getTaxTotal() << '\n';
        }
        else if (ND0 == 2)
        {
            taxTotal = grossPayTotal * (1 - 0.0775);
            cout << "Taxable income = " << grossPayTotal << "* (1 - 0.0775) = $" << getTaxTotal() << '\n';
        }
        else if (ND0 == 3)
        {
            taxTotal = grossPayTotal * (1 - 0.1125);
            cout << "Taxable income = " << grossPayTotal << "* (1 - 0.1125) = $" << getTaxTotal() << '\n';
        }
        else if (ND0 == 4)
        {
            taxTotal = grossPayTotal * (1 - 0.145);
            cout << "Taxable income = " << grossPayTotal << "* (1 - 0.145) = $" << getTaxTotal() << '\n';
        }
        else if (ND0 == 5)
        {
            taxTotal = grossPayTotal * (1 - 0.175);
            cout << "Taxable income = " << grossPayTotal << "* (1 - 0.175) = $" << getTaxTotal() << '\n';
        }
        else if (ND0 >= 6)
        {
            taxTotal = grossPayTotal * (1 - 0.2025);
            cout << "Taxable income = " << grossPayTotal << "* (1 - 0.2025) = $" << getTaxTotal() << '\n';
        }
    }

    double getTaxTotal()
    {
        return taxTotal;
    }
};

int main()
{
    double HP;
    double HW;
    int ND;

    GrossPay GP;
    TaxableIncome TaI;

    cout << "Enter the hours worked: ";
    cin >> HW;
    GP.setHourWork(HW);

    cout << "Enter the hourly pay: ";
    cin >> HP;
    GP.setHourPay(HP);

    cout << "Enter the number of dependents: ";
    cin >> ND;
    TaI.setNoD(ND);

    if (HW > 0 && HW <= 40)
    {
        GP.lessThan40();
    }
    else if (HW > 40 && HW <= 60)
    {
        GP.between40and60();
    }
    else if (HW > 60)
    {
        GP.moreThan60();
    }
    else
    {
        cout << "Invalid number of Working Hours." << '\n';
        return 1;
    }

    if (ND >= 0)
    {
        TaI.calculateTax(GP.getTotal());
    }
    else
    {
        cout << "Invalid number of dependents." << '\n';
        return 1;
    }

    return 0;
}