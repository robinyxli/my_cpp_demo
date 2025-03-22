#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <time.h>
#include <chrono>

class BS_asset_sim {
public:
    BS_asset_sim(double drift, double vol, double initial_price, unsigned int seed)
        : miu(drift), sigma(vol), S_0(initial_price), set_seed(seed), norm(0.0, 1.0) {}

    std::vector<double> exact(double T, double t, int time_step, int n_sim) {
        double d_t = 1.0 / time_step;  
        int steps = int ((T - t) * time_step);
        std::vector<double> mc_avg(steps + 1, 0.0);
        mc_avg[0] = S_0;
        for (int j = 0; j < n_sim; j++){
            std::default_random_engine generator(set_seed + j); 
            std::vector<double> S(steps + 1);
            S[0] = S_0;

            for (int i = 0; i < steps; i++) {
                double W = norm(generator);
                S[i + 1] = S[i] * std::exp((miu - 0.5 * std::pow(sigma, 2)) * d_t + sigma * std::sqrt(d_t) * W);
                mc_avg[i + 1] += S[i + 1];
            }
        }
        for (int i = 1; i <= steps; i++) {
            mc_avg[i] /= n_sim;
        }

        return mc_avg;
    }

private:
    double miu;
    double sigma;
    double S_0;
    unsigned int set_seed;
    std::normal_distribution<double> norm;
};

int main() {

    double initial_price = 400.0;
    double drift = 0.05;
    double vol = 0.2;
    int time_step = 252;
    double T = 1.0;
    double t = 0.0;
    int n_sim = 1000;
    unsigned int seed = 10;

    BS_asset_sim sim(drift, vol, initial_price, seed); 
    std::vector<double> S_t = sim.exact(T, t, time_step, n_sim);

    std::cout << "MC Simulated Stock Price at Maturity:" << std::endl;
    std::cout << S_t[S_t.size() - 1] << std::endl;

    return 0;
}