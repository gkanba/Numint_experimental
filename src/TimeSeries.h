#ifndef __IG_TIMESERIES_H_
#define __IG_TIMESERIES_H_

#include "eigen3/Eigen/Dense"
#include <vector>

namespace Numint{
            enum TimeSeriesFormat
            {
                  ONLY_TIME,
                  ONLY_DATA,
                  TIME_DATA,
                  TIME_DATA_TAG,
            };

            class TimeSeries{
                  public:
                        TimeSeries();
                        virtual int len();
                        virtual int dim();
                        virtual double width();
                        virtual Eigen::Vector2d interval();
                        virtual void append(const Eigen::VectorXd append_data);
                        //virtual int save(const std::string filename, const TimeSeriesFormat format);
                        virtual void print(const int row);
            };

            class TimeSeriesXd : public TimeSeries
            {
                  private:
                        double width_ = 0;
                        Eigen::Vector2d interval_;            
                        Eigen::MatrixXd data_;
                        std::vector<std::string> tag_;
                  public:
                        TimeSeriesXd();
                        TimeSeriesXd(const Eigen::VectorXd init_data, const double time, const double width);
                        //TimeSeriesXd(const Eigen::MatrixXd init_data, const Eigen::Vector2d interval);
                        int len();
                        int dim();
                        double width();
                        Eigen::Vector2d interval();
                        void append(const Eigen::VectorXd append_data);
                        //int save(const std::string filename, const TimeSeriesFormat format);
                        void print(const int row);
            };
}

#endif // !__IG_TIMESERIES_H_
