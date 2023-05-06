//
// Created by Tianyang HUANG on 06/05/2023.
//

#ifndef GPS_DATA_CONVERTER_H
#define GPS_DATA_CONVERTER_H

#include <eigen3/Eigen/Dense>
#include "gnss.pb.h"

// Convert an Eigen::Vector3d to eskf_data_flow::GpsProto_Vector3d
eskf_data_flow::GpsProto_Vector3d eigen_to_proto(const Eigen::Vector3d& vec);

// Convert an eskf_data_flow::GpsProto_Vector3d to Eigen::Vector3d
Eigen::Vector3d proto_to_eigen(const eskf_data_flow::GpsProto_Vector3d& proto_vec);

#endif // GPS_DATA_CONVERTER_H

