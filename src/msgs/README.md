# Custom Message Generation

Two files to edit while generating custom messages in ROS. (a) CMakeLists.txt and (b) Package.xml. Both reside inside a package. 

## Package.xml
This file provides information about a package's compile-time and run-time dependencies.

Uncomment the following lines in Package.xml file.

```
  <build_depend>message_generation</build_depend>
  
  <exec_depend>message_runtime</exec_depend>
```

## CMakeLists.txt

Step 1:
```
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)
```

Step 2:
```
 add_message_files(
   FILES
   custom_message_1.msg
   custom_message_2.msg
   custom_message_3.msg
 )
```

Step 3:
```
 generate_messages(
   DEPENDENCIES
   std_msgs
 )
```


Step 4:
```
catkin_package(
#  INCLUDE_DIRS include     //uncomment this if your package contains header files in include dir
#  LIBRARIES test_pkg2
   CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)
```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
