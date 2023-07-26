#include "TimeSeries.h"
#include "eigen3/Eigen/Dense"
#include <eigen3/Eigen/src/Core/util/Constants.h>
#include <iostream>
namespace Numint
{

      TimeSeries::TimeSeries() = default;
      int TimeSeries::dim() { return 0; }
      int TimeSeries::len() { return 0; }
      double TimeSeries::width() { return 0.0; }
      Eigen::Vector2d TimeSeries::interval() { return Eigen::Vector2d::Zero(); } 
      void TimeSeries::append(const Eigen::VectorXd append_data) {}
      void TimeSeries::print(const int row) {}

      TimeSeriesXd::TimeSeriesXd() = default;
      TimeSeriesXd::TimeSeriesXd(const Eigen::VectorXd init_data, const double time, const double width)
      {
            width_ = width;
            data_ = Eigen::MatrixXd::Zero(1, init_data.size() + 1);
            data_.row(0) << time, init_data.transpose();
            interval_ = Eigen::Vector2d::Zero();
            interval_ << time, time;
      }

      int TimeSeriesXd::dim() { return data_.cols() - 1; }
      int TimeSeriesXd::len() { return data_.rows(); }
      double TimeSeriesXd::width() { return width_; }
      Eigen::Vector2d TimeSeriesXd::interval() { return interval_; }
      void TimeSeriesXd::append(const Eigen::VectorXd append_data)
      {
            assert(data_.cols() == append_data.size() + 1);
            data_.conservativeResize(data_.rows() + 1, Eigen::NoChange);
            interval_(1) += width_;
            data_.bottomRows(1) << interval_(1), append_data.transpose();
      }
      void TimeSeriesXd::print(const int row)
      {
            std::cout << "t = " << data_(row, 0) << ", dat = " << std::endl;
            std::cout << data_(row, Eigen::seq(1, Eigen::last)) << std::endl;
            std::cout << "mat = " << std::endl;
            std::cout << data_ << std::endl;
      }
}
