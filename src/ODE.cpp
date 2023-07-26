#include "ODE.h"
#include "eigen3/Eigen/Dense"

namespace Numint {
      
ODE::ODE() = default;
Eigen::VectorXd ODE::RHS(const Eigen::VectorXd value)
{
      return Eigen::VectorXd::Zero(1);
}
int ODE::dim_model()
{
      return 0;
}

ODE_L63::ODE_L63() = default;
ODE_L63::ODE_L63(const Eigen::VectorXd param)
{
      assert(param.size() == dim_param_);
      param_ = param;
}
Eigen::VectorXd ODE_L63::RHS(const Eigen::VectorXd state)
{
      assert(state.size() == dim_model_);
      Eigen::VectorXd LHS = Eigen::VectorXd::Zero(dim_model_);
      LHS(0) = param_(0) * (state(1) - state(0));
      LHS(1) = state(0) * param_(0) - state(1) - state(1) * state(2);
      LHS(2) = state(0) * state(1) - param_(2) * state(2);
      return LHS;
}
int ODE_L63::dim_model()
{
      return dim_model_;
}
}
