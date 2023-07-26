#include "Trajectory.h"
#include "eigen3/Eigen/Dense"
#include <eigen3/Eigen/src/Core/ArithmeticSequence.h>
#include <eigen3/Eigen/src/Core/util/IndexedViewHelper.h>

namespace Numint{

TrajectoryXd::TrajectoryXd() {}

TrajectoryXd::TrajectoryXd(const Eigen::MatrixXd init_traj){
      m_dim = init_traj.cols();
      m_len = init_traj.rows();
      m_traj = init_traj;
}

Eigen::MatrixXd TrajectoryXd::matrix(const bool isTimeIncluded){
      if(isTimeIncluded){
            // Return itself
            return m_traj;
      }
      else{
            // Return manipulated
            return m_traj(Eigen::all, Eigen::seq(1, Eigen::last));
      }
}

}
