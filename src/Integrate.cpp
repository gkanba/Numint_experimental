#include "Integrate.h"
#include "ODE.h"
#include "eigen3/Eigen/Dense"
#include <iostream>

namespace Numint
{
      namespace Integrate{
            Integrator::Integrator() = default;
            Eigen::VectorXd Integrator::integrate(const int steps, const double h, const Eigen::VectorXd init_state, Numint::ODE& ode)
            {
                  return Eigen::VectorXd::Zero(1);
            }
            Euler::Euler() = default;
            Eigen::VectorXd Euler::integrate(const int steps, const double h, const Eigen::VectorXd init_state, Numint::ODE& ode)
            {
                  assert(steps > 0);
                  assert(init_state.size() == ode.dim_model());
                  Eigen::VectorXd state = init_state;
                  for(int i = 0; i < steps; i++)
                  {
                        state += h * ode.RHS(state);
                  }
                  return state;
            }
            RK4::RK4() = default;
            Eigen::VectorXd RK4::integrate(const int steps, const double h, const Eigen::VectorXd init_state, Numint::ODE& ode)
            {
                  assert(steps > 0);
                  assert(init_state.size() == ode.dim_model());
                  Eigen::VectorXd state = init_state;
                  for(int i = 0; i < steps; i++)
                  {
                        Eigen::VectorXd k_a = h * ode.RHS(state);
                        Eigen::VectorXd k_b = h * ode.RHS(state + 0.5 * k_a);
                        Eigen::VectorXd k_c = h * ode.RHS(state + 0.5 * k_b);
                        Eigen::VectorXd k_d = h * ode.RHS(state + k_c);
                        state += (1.0 / 6.0) * (k_a + 2 * k_b + 2 * k_c + k_d);
                  }
                  return state;
            }
      }
}
