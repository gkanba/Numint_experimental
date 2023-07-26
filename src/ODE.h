#ifndef __IG_ODE_H_
#define __IG_ODE_H_

#include "eigen3/Eigen/Dense"

namespace Numint
{

class ODE
{
      public:
            ODE();
            virtual Eigen::VectorXd RHS(const Eigen::VectorXd value);
            virtual int dim_model();
};

class ODE_L63 : public ODE 
{
      private:
            //
            //    ODE Parameter : [sigma, rho, beta]
            //
            Eigen::VectorXd param_;
      public: 
            static const int dim_model_ = 3; 
            static const int dim_param_ = 3;

            ODE_L63();
            ODE_L63(const Eigen::VectorXd param);
            Eigen::VectorXd RHS(const Eigen::VectorXd state);
            int dim_model();      
};

}

#endif // !__IG_ODE_H_
