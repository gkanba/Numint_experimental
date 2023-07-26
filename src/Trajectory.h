#ifndef __IG_TRAJECTORYXD_
#define __IG_TRAJECTORYXD_

#include "eigen3/Eigen/Dense"
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <utility>

namespace Numint{

class TrajectoryXd{
public:
      //
      //    constructor       : default
      //
      TrajectoryXd();
      //
      //    constructor       : copy
      //
      TrajectoryXd(const TrajectoryXd &object);
      //    
      //    constructor       : initial state point matrix (len x dim)
      //
      //    ==Note==
      //          If len = 1, this simply means initializing trajectory with a initial state point.
      //          If len = N, this means initializing trajectory with a previously calculated trajectory.
      //
      TrajectoryXd(const Eigen::MatrixXd init_traj, const std::pair<int, int> init_time_interval);      
      //
      //    return            : Eigen::MatrixXd contains m_traj[index:index, 2:dim]
      //
      //    ==Note==
      //          Returns state point in phase space of a given index.
      //          (e.g if a given index = 0, returns initial state point in phase space)
      //
      Eigen::MatrixXd point_from_index(const int index);
      //
      //    return            : Eigen::MatrixXd contains m_traj[nearest_index:nearest_index, 2:dim]. 
      //    nearest_index     : index of state points on phase space at the nearest discrete time to the given time.
      //
      //    ==Note==
      //          Returns state point in phase space of time; time is rounded to a nearest index.
      //          (e.g if a given time = 0.99 and nearest descrete time of state point = 1.00,
      //                returns state point of time 1.00 in phase space)
      //
      //
      Eigen::MatrixXd point_from_time(const double time);
      //    
      //    return            : Eigen::MatrixXd contains below. 
      //          m_traj[range.first:range.second, 2:dim] (!isTimeIncluded)
      //          m_traj[range.first:range.second, 1:dim] ( isTimeIncluded)
      //
      Eigen::MatrixXd matrix(const bool isTimeIncluded = false);

private:
      //
      //    m_dim       : state dimension
      //
      //    ==Note==
      //          State dimension does not include time column, so the trajectory vector dimesion is not same as this.
      //          See the note of m_traj for more details.
      //              
      int m_dim = 1;
      //
      //    m_len       : state step length
      //
      //    ==Note==
      //          If you want to contain a Time Series Data descretized with times (t = 0, t = 1, t = 2),
      //                m_len should return 3.
      //          Number of steps related to integration, assimilation and so on is equal to m_len - 1. 
      //
      int m_len = 1;
      //    
      //    m_time      : trajectory time interval
      //    
      //    ==Note==
      //          First element of m_time corresponds to time of first element in the trajectory sequence.
      //          Second element of m_time corresponds to time of last element in the trajectory sequence.
      //
      std::pair<double, double> m_time = {0., 1.};
      //    
      //    m_traj      : trajectory data matrix
      //
      //    ==Note==
      //          First column            contains time series sequence.
      //          1st to N-th column      contains time series state sequence of N-th variable. 
      //          First rows              contains row vector [t_0, x_1(t_0), x_2(t_0), ..., x_dim(t_0)]
      //          1st to N-th row         contains row vector [t_N-1, x_1(t_N-1), x_2(t_N-1), ..., x_dim(t_N-1)]
      //
      Eigen::MatrixXd m_traj;
};

}

#endif // !__IG_TRAJECTORYXD_
