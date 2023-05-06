//
// Created by Tianyang HUANG on 06/05/2023.
//

#include "test_gnss_pb.h"

#include <iostream>
#include <eigen3/Eigen/Dense>
#include <google/protobuf/stubs/common.h>
#include "gnss.pb.h"

eskf_data_flow::GpsProto_Vector3d eigen_to_proto(const Eigen::Vector3d& vec) {
    eskf_data_flow::GpsProto_Vector3d proto_vec;
    proto_vec.set_x(vec.x());
    proto_vec.set_y(vec.y());
    proto_vec.set_z(vec.z());
    return proto_vec;
}

Eigen::Vector3d proto_to_eigen(const eskf_data_flow::GpsProto_Vector3d& proto_vec) {
    return Eigen::Vector3d(proto_vec.x(), proto_vec.y(), proto_vec.z());
}

int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Encode GpsProto
    eskf_data_flow::GpsProto gps_data;

    Eigen::Vector3d position_lla(1, 2, 3);
    Eigen::Vector3d velocity(4, 5, 6);
    Eigen::Vector3d position(7, 8, 9);
    Eigen::Vector3d true_velocity(10, 11, 12);
    Eigen::Vector3d true_position_lla(13, 14, 15);
    double time = 42;

    gps_data.mutable_position_lla()->CopyFrom(eigen_to_proto(position_lla));
    gps_data.mutable_velocity()->CopyFrom(eigen_to_proto(velocity));
    gps_data.mutable_position()->CopyFrom(eigen_to_proto(position));
    gps_data.mutable_true_velocity()->CopyFrom(eigen_to_proto(true_velocity));
    gps_data.mutable_true_position_lla()->CopyFrom(eigen_to_proto(true_position_lla));
    gps_data.set_time(time);

    std::string serialized_data;
    gps_data.SerializeToString(&serialized_data);

    // Decode GpsProto
    eskf_data_flow::GpsProto decoded_data;
    decoded_data.ParseFromString(serialized_data);

    Eigen::Vector3d decoded_position_lla = proto_to_eigen(decoded_data.position_lla());
    Eigen::Vector3d decoded_velocity = proto_to_eigen(decoded_data.velocity());
    Eigen::Vector3d decoded_position = proto_to_eigen(decoded_data.position());
    Eigen::Vector3d decoded_true_velocity = proto_to_eigen(decoded_data.true_velocity());
    Eigen::Vector3d decoded_true_position_lla = proto_to_eigen(decoded_data.true_position_lla());
    double decoded_time = decoded_data.time();

    std::cout << "Decoded Position LLA: " << decoded_position_lla.transpose() << std::endl;
    std::cout << "Decoded Velocity: " << decoded_velocity.transpose() << std::endl;
    std::cout << "Decoded Position: " << decoded_position.transpose() << std::endl;
    std::cout << "Decoded True Velocity: " << decoded_true_velocity.transpose() << std::endl;
    std::cout << "Decoded True Position LLA: " << decoded_true_position_lla.transpose() << std::endl;
    std::cout << "Decoded Time: " << decoded_time << std::endl;

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}

