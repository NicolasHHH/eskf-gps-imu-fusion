//
// Created by meng on 2021/2/26.
// Corrected by hty on 2023/5/3
//

#ifndef GPS_IMU_FUSION_TOOL_H
#define GPS_IMU_FUSION_TOOL_H

#include <eigen3/Eigen/Dense>

inline void TransformCoordinate(Eigen::Vector3d& vec){
    double kDegree2Radian = M_PI / 180.0;

    // the rotations are applied on the old axis
    Eigen::Quaterniond Q_ned_enu = Eigen::AngleAxisd(90 * kDegree2Radian, Eigen::Vector3d::UnitZ()) *
                               Eigen::AngleAxisd(0 * kDegree2Radian, Eigen::Vector3d::UnitY()) *
                               Eigen::AngleAxisd(180 * kDegree2Radian, Eigen::Vector3d::UnitX());

    vec = Q_ned_enu * vec; // different with the issue
}
#endif //GPS_IMU_FUSION_TOOL_H
