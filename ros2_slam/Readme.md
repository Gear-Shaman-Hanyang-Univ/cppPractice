### 프로젝트 설명
C++ 프로젝트에서 라이다 데이터를 생성하고, 이를 ROS2 노드에서 퍼블리시/구독하여 처리하는 과장된 프로젝트 작성.
<br/></br>

### 디렉토리 구조
```
ros2_slam/
├── CMakeLists.txt
├── package.xml
├── include/
│   ├── lidar.hpp
│   ├── point.hpp
├── src/
│   ├── lidar.cpp
│   ├── lidar_publisher.cpp
├── slam/
│   ├── __init__.py
│   ├── slam_node.py
└── setup.py
```
(빌드를 하지 않은 상태이므로 임의로 파일 작성)

### 실행 방법
* ros2 워크스페이스에서 빌드
```bash
colcon build
```

* 터미널1 : LiDAR 퍼블리셔 실행
```bash
ros2 run ros2_slam lidar_publisher
```

* 터미널2 : SLAM 노드 실행
```bash
ros2 run ros2_slam slam_node
```