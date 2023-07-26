#include "ODE.h"
#include "Integrate.h"
#include "TimeSeries.h"

#include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int argc, char** argv){ 
      
      Eigen::VectorXd init_state = Eigen::VectorXd::Ones(3);
      double h = 0.01;
      Eigen::VectorXd param(3);
      param(0) = 10.0;
      param(1) = 8.0/3.0;
      param(2) = 28.0;

      Numint::ODE_L63 default_l63 = Numint::ODE_L63(param);
      
      Numint::Integrate::RK4 rk4_integrator = Numint::Integrate::RK4();
      Numint::Integrate::Euler euler_integrator = Numint::Integrate::Euler();

      Eigen::VectorXd r_1 = rk4_integrator.integrate(1, h, init_state, default_l63);
      Eigen::VectorXd r_2 = rk4_integrator.integrate(2, h, init_state, default_l63);
      Eigen::VectorXd r_3 = rk4_integrator.integrate(3, h, init_state, default_l63);
      Eigen::VectorXd r_4 = rk4_integrator.integrate(4, h, init_state, default_l63);
      Eigen::VectorXd r_5 = rk4_integrator.integrate(5, h, init_state, default_l63);
      Eigen::VectorXd r_100 = rk4_integrator.integrate(100, h, init_state, default_l63);

      std::cout << "init = " << std::endl << init_state << std::endl;
      std::cout << "r_1 = " << std::endl << r_1 << std::endl; 
      std::cout << "r_2 = " << std::endl << r_2 << std::endl;
      std::cout << "r_3 = " << std::endl << r_3 << std::endl;
      std::cout << "r_4 = " << std::endl << r_4 << std::endl;
      std::cout << "r_5 = " << std::endl << r_5 << std::endl;
      std::cout << "r_100 = " << std::endl << r_100 << std::endl;


      Numint::TimeSeriesXd tsd = Numint::TimeSeriesXd(init_state, 10.0, 0.1);
      tsd.append(init_state * 1.2);
      tsd.append(init_state * 1.4);
      tsd.append(init_state * 1.6);
      tsd.print(0);
      return 0;
}
