cmake_minimum_required(VERSION 3.16)
project(pubsub_publisher_example)

# Find the installed Google Cloud Pub/Sub package
find_package(google_cloud_cpp_pubsub REQUIRED)

add_executable(pubsub_publisher
    main.cpp
    pubsub_publisher.cpp
)

target_include_directories(pubsub_publisher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(pubsub_publisher
    google-cloud-cpp::pubsub
)

