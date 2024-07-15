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
        double total = hourWork * hourPay;
        cout << "Gross Pay = " << hourPay << "*" << hourWork << " = " << total << '\n';
    }
    void between40and60()
    {
        double total = (40 * hourPay) + ((hourWork - 40) * (hourPay * 1.5));
        cout << "Gross Pay = (40*" << hourPay << ") + ((" << hourWork << "-40) * (" << hourPay << "*1.5)) = " << total << '\n';
    }
    void moreThan60()
    {
        double total = (40 * hourPay) + (20 * (hourPay * 1.5)) + ((hourWork - 60) * (hourPay * 2));
        cout << "Gross Pay = (40*" << hourPay << ") + (20 * (" << hourPay << "*1.5))" << " + ((" << hourWork << "-60) * (" << hourPay << "*2)) = " << total << '\n';
    }
};

int main()
{
    double HP;
    double HW;
    GrossPay GP;

    cout << "Hour Worked = ";
    cin >> HW;
    GP.setHourWork(HW);

    cout << "Hour Pay = ";
    cin >> HP;
    GP.setHourPay(HP);

    if (HW > 0 && HW <= 40)
    {
        GP.lessThan40();
    }
    else if (HW > 0 && HW > 40 && HW <= 60)
    {
        GP.between40and60();
    }
    else if (HW > 0 && HW > 60)
    {
        GP.moreThan60();
    }
    else
    {
        cout << "Sorry Hour Worked need to be positive number." << '\n';
    }

    return 0;
}