#ifndef _IG_INTEGRATE_H_
#define _IG_INTEGRATE_H_

#include "ODE.h"
#include "eigen3/Eigen/Dense"

namespace Numint
{
      namespace Integrate
      {
            class Integrator
            {
                  public:
                        Integrator();
                        virtual Eigen::VectorXd integrate(const int steps, const double h, const Eigen::VectorXd init_state, Numint::ODE& ode);
            };

            class Euler : public Integrator
            {
                  public:
                        Euler();
                        Eigen::VectorXd integrate(const int steps, const double h, const Eigen::VectorXd init_state, Numint::ODE& ode);
            };

            class RK4 : public Integrator
            {
                  public:
                        RK4();
                        Eigen::VectorXd integrate(const int steps, const double h, const Eigen::VectorXd init_state, Numint::ODE& ode);
            };
      }
}

#endif // !_IG_INTEGRATE_H_
