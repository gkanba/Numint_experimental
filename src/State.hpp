#ifndef __IG_STATE_H_
#define __IG_STATE_H_

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>

namespace Numint{

      template<int dim>
      class StateSequenceXd {
      public:
            StateSequenceXd(const Eigen::MatrixXd<dim> init_data, const double init_step_width) : m_data(init_data), m_step_width(init_step_width)
            ~StateSequenceXd(){}
      private:
            /*
             *    data : Matrix(len x dim)
             *    
             *    Contain Time Series Data in specified dimension.
             *    Initialized with (dim x 1) zero vector.
             *        
             * */ 
            Eigen::MatrixXd   m_data;
            /*
             *    time_width : Vector(2 x 1)
             *    
             *    Contain Time Width. (e.g [0.0, 1.0]^T means [time_begin, time_end]^T)
             *    Initialized with (2 x 1) zero vector 
             * */ 
            Eigen::Matrix2d   m_time_width;
            /*
             *    step_width : Scalar (double)
             *
             *    Contain Time Width between 2 adjacent Time Series Data. 
             *    Initialized with -1.0;
             *
             * */
            double            m_step_width;
      };
}

#endif 
