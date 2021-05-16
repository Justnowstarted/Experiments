# ROS Essentials

For compiling all the packages at once
```
catkin_make
```
For compiling a specific package 
```
catkin_make --pkg <package_name>
```
Both the above commands build the executable(MAKE file) into build space.

## Creating a package

Create a directory of structure workspace_name/src. While in [src] folder, execute the following through terminal to initialise the workspace with the top-level CMakeLists.txt 
```
catkin_init_workspace
```
Being the [src] folder, create a custom package with rosclient libraries with the following command
```
catkin_create_pkg <package_name> rospy roscpp std_msgs
```



## License
[MIT](https://choosealicense.com/licenses/mit/)
