Development environment: 
- Ubuntu 18.04 
- MacOS Ventura 13.0


======================= 分割线 ==============================

# ESKF融合IMU与GPS数据


![融合IMU数据之后的GPS轨迹效果](https://img-blog.csdnimg.cn/20210304150232490.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3UwMTEzNDE4NTY=,size_16,color_FFFFFF,t_70#pic_center)

绿色轨迹：ground truth
蓝色轨迹：fuse IMU and GPS
红色轨迹：GPS

实现方法请参考我的博客[《【附源码+代码注释】误差状态卡尔曼滤波(error-state Kalman Filter)实现GPS+IMU融合，EKF ESKF GPS+IMU》](https://blog.csdn.net/u011341856/article/details/114262451)

## 1.  依赖库

Eigen

```shell
sudo apt-get install libeigen3-dev
```

Yaml

```shell
# linux 
sudo apt-get install libyaml-cpp-dev

# mac
brew install yaml-cpp-dev

# dev libraries are those that contain the header files (*.h, *.hpp) (generally).
```

## 2. 编译

```shell
cd eskf-gps-imu-fusion
mkdir build
cd build
cmake ..
make 
```

## 3. 运行

```shell
cd eskf-gps-imu-fusion/build
./gps_imu_fusion
```

## 4.轨迹显示

执行完`./gps_imu_fusion`会生成轨迹文件

```shell
cd eskf-gps-imu-fusion/data
evo_traj kitti fused.txt gt.txt measured.txt -p
```

> 需要安装evo，可以参考我的博客中的介绍：https://blog.csdn.net/u011341856/article/details/104594392?spm=1001.2014.3001.5501
