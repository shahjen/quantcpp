#include "vanilla_option.h"
#include "math.h"

void VanillaOption::init()
{
    strike = 100.0;
    rho = 0.05; // 5%
    time_to_expiry = 1.0; // 1yr to expiry
    stock_price = 100.0; // ATM Option
    sigma = 0.2; //20% vol
}

void VanillaOption::copy(const VanillaOption& rhs)
{
    strike = rhs.get_strike();
    rho = rhs.get_rho();
    time_to_expiry = rhs.get_time_to_expiry();
    stock_price = rhs.get_stock_price();
    sigma = rhs.get_sigma();
}

VanillaOption::VanillaOption()
{
    init();
}

VanillaOption::VanillaOption(const double& _strike, const double& _rho, const double& _time_to_expiry, const double& _stock_price, const double& _sigma)
{
    strike = _strike;
    rho = _rho;
    time_to_expiry = _time_to_expiry;
    stock_price = _stock_price;
    sigma = _sigma;
}

VanillaOption::VanillaOption(const VanillaOption& rhs)
{
    copy(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs)
{
    if(this != &rhs) copy(rhs); 
    // only copy if not already equal. Will be useful for larger objects
    return *this;
}

VanillaOption::~VanillaOption()
{

}

double VanillaOption::N(const double& x) const
{
    return 0.5 * (1 + erf(x / sqrt(2.0)));
}

double VanillaOption::get_strike() const
{
    return strike;
};
double VanillaOption::get_rho() const
{
    return rho;
};
double VanillaOption::get_time_to_expiry() const
{
    return time_to_expiry;
};
double VanillaOption::get_stock_price() const
{
    return stock_price;
};
double VanillaOption::get_sigma() const
{
    return sigma;
};
double VanillaOption::calc_call_price() const
{
    double sigma_sqrt_t{sigma*sqrt(time_to_expiry)};
    double d1{(log(stock_price/strike) + (rho+sigma*sigma*0.5))/sigma_sqrt_t};
    double d2{d1-sigma_sqrt_t};
    return stock_price*N(d1) - strike*exp(-rho*time_to_expiry)*(d2);
};
double VanillaOption::calc_put_price() const
{
    double sigma_sqrt_t{sigma*sqrt(time_to_expiry)};
    double d1{(log(stock_price/strike) + (rho+sigma*sigma*0.5))/sigma_sqrt_t};
    double d2{d1-sigma_sqrt_t};
    return strike*exp(-rho*time_to_expiry)*(-d2) - stock_price*N(-d1);
};