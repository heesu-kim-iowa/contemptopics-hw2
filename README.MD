# ENV
## VS 2017 (Optional)
If you have version conflict such as 
```
The build tools for v142 (Platform Toolset = 'v142') cannot be found. 
To build using the v142 build tools, please install 142 build tools.
Alternatively, you may upgrade to the current Visual Studio tools by selecting the Project menu or right-click the solution, and then selecting "Retarget solution."
```
or
```
Error (active)	E0757	overloaded function "std::chrono::duration<_Rep, _Period>::duration [with _Rep=long long, _Period=std::nano]" is not a type name	contemptopics-hw____	C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\include\chrono	195	
```
, use the [latest version of VS](https://visualstudio.microsoft.com/ko/thank-you-downloading-visual-studio/?sku=Community&rel=16) following the [guideline](https://openframeworks.cc/setup/vs/) as similar as possible. 
Then, create a new OF project, replace the `/src/`, and open the project with your VS.

# SETUP
## Eigen
  - Download **[Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)** library
  - Setup the path of **Eigen** <br />
Menu bar -> Project -> PROJECT_NAME properties... -> C/C++ -> General -> Additional Include Directories -> Edit -> Specify the path of the **Eigen** liabrary

## ofxGui
  - Setup the path of **ofxGui** <br />
Menu bar -> Project -> PROJECT_NAME properties... -> C/C++ -> General -> Additional Include Directories -> Edit -> Specify the path of the **ofxGui** liabrary(src path)

