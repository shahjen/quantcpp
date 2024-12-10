#pragma once VANILLA_OPTION_H
class VanillaOption
{
    private:
        void init();
        void copy(const VanillaOption& rhs);
        double strike; // Strike
        double rho; // risk-free rate
        double time_to_expiry; // time-to-expiry
        double stock_price; //Stock price
        double sigma; // Volatility of underlying
    public:
        VanillaOption();
        VanillaOption(const double& strike,
        const double& rho,
        const double& time_to_expiry,
        const double& stock_price,
        const double& sigma ); // Parametrized
        VanillaOption(const VanillaOption& rhs);
        VanillaOption& operator=(const VanillaOption& rhs); // Chained assignment
        virtual ~VanillaOption(); // Virtual destructor
        double get_strike() const;
        double get_rho() const;
        double get_time_to_expiry() const;
        double get_stock_price() const;
        double get_sigma() const;
        double calc_call_price() const;
        double calc_put_price() const;
};